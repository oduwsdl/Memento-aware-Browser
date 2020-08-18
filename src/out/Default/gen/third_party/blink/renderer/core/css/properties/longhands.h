// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/css/properties/templates/css_properties.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/properties/css_property_methods.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5



#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTIES_CSS_PROPERTIES_LONGHANDS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTIES_CSS_PROPERTIES_LONGHANDS_H_

#include "third_party/blink/renderer/core/css/properties/longhand.h"

namespace blink {

class ComputedStyle;
class CSSParserContext;
class CSSParserLocalContext;
class CSSValue;
class LayoutObject;
class Node;
class SVGComputedStyle;

namespace css_longhand {

// animation-delay
class AnimationDelay final : public Longhand {
 public:
  constexpr AnimationDelay() : Longhand(CSSPropertyID::kAnimationDelay, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-direction
class AnimationDirection final : public Longhand {
 public:
  constexpr AnimationDirection() : Longhand(CSSPropertyID::kAnimationDirection, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-duration
class AnimationDuration final : public Longhand {
 public:
  constexpr AnimationDuration() : Longhand(CSSPropertyID::kAnimationDuration, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-fill-mode
class AnimationFillMode final : public Longhand {
 public:
  constexpr AnimationFillMode() : Longhand(CSSPropertyID::kAnimationFillMode, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-iteration-count
class AnimationIterationCount final : public Longhand {
 public:
  constexpr AnimationIterationCount() : Longhand(CSSPropertyID::kAnimationIterationCount, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-name
class AnimationName final : public Longhand {
 public:
  constexpr AnimationName() : Longhand(CSSPropertyID::kAnimationName, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-play-state
class AnimationPlayState final : public Longhand {
 public:
  constexpr AnimationPlayState() : Longhand(CSSPropertyID::kAnimationPlayState, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-timeline
class AnimationTimeline final : public Longhand {
 public:
  constexpr AnimationTimeline() : Longhand(CSSPropertyID::kAnimationTimeline, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// animation-timing-function
class AnimationTimingFunction final : public Longhand {
 public:
  constexpr AnimationTimingFunction() : Longhand(CSSPropertyID::kAnimationTimingFunction, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transition-delay
class TransitionDelay final : public Longhand {
 public:
  constexpr TransitionDelay() : Longhand(CSSPropertyID::kTransitionDelay, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transition-duration
class TransitionDuration final : public Longhand {
 public:
  constexpr TransitionDuration() : Longhand(CSSPropertyID::kTransitionDuration, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transition-property
class TransitionProperty final : public Longhand {
 public:
  constexpr TransitionProperty() : Longhand(CSSPropertyID::kTransitionProperty, kProperty | kAnimation | kValidForMarker, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transition-timing-function
class TransitionTimingFunction final : public Longhand {
 public:
  constexpr TransitionTimingFunction() : Longhand(CSSPropertyID::kTransitionTimingFunction, kProperty | kAnimation | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// color
class Color final : public Longhand {
 public:
  constexpr Color() : Longhand(CSSPropertyID::kColor, kInterpolable | kProperty | kInherited | kIsAffectedByForcedColors | kValidForFirstLetter | kValidForCue | kValidForMarker, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// color-scheme
class ColorScheme final : public Longhand {
 public:
  constexpr ColorScheme() : Longhand(CSSPropertyID::kColorScheme, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// direction
class Direction final : public Longhand {
 public:
  constexpr Direction() : Longhand(CSSPropertyID::kDirection, kProperty | kInherited | kValidForMarker | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsAffectedByAll() const override { return false; }
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-family
class FontFamily final : public Longhand {
 public:
  constexpr FontFamily() : Longhand(CSSPropertyID::kFontFamily, kDescriptor | kProperty | kInherited | kValidForFirstLetter | kValidForCue | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-feature-settings
class FontFeatureSettings final : public Longhand {
 public:
  constexpr FontFeatureSettings() : Longhand(CSSPropertyID::kFontFeatureSettings, kDescriptor | kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-kerning
class FontKerning final : public Longhand {
 public:
  constexpr FontKerning() : Longhand(CSSPropertyID::kFontKerning, kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-optical-sizing
class FontOpticalSizing final : public Longhand {
 public:
  constexpr FontOpticalSizing() : Longhand(CSSPropertyID::kFontOpticalSizing, kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-size
class FontSize final : public Longhand {
 public:
  constexpr FontSize() : Longhand(CSSPropertyID::kFontSize, kInterpolable | kProperty | kInherited | kValidForFirstLetter | kValidForCue | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-size-adjust
class FontSizeAdjust final : public Longhand {
 public:
  constexpr FontSizeAdjust() : Longhand(CSSPropertyID::kFontSizeAdjust, kInterpolable | kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-stretch
class FontStretch final : public Longhand {
 public:
  constexpr FontStretch() : Longhand(CSSPropertyID::kFontStretch, kInterpolable | kDescriptor | kProperty | kInherited | kValidForFirstLetter | kValidForCue | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-style
class FontStyle final : public Longhand {
 public:
  constexpr FontStyle() : Longhand(CSSPropertyID::kFontStyle, kDescriptor | kProperty | kInherited | kValidForFirstLetter | kValidForCue | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-variant-caps
class FontVariantCaps final : public Longhand {
 public:
  constexpr FontVariantCaps() : Longhand(CSSPropertyID::kFontVariantCaps, kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-variant-east-asian
class FontVariantEastAsian final : public Longhand {
 public:
  constexpr FontVariantEastAsian() : Longhand(CSSPropertyID::kFontVariantEastAsian, kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-variant-ligatures
class FontVariantLigatures final : public Longhand {
 public:
  constexpr FontVariantLigatures() : Longhand(CSSPropertyID::kFontVariantLigatures, kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-variant-numeric
class FontVariantNumeric final : public Longhand {
 public:
  constexpr FontVariantNumeric() : Longhand(CSSPropertyID::kFontVariantNumeric, kProperty | kInherited | kValidForFirstLetter | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-variation-settings
class FontVariationSettings final : public Longhand {
 public:
  constexpr FontVariationSettings() : Longhand(CSSPropertyID::kFontVariationSettings, kInterpolable | kProperty | kInherited | kValidForFirstLetter | kValidForCue | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-weight
class FontWeight final : public Longhand {
 public:
  constexpr FontWeight() : Longhand(CSSPropertyID::kFontWeight, kInterpolable | kDescriptor | kProperty | kInherited | kValidForFirstLetter | kValidForCue | kValidForMarker | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// forced-color-adjust
class ForcedColorAdjust final : public Longhand {
 public:
  constexpr ForcedColorAdjust() : Longhand(CSSPropertyID::kForcedColorAdjust, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-color
class InternalVisitedColor final : public Longhand {
 public:
  constexpr InternalVisitedColor() : Longhand(CSSPropertyID::kInternalVisitedColor, kProperty | kInherited | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter | kValidForCue | kValidForMarker, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-orientation
class TextOrientation final : public Longhand {
 public:
  constexpr TextOrientation() : Longhand(CSSPropertyID::kTextOrientation, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-rendering
class TextRendering final : public Longhand {
 public:
  constexpr TextRendering() : Longhand(CSSPropertyID::kTextRendering, kProperty | kInherited | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-font-smoothing
class WebkitFontSmoothing final : public Longhand {
 public:
  constexpr WebkitFontSmoothing() : Longhand(CSSPropertyID::kWebkitFontSmoothing, kProperty | kInherited | kValidForFirstLetter | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-locale
class WebkitLocale final : public Longhand {
 public:
  constexpr WebkitLocale() : Longhand(CSSPropertyID::kWebkitLocale, kProperty | kInherited | kAffectsFont, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-orientation
class WebkitTextOrientation final : public Longhand {
 public:
  constexpr WebkitTextOrientation() : Longhand(CSSPropertyID::kWebkitTextOrientation, kProperty | kInherited | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-writing-mode
class WebkitWritingMode final : public Longhand {
 public:
  constexpr WebkitWritingMode() : Longhand(CSSPropertyID::kWebkitWritingMode, kProperty | kInherited | kSurrogate | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// writing-mode
class WritingMode final : public Longhand {
 public:
  constexpr WritingMode() : Longhand(CSSPropertyID::kWritingMode, kProperty | kInherited | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// zoom
class Zoom final : public Longhand {
 public:
  constexpr Zoom() : Longhand(CSSPropertyID::kZoom, kDescriptor | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// align-content
class AlignContent final : public Longhand {
 public:
  constexpr AlignContent() : Longhand(CSSPropertyID::kAlignContent, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// align-items
class AlignItems final : public Longhand {
 public:
  constexpr AlignItems() : Longhand(CSSPropertyID::kAlignItems, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// align-self
class AlignSelf final : public Longhand {
 public:
  constexpr AlignSelf() : Longhand(CSSPropertyID::kAlignSelf, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// alignment-baseline
class AlignmentBaseline final : public Longhand {
 public:
  constexpr AlignmentBaseline() : Longhand(CSSPropertyID::kAlignmentBaseline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// all
class All final : public Longhand {
 public:
  constexpr All() : Longhand(CSSPropertyID::kAll, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsAffectedByAll() const override { return false; }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// appearance
class Appearance final : public Longhand {
 public:
  constexpr Appearance() : Longhand(CSSPropertyID::kAppearance, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// aspect-ratio
class AspectRatio final : public Longhand {
 public:
  constexpr AspectRatio() : Longhand(CSSPropertyID::kAspectRatio, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// backdrop-filter
class BackdropFilter final : public Longhand {
 public:
  constexpr BackdropFilter() : Longhand(CSSPropertyID::kBackdropFilter, kInterpolable | kCompositableProperty | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// backface-visibility
class BackfaceVisibility final : public Longhand {
 public:
  constexpr BackfaceVisibility() : Longhand(CSSPropertyID::kBackfaceVisibility, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-attachment
class BackgroundAttachment final : public Longhand {
 public:
  constexpr BackgroundAttachment() : Longhand(CSSPropertyID::kBackgroundAttachment, kProperty | kValidForFirstLetter | kValidForCue | kBackground, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-blend-mode
class BackgroundBlendMode final : public Longhand {
 public:
  constexpr BackgroundBlendMode() : Longhand(CSSPropertyID::kBackgroundBlendMode, kProperty | kValidForFirstLetter | kBackground, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-clip
class BackgroundClip final : public Longhand {
 public:
  constexpr BackgroundClip() : Longhand(CSSPropertyID::kBackgroundClip, kProperty | kValidForFirstLetter | kValidForCue | kBackground, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-color
class BackgroundColor final : public Longhand {
 public:
  constexpr BackgroundColor() : Longhand(CSSPropertyID::kBackgroundColor, kInterpolable | kProperty | kValidForFirstLetter | kValidForCue | kBackground, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-image
class BackgroundImage final : public Longhand {
 public:
  constexpr BackgroundImage() : Longhand(CSSPropertyID::kBackgroundImage, kInterpolable | kProperty | kValidForFirstLetter | kValidForCue | kBackground, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-origin
class BackgroundOrigin final : public Longhand {
 public:
  constexpr BackgroundOrigin() : Longhand(CSSPropertyID::kBackgroundOrigin, kProperty | kValidForFirstLetter | kValidForCue | kBackground, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-position-x
class BackgroundPositionX final : public Longhand {
 public:
  constexpr BackgroundPositionX() : Longhand(CSSPropertyID::kBackgroundPositionX, kInterpolable | kProperty | kValidForFirstLetter | kValidForCue | kBackground, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-position-y
class BackgroundPositionY final : public Longhand {
 public:
  constexpr BackgroundPositionY() : Longhand(CSSPropertyID::kBackgroundPositionY, kInterpolable | kProperty | kValidForFirstLetter | kValidForCue | kBackground, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-repeat-x
class BackgroundRepeatX final : public Longhand {
 public:
  constexpr BackgroundRepeatX() : Longhand(CSSPropertyID::kBackgroundRepeatX, kProperty | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-repeat-y
class BackgroundRepeatY final : public Longhand {
 public:
  constexpr BackgroundRepeatY() : Longhand(CSSPropertyID::kBackgroundRepeatY, kProperty | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// background-size
class BackgroundSize final : public Longhand {
 public:
  constexpr BackgroundSize() : Longhand(CSSPropertyID::kBackgroundSize, kInterpolable | kProperty | kValidForFirstLetter | kValidForCue | kBackground, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// baseline-shift
class BaselineShift final : public Longhand {
 public:
  constexpr BaselineShift() : Longhand(CSSPropertyID::kBaselineShift, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// block-size
class BlockSize final : public Longhand {
 public:
  constexpr BlockSize() : Longhand(CSSPropertyID::kBlockSize, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-block-end-color
class BorderBlockEndColor final : public Longhand {
 public:
  constexpr BorderBlockEndColor() : Longhand(CSSPropertyID::kBorderBlockEndColor, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-block-end-style
class BorderBlockEndStyle final : public Longhand {
 public:
  constexpr BorderBlockEndStyle() : Longhand(CSSPropertyID::kBorderBlockEndStyle, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-block-end-width
class BorderBlockEndWidth final : public Longhand {
 public:
  constexpr BorderBlockEndWidth() : Longhand(CSSPropertyID::kBorderBlockEndWidth, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-block-start-color
class BorderBlockStartColor final : public Longhand {
 public:
  constexpr BorderBlockStartColor() : Longhand(CSSPropertyID::kBorderBlockStartColor, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-block-start-style
class BorderBlockStartStyle final : public Longhand {
 public:
  constexpr BorderBlockStartStyle() : Longhand(CSSPropertyID::kBorderBlockStartStyle, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-block-start-width
class BorderBlockStartWidth final : public Longhand {
 public:
  constexpr BorderBlockStartWidth() : Longhand(CSSPropertyID::kBorderBlockStartWidth, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-bottom-color
class BorderBottomColor final : public Longhand {
 public:
  constexpr BorderBottomColor() : Longhand(CSSPropertyID::kBorderBottomColor, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-bottom-left-radius
class BorderBottomLeftRadius final : public Longhand {
 public:
  constexpr BorderBottomLeftRadius() : Longhand(CSSPropertyID::kBorderBottomLeftRadius, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-bottom-right-radius
class BorderBottomRightRadius final : public Longhand {
 public:
  constexpr BorderBottomRightRadius() : Longhand(CSSPropertyID::kBorderBottomRightRadius, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-bottom-style
class BorderBottomStyle final : public Longhand {
 public:
  constexpr BorderBottomStyle() : Longhand(CSSPropertyID::kBorderBottomStyle, kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-bottom-width
class BorderBottomWidth final : public Longhand {
 public:
  constexpr BorderBottomWidth() : Longhand(CSSPropertyID::kBorderBottomWidth, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-collapse
class BorderCollapse final : public Longhand {
 public:
  constexpr BorderCollapse() : Longhand(CSSPropertyID::kBorderCollapse, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-image-outset
class BorderImageOutset final : public Longhand {
 public:
  constexpr BorderImageOutset() : Longhand(CSSPropertyID::kBorderImageOutset, kInterpolable | kProperty | kValidForFirstLetter | kBorder, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-image-repeat
class BorderImageRepeat final : public Longhand {
 public:
  constexpr BorderImageRepeat() : Longhand(CSSPropertyID::kBorderImageRepeat, kProperty | kValidForFirstLetter | kBorder, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-image-slice
class BorderImageSlice final : public Longhand {
 public:
  constexpr BorderImageSlice() : Longhand(CSSPropertyID::kBorderImageSlice, kInterpolable | kProperty | kValidForFirstLetter | kBorder, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-image-source
class BorderImageSource final : public Longhand {
 public:
  constexpr BorderImageSource() : Longhand(CSSPropertyID::kBorderImageSource, kInterpolable | kProperty | kValidForFirstLetter | kBorder, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-image-width
class BorderImageWidth final : public Longhand {
 public:
  constexpr BorderImageWidth() : Longhand(CSSPropertyID::kBorderImageWidth, kInterpolable | kProperty | kValidForFirstLetter | kBorder, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const CSSValue* InitialValue() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-inline-end-color
class BorderInlineEndColor final : public Longhand {
 public:
  constexpr BorderInlineEndColor() : Longhand(CSSPropertyID::kBorderInlineEndColor, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-inline-end-style
class BorderInlineEndStyle final : public Longhand {
 public:
  constexpr BorderInlineEndStyle() : Longhand(CSSPropertyID::kBorderInlineEndStyle, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-inline-end-width
class BorderInlineEndWidth final : public Longhand {
 public:
  constexpr BorderInlineEndWidth() : Longhand(CSSPropertyID::kBorderInlineEndWidth, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-inline-start-color
class BorderInlineStartColor final : public Longhand {
 public:
  constexpr BorderInlineStartColor() : Longhand(CSSPropertyID::kBorderInlineStartColor, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-inline-start-style
class BorderInlineStartStyle final : public Longhand {
 public:
  constexpr BorderInlineStartStyle() : Longhand(CSSPropertyID::kBorderInlineStartStyle, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-inline-start-width
class BorderInlineStartWidth final : public Longhand {
 public:
  constexpr BorderInlineStartWidth() : Longhand(CSSPropertyID::kBorderInlineStartWidth, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-left-color
class BorderLeftColor final : public Longhand {
 public:
  constexpr BorderLeftColor() : Longhand(CSSPropertyID::kBorderLeftColor, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-left-style
class BorderLeftStyle final : public Longhand {
 public:
  constexpr BorderLeftStyle() : Longhand(CSSPropertyID::kBorderLeftStyle, kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-left-width
class BorderLeftWidth final : public Longhand {
 public:
  constexpr BorderLeftWidth() : Longhand(CSSPropertyID::kBorderLeftWidth, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-right-color
class BorderRightColor final : public Longhand {
 public:
  constexpr BorderRightColor() : Longhand(CSSPropertyID::kBorderRightColor, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-right-style
class BorderRightStyle final : public Longhand {
 public:
  constexpr BorderRightStyle() : Longhand(CSSPropertyID::kBorderRightStyle, kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-right-width
class BorderRightWidth final : public Longhand {
 public:
  constexpr BorderRightWidth() : Longhand(CSSPropertyID::kBorderRightWidth, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-top-color
class BorderTopColor final : public Longhand {
 public:
  constexpr BorderTopColor() : Longhand(CSSPropertyID::kBorderTopColor, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-top-left-radius
class BorderTopLeftRadius final : public Longhand {
 public:
  constexpr BorderTopLeftRadius() : Longhand(CSSPropertyID::kBorderTopLeftRadius, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-top-right-radius
class BorderTopRightRadius final : public Longhand {
 public:
  constexpr BorderTopRightRadius() : Longhand(CSSPropertyID::kBorderTopRightRadius, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-top-style
class BorderTopStyle final : public Longhand {
 public:
  constexpr BorderTopStyle() : Longhand(CSSPropertyID::kBorderTopStyle, kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// border-top-width
class BorderTopWidth final : public Longhand {
 public:
  constexpr BorderTopWidth() : Longhand(CSSPropertyID::kBorderTopWidth, kInterpolable | kProperty | kValidForFirstLetter | kBorder | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// bottom
class Bottom final : public Longhand {
 public:
  constexpr Bottom() : Longhand(CSSPropertyID::kBottom, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// box-shadow
class BoxShadow final : public Longhand {
 public:
  constexpr BoxShadow() : Longhand(CSSPropertyID::kBoxShadow, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// box-sizing
class BoxSizing final : public Longhand {
 public:
  constexpr BoxSizing() : Longhand(CSSPropertyID::kBoxSizing, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// break-after
class BreakAfter final : public Longhand {
 public:
  constexpr BreakAfter() : Longhand(CSSPropertyID::kBreakAfter, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// break-before
class BreakBefore final : public Longhand {
 public:
  constexpr BreakBefore() : Longhand(CSSPropertyID::kBreakBefore, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// break-inside
class BreakInside final : public Longhand {
 public:
  constexpr BreakInside() : Longhand(CSSPropertyID::kBreakInside, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// buffered-rendering
class BufferedRendering final : public Longhand {
 public:
  constexpr BufferedRendering() : Longhand(CSSPropertyID::kBufferedRendering, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// caption-side
class CaptionSide final : public Longhand {
 public:
  constexpr CaptionSide() : Longhand(CSSPropertyID::kCaptionSide, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// caret-color
class CaretColor final : public Longhand {
 public:
  constexpr CaretColor() : Longhand(CSSPropertyID::kCaretColor, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// clear
class Clear final : public Longhand {
 public:
  constexpr Clear() : Longhand(CSSPropertyID::kClear, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// clip
class Clip final : public Longhand {
 public:
  constexpr Clip() : Longhand(CSSPropertyID::kClip, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// clip-path
class ClipPath final : public Longhand {
 public:
  constexpr ClipPath() : Longhand(CSSPropertyID::kClipPath, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// clip-rule
class ClipRule final : public Longhand {
 public:
  constexpr ClipRule() : Longhand(CSSPropertyID::kClipRule, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// color-interpolation
class ColorInterpolation final : public Longhand {
 public:
  constexpr ColorInterpolation() : Longhand(CSSPropertyID::kColorInterpolation, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// color-interpolation-filters
class ColorInterpolationFilters final : public Longhand {
 public:
  constexpr ColorInterpolationFilters() : Longhand(CSSPropertyID::kColorInterpolationFilters, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// color-rendering
class ColorRendering final : public Longhand {
 public:
  constexpr ColorRendering() : Longhand(CSSPropertyID::kColorRendering, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-count
class ColumnCount final : public Longhand {
 public:
  constexpr ColumnCount() : Longhand(CSSPropertyID::kColumnCount, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-fill
class ColumnFill final : public Longhand {
 public:
  constexpr ColumnFill() : Longhand(CSSPropertyID::kColumnFill, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-gap
class ColumnGap final : public Longhand {
 public:
  constexpr ColumnGap() : Longhand(CSSPropertyID::kColumnGap, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-rule-color
class ColumnRuleColor final : public Longhand {
 public:
  constexpr ColumnRuleColor() : Longhand(CSSPropertyID::kColumnRuleColor, kInterpolable | kProperty | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-rule-style
class ColumnRuleStyle final : public Longhand {
 public:
  constexpr ColumnRuleStyle() : Longhand(CSSPropertyID::kColumnRuleStyle, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-rule-width
class ColumnRuleWidth final : public Longhand {
 public:
  constexpr ColumnRuleWidth() : Longhand(CSSPropertyID::kColumnRuleWidth, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-span
class ColumnSpan final : public Longhand {
 public:
  constexpr ColumnSpan() : Longhand(CSSPropertyID::kColumnSpan, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// column-width
class ColumnWidth final : public Longhand {
 public:
  constexpr ColumnWidth() : Longhand(CSSPropertyID::kColumnWidth, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// contain
class Contain final : public Longhand {
 public:
  constexpr Contain() : Longhand(CSSPropertyID::kContain, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// contain-intrinsic-size
class ContainIntrinsicSize final : public Longhand {
 public:
  constexpr ContainIntrinsicSize() : Longhand(CSSPropertyID::kContainIntrinsicSize, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// content
class Content final : public Longhand {
 public:
  constexpr Content() : Longhand(CSSPropertyID::kContent, kProperty | kValidForMarker, ',') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// content-visibility
class ContentVisibility final : public Longhand {
 public:
  constexpr ContentVisibility() : Longhand(CSSPropertyID::kContentVisibility, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// counter-increment
class CounterIncrement final : public Longhand {
 public:
  constexpr CounterIncrement() : Longhand(CSSPropertyID::kCounterIncrement, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// counter-reset
class CounterReset final : public Longhand {
 public:
  constexpr CounterReset() : Longhand(CSSPropertyID::kCounterReset, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// counter-set
class CounterSet final : public Longhand {
 public:
  constexpr CounterSet() : Longhand(CSSPropertyID::kCounterSet, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// cursor
class Cursor final : public Longhand {
 public:
  constexpr Cursor() : Longhand(CSSPropertyID::kCursor, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// cx
class Cx final : public Longhand {
 public:
  constexpr Cx() : Longhand(CSSPropertyID::kCx, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// cy
class Cy final : public Longhand {
 public:
  constexpr Cy() : Longhand(CSSPropertyID::kCy, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// d
class D final : public Longhand {
 public:
  constexpr D() : Longhand(CSSPropertyID::kD, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// display
class Display final : public Longhand {
 public:
  constexpr Display() : Longhand(CSSPropertyID::kDisplay, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// dominant-baseline
class DominantBaseline final : public Longhand {
 public:
  constexpr DominantBaseline() : Longhand(CSSPropertyID::kDominantBaseline, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// empty-cells
class EmptyCells final : public Longhand {
 public:
  constexpr EmptyCells() : Longhand(CSSPropertyID::kEmptyCells, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// end
class End final : public Longhand {
 public:
  constexpr End() : Longhand(CSSPropertyID::kEnd, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// fill
class Fill final : public Longhand {
 public:
  constexpr Fill() : Longhand(CSSPropertyID::kFill, kInterpolable | kProperty | kInherited | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// fill-opacity
class FillOpacity final : public Longhand {
 public:
  constexpr FillOpacity() : Longhand(CSSPropertyID::kFillOpacity, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// fill-rule
class FillRule final : public Longhand {
 public:
  constexpr FillRule() : Longhand(CSSPropertyID::kFillRule, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// filter
class Filter final : public Longhand {
 public:
  constexpr Filter() : Longhand(CSSPropertyID::kFilter, kInterpolable | kCompositableProperty | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flex-basis
class FlexBasis final : public Longhand {
 public:
  constexpr FlexBasis() : Longhand(CSSPropertyID::kFlexBasis, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flex-direction
class FlexDirection final : public Longhand {
 public:
  constexpr FlexDirection() : Longhand(CSSPropertyID::kFlexDirection, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flex-grow
class FlexGrow final : public Longhand {
 public:
  constexpr FlexGrow() : Longhand(CSSPropertyID::kFlexGrow, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flex-shrink
class FlexShrink final : public Longhand {
 public:
  constexpr FlexShrink() : Longhand(CSSPropertyID::kFlexShrink, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flex-wrap
class FlexWrap final : public Longhand {
 public:
  constexpr FlexWrap() : Longhand(CSSPropertyID::kFlexWrap, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// float
class Float final : public Longhand {
 public:
  constexpr Float() : Longhand(CSSPropertyID::kFloat, kProperty | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flood-color
class FloodColor final : public Longhand {
 public:
  constexpr FloodColor() : Longhand(CSSPropertyID::kFloodColor, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// flood-opacity
class FloodOpacity final : public Longhand {
 public:
  constexpr FloodOpacity() : Longhand(CSSPropertyID::kFloodOpacity, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// font-display
class FontDisplay final : public Longhand {
 public:
  constexpr FontDisplay() : Longhand(CSSPropertyID::kFontDisplay, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// grid-auto-columns
class GridAutoColumns final : public Longhand {
 public:
  constexpr GridAutoColumns() : Longhand(CSSPropertyID::kGridAutoColumns, kProperty, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-auto-flow
class GridAutoFlow final : public Longhand {
 public:
  constexpr GridAutoFlow() : Longhand(CSSPropertyID::kGridAutoFlow, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-auto-rows
class GridAutoRows final : public Longhand {
 public:
  constexpr GridAutoRows() : Longhand(CSSPropertyID::kGridAutoRows, kProperty, ' ') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-column-end
class GridColumnEnd final : public Longhand {
 public:
  constexpr GridColumnEnd() : Longhand(CSSPropertyID::kGridColumnEnd, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-column-start
class GridColumnStart final : public Longhand {
 public:
  constexpr GridColumnStart() : Longhand(CSSPropertyID::kGridColumnStart, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-row-end
class GridRowEnd final : public Longhand {
 public:
  constexpr GridRowEnd() : Longhand(CSSPropertyID::kGridRowEnd, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-row-start
class GridRowStart final : public Longhand {
 public:
  constexpr GridRowStart() : Longhand(CSSPropertyID::kGridRowStart, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-template-areas
class GridTemplateAreas final : public Longhand {
 public:
  constexpr GridTemplateAreas() : Longhand(CSSPropertyID::kGridTemplateAreas, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-template-columns
class GridTemplateColumns final : public Longhand {
 public:
  constexpr GridTemplateColumns() : Longhand(CSSPropertyID::kGridTemplateColumns, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// grid-template-rows
class GridTemplateRows final : public Longhand {
 public:
  constexpr GridTemplateRows() : Longhand(CSSPropertyID::kGridTemplateRows, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// height
class Height final : public Longhand {
 public:
  constexpr Height() : Longhand(CSSPropertyID::kHeight, kInterpolable | kDescriptor | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// hyphens
class Hyphens final : public Longhand {
 public:
  constexpr Hyphens() : Longhand(CSSPropertyID::kHyphens, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// image-orientation
class ImageOrientation final : public Longhand {
 public:
  constexpr ImageOrientation() : Longhand(CSSPropertyID::kImageOrientation, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// image-rendering
class ImageRendering final : public Longhand {
 public:
  constexpr ImageRendering() : Longhand(CSSPropertyID::kImageRendering, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// inherits
class Inherits final : public Longhand {
 public:
  constexpr Inherits() : Longhand(CSSPropertyID::kInherits, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// initial-value
class InitialValue final : public Longhand {
 public:
  constexpr InitialValue() : Longhand(CSSPropertyID::kInitialValue, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// inline-size
class InlineSize final : public Longhand {
 public:
  constexpr InlineSize() : Longhand(CSSPropertyID::kInlineSize, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// inset-block-end
class InsetBlockEnd final : public Longhand {
 public:
  constexpr InsetBlockEnd() : Longhand(CSSPropertyID::kInsetBlockEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// inset-block-start
class InsetBlockStart final : public Longhand {
 public:
  constexpr InsetBlockStart() : Longhand(CSSPropertyID::kInsetBlockStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// inset-inline-end
class InsetInlineEnd final : public Longhand {
 public:
  constexpr InsetInlineEnd() : Longhand(CSSPropertyID::kInsetInlineEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// inset-inline-start
class InsetInlineStart final : public Longhand {
 public:
  constexpr InsetInlineStart() : Longhand(CSSPropertyID::kInsetInlineStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-empty-line-height
class InternalEmptyLineHeight final : public Longhand {
 public:
  constexpr InternalEmptyLineHeight() : Longhand(CSSPropertyID::kInternalEmptyLineHeight, kProperty | kInternal, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-forced-background-color-rgb
class InternalForcedBackgroundColorRgb final : public Longhand {
 public:
  constexpr InternalForcedBackgroundColorRgb() : Longhand(CSSPropertyID::kInternalForcedBackgroundColorRgb, kProperty | kInternal | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-background-color
class InternalVisitedBackgroundColor final : public Longhand {
 public:
  constexpr InternalVisitedBackgroundColor() : Longhand(CSSPropertyID::kInternalVisitedBackgroundColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-block-end-color
class InternalVisitedBorderBlockEndColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderBlockEndColor() : Longhand(CSSPropertyID::kInternalVisitedBorderBlockEndColor, kProperty | kVisited | kInternal | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-block-start-color
class InternalVisitedBorderBlockStartColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderBlockStartColor() : Longhand(CSSPropertyID::kInternalVisitedBorderBlockStartColor, kProperty | kVisited | kInternal | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-bottom-color
class InternalVisitedBorderBottomColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderBottomColor() : Longhand(CSSPropertyID::kInternalVisitedBorderBottomColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-inline-end-color
class InternalVisitedBorderInlineEndColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderInlineEndColor() : Longhand(CSSPropertyID::kInternalVisitedBorderInlineEndColor, kProperty | kVisited | kInternal | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-inline-start-color
class InternalVisitedBorderInlineStartColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderInlineStartColor() : Longhand(CSSPropertyID::kInternalVisitedBorderInlineStartColor, kProperty | kVisited | kInternal | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-left-color
class InternalVisitedBorderLeftColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderLeftColor() : Longhand(CSSPropertyID::kInternalVisitedBorderLeftColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-right-color
class InternalVisitedBorderRightColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderRightColor() : Longhand(CSSPropertyID::kInternalVisitedBorderRightColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-border-top-color
class InternalVisitedBorderTopColor final : public Longhand {
 public:
  constexpr InternalVisitedBorderTopColor() : Longhand(CSSPropertyID::kInternalVisitedBorderTopColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-caret-color
class InternalVisitedCaretColor final : public Longhand {
 public:
  constexpr InternalVisitedCaretColor() : Longhand(CSSPropertyID::kInternalVisitedCaretColor, kProperty | kInherited | kVisited | kInternal, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-column-rule-color
class InternalVisitedColumnRuleColor final : public Longhand {
 public:
  constexpr InternalVisitedColumnRuleColor() : Longhand(CSSPropertyID::kInternalVisitedColumnRuleColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-fill
class InternalVisitedFill final : public Longhand {
 public:
  constexpr InternalVisitedFill() : Longhand(CSSPropertyID::kInternalVisitedFill, kProperty | kInherited | kVisited | kInternal | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-outline-color
class InternalVisitedOutlineColor final : public Longhand {
 public:
  constexpr InternalVisitedOutlineColor() : Longhand(CSSPropertyID::kInternalVisitedOutlineColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-stroke
class InternalVisitedStroke final : public Longhand {
 public:
  constexpr InternalVisitedStroke() : Longhand(CSSPropertyID::kInternalVisitedStroke, kProperty | kInherited | kVisited | kInternal | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-text-decoration-color
class InternalVisitedTextDecorationColor final : public Longhand {
 public:
  constexpr InternalVisitedTextDecorationColor() : Longhand(CSSPropertyID::kInternalVisitedTextDecorationColor, kProperty | kVisited | kInternal | kIsAffectedByForcedColors | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-text-emphasis-color
class InternalVisitedTextEmphasisColor final : public Longhand {
 public:
  constexpr InternalVisitedTextEmphasisColor() : Longhand(CSSPropertyID::kInternalVisitedTextEmphasisColor, kProperty | kInherited | kVisited | kInternal | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-text-fill-color
class InternalVisitedTextFillColor final : public Longhand {
 public:
  constexpr InternalVisitedTextFillColor() : Longhand(CSSPropertyID::kInternalVisitedTextFillColor, kProperty | kInherited | kVisited | kInternal, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -internal-visited-text-stroke-color
class InternalVisitedTextStrokeColor final : public Longhand {
 public:
  constexpr InternalVisitedTextStrokeColor() : Longhand(CSSPropertyID::kInternalVisitedTextStrokeColor, kProperty | kInherited | kVisited | kInternal, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* GetUnvisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// isolation
class Isolation final : public Longhand {
 public:
  constexpr Isolation() : Longhand(CSSPropertyID::kIsolation, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// justify-content
class JustifyContent final : public Longhand {
 public:
  constexpr JustifyContent() : Longhand(CSSPropertyID::kJustifyContent, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// justify-items
class JustifyItems final : public Longhand {
 public:
  constexpr JustifyItems() : Longhand(CSSPropertyID::kJustifyItems, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// justify-self
class JustifySelf final : public Longhand {
 public:
  constexpr JustifySelf() : Longhand(CSSPropertyID::kJustifySelf, kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// left
class Left final : public Longhand {
 public:
  constexpr Left() : Longhand(CSSPropertyID::kLeft, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// letter-spacing
class LetterSpacing final : public Longhand {
 public:
  constexpr LetterSpacing() : Longhand(CSSPropertyID::kLetterSpacing, kInterpolable | kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// lighting-color
class LightingColor final : public Longhand {
 public:
  constexpr LightingColor() : Longhand(CSSPropertyID::kLightingColor, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// line-break
class LineBreak final : public Longhand {
 public:
  constexpr LineBreak() : Longhand(CSSPropertyID::kLineBreak, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// line-height
class LineHeight final : public Longhand {
 public:
  constexpr LineHeight() : Longhand(CSSPropertyID::kLineHeight, kInterpolable | kProperty | kInherited | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// line-height-step
class LineHeightStep final : public Longhand {
 public:
  constexpr LineHeightStep() : Longhand(CSSPropertyID::kLineHeightStep, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// list-style-image
class ListStyleImage final : public Longhand {
 public:
  constexpr ListStyleImage() : Longhand(CSSPropertyID::kListStyleImage, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// list-style-position
class ListStylePosition final : public Longhand {
 public:
  constexpr ListStylePosition() : Longhand(CSSPropertyID::kListStylePosition, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// list-style-type
class ListStyleType final : public Longhand {
 public:
  constexpr ListStyleType() : Longhand(CSSPropertyID::kListStyleType, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-block-end
class MarginBlockEnd final : public Longhand {
 public:
  constexpr MarginBlockEnd() : Longhand(CSSPropertyID::kMarginBlockEnd, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-block-start
class MarginBlockStart final : public Longhand {
 public:
  constexpr MarginBlockStart() : Longhand(CSSPropertyID::kMarginBlockStart, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-bottom
class MarginBottom final : public Longhand {
 public:
  constexpr MarginBottom() : Longhand(CSSPropertyID::kMarginBottom, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-inline-end
class MarginInlineEnd final : public Longhand {
 public:
  constexpr MarginInlineEnd() : Longhand(CSSPropertyID::kMarginInlineEnd, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-inline-start
class MarginInlineStart final : public Longhand {
 public:
  constexpr MarginInlineStart() : Longhand(CSSPropertyID::kMarginInlineStart, kProperty | kValidForFirstLetter | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-left
class MarginLeft final : public Longhand {
 public:
  constexpr MarginLeft() : Longhand(CSSPropertyID::kMarginLeft, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-right
class MarginRight final : public Longhand {
 public:
  constexpr MarginRight() : Longhand(CSSPropertyID::kMarginRight, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// margin-top
class MarginTop final : public Longhand {
 public:
  constexpr MarginTop() : Longhand(CSSPropertyID::kMarginTop, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// marker-end
class MarkerEnd final : public Longhand {
 public:
  constexpr MarkerEnd() : Longhand(CSSPropertyID::kMarkerEnd, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// marker-mid
class MarkerMid final : public Longhand {
 public:
  constexpr MarkerMid() : Longhand(CSSPropertyID::kMarkerMid, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// marker-start
class MarkerStart final : public Longhand {
 public:
  constexpr MarkerStart() : Longhand(CSSPropertyID::kMarkerStart, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// mask
class Mask final : public Longhand {
 public:
  constexpr Mask() : Longhand(CSSPropertyID::kMask, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// mask-type
class MaskType final : public Longhand {
 public:
  constexpr MaskType() : Longhand(CSSPropertyID::kMaskType, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// math-style
class MathStyle final : public Longhand {
 public:
  constexpr MathStyle() : Longhand(CSSPropertyID::kMathStyle, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// math-superscript-shift-style
class MathSuperscriptShiftStyle final : public Longhand {
 public:
  constexpr MathSuperscriptShiftStyle() : Longhand(CSSPropertyID::kMathSuperscriptShiftStyle, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// max-block-size
class MaxBlockSize final : public Longhand {
 public:
  constexpr MaxBlockSize() : Longhand(CSSPropertyID::kMaxBlockSize, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// max-height
class MaxHeight final : public Longhand {
 public:
  constexpr MaxHeight() : Longhand(CSSPropertyID::kMaxHeight, kInterpolable | kDescriptor | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// max-inline-size
class MaxInlineSize final : public Longhand {
 public:
  constexpr MaxInlineSize() : Longhand(CSSPropertyID::kMaxInlineSize, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// max-width
class MaxWidth final : public Longhand {
 public:
  constexpr MaxWidth() : Longhand(CSSPropertyID::kMaxWidth, kInterpolable | kDescriptor | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// max-zoom
class MaxZoom final : public Longhand {
 public:
  constexpr MaxZoom() : Longhand(CSSPropertyID::kMaxZoom, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// min-block-size
class MinBlockSize final : public Longhand {
 public:
  constexpr MinBlockSize() : Longhand(CSSPropertyID::kMinBlockSize, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// min-height
class MinHeight final : public Longhand {
 public:
  constexpr MinHeight() : Longhand(CSSPropertyID::kMinHeight, kInterpolable | kDescriptor | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// min-inline-size
class MinInlineSize final : public Longhand {
 public:
  constexpr MinInlineSize() : Longhand(CSSPropertyID::kMinInlineSize, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// min-width
class MinWidth final : public Longhand {
 public:
  constexpr MinWidth() : Longhand(CSSPropertyID::kMinWidth, kInterpolable | kDescriptor | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// min-zoom
class MinZoom final : public Longhand {
 public:
  constexpr MinZoom() : Longhand(CSSPropertyID::kMinZoom, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// mix-blend-mode
class MixBlendMode final : public Longhand {
 public:
  constexpr MixBlendMode() : Longhand(CSSPropertyID::kMixBlendMode, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// object-fit
class ObjectFit final : public Longhand {
 public:
  constexpr ObjectFit() : Longhand(CSSPropertyID::kObjectFit, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// object-position
class ObjectPosition final : public Longhand {
 public:
  constexpr ObjectPosition() : Longhand(CSSPropertyID::kObjectPosition, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// offset-anchor
class OffsetAnchor final : public Longhand {
 public:
  constexpr OffsetAnchor() : Longhand(CSSPropertyID::kOffsetAnchor, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// offset-distance
class OffsetDistance final : public Longhand {
 public:
  constexpr OffsetDistance() : Longhand(CSSPropertyID::kOffsetDistance, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// offset-path
class OffsetPath final : public Longhand {
 public:
  constexpr OffsetPath() : Longhand(CSSPropertyID::kOffsetPath, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// offset-position
class OffsetPosition final : public Longhand {
 public:
  constexpr OffsetPosition() : Longhand(CSSPropertyID::kOffsetPosition, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// offset-rotate
class OffsetRotate final : public Longhand {
 public:
  constexpr OffsetRotate() : Longhand(CSSPropertyID::kOffsetRotate, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// opacity
class Opacity final : public Longhand {
 public:
  constexpr Opacity() : Longhand(CSSPropertyID::kOpacity, kInterpolable | kCompositableProperty | kProperty | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// order
class Order final : public Longhand {
 public:
  constexpr Order() : Longhand(CSSPropertyID::kOrder, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// orientation
class Orientation final : public Longhand {
 public:
  constexpr Orientation() : Longhand(CSSPropertyID::kOrientation, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// origin-trial-test-property
class OriginTrialTestProperty final : public Longhand {
 public:
  constexpr OriginTrialTestProperty() : Longhand(CSSPropertyID::kOriginTrialTestProperty, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure(const ExecutionContext*) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// orphans
class Orphans final : public Longhand {
 public:
  constexpr Orphans() : Longhand(CSSPropertyID::kOrphans, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// outline-color
class OutlineColor final : public Longhand {
 public:
  constexpr OutlineColor() : Longhand(CSSPropertyID::kOutlineColor, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// outline-offset
class OutlineOffset final : public Longhand {
 public:
  constexpr OutlineOffset() : Longhand(CSSPropertyID::kOutlineOffset, kInterpolable | kProperty | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// outline-style
class OutlineStyle final : public Longhand {
 public:
  constexpr OutlineStyle() : Longhand(CSSPropertyID::kOutlineStyle, kProperty | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// outline-width
class OutlineWidth final : public Longhand {
 public:
  constexpr OutlineWidth() : Longhand(CSSPropertyID::kOutlineWidth, kInterpolable | kProperty | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overflow-anchor
class OverflowAnchor final : public Longhand {
 public:
  constexpr OverflowAnchor() : Longhand(CSSPropertyID::kOverflowAnchor, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overflow-block
class OverflowBlock final : public Longhand {
 public:
  constexpr OverflowBlock() : Longhand(CSSPropertyID::kOverflowBlock, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overflow-inline
class OverflowInline final : public Longhand {
 public:
  constexpr OverflowInline() : Longhand(CSSPropertyID::kOverflowInline, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overflow-wrap
class OverflowWrap final : public Longhand {
 public:
  constexpr OverflowWrap() : Longhand(CSSPropertyID::kOverflowWrap, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overflow-x
class OverflowX final : public Longhand {
 public:
  constexpr OverflowX() : Longhand(CSSPropertyID::kOverflowX, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overflow-y
class OverflowY final : public Longhand {
 public:
  constexpr OverflowY() : Longhand(CSSPropertyID::kOverflowY, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overscroll-behavior-block
class OverscrollBehaviorBlock final : public Longhand {
 public:
  constexpr OverscrollBehaviorBlock() : Longhand(CSSPropertyID::kOverscrollBehaviorBlock, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overscroll-behavior-inline
class OverscrollBehaviorInline final : public Longhand {
 public:
  constexpr OverscrollBehaviorInline() : Longhand(CSSPropertyID::kOverscrollBehaviorInline, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overscroll-behavior-x
class OverscrollBehaviorX final : public Longhand {
 public:
  constexpr OverscrollBehaviorX() : Longhand(CSSPropertyID::kOverscrollBehaviorX, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// overscroll-behavior-y
class OverscrollBehaviorY final : public Longhand {
 public:
  constexpr OverscrollBehaviorY() : Longhand(CSSPropertyID::kOverscrollBehaviorY, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-block-end
class PaddingBlockEnd final : public Longhand {
 public:
  constexpr PaddingBlockEnd() : Longhand(CSSPropertyID::kPaddingBlockEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-block-start
class PaddingBlockStart final : public Longhand {
 public:
  constexpr PaddingBlockStart() : Longhand(CSSPropertyID::kPaddingBlockStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-bottom
class PaddingBottom final : public Longhand {
 public:
  constexpr PaddingBottom() : Longhand(CSSPropertyID::kPaddingBottom, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-inline-end
class PaddingInlineEnd final : public Longhand {
 public:
  constexpr PaddingInlineEnd() : Longhand(CSSPropertyID::kPaddingInlineEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-inline-start
class PaddingInlineStart final : public Longhand {
 public:
  constexpr PaddingInlineStart() : Longhand(CSSPropertyID::kPaddingInlineStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-left
class PaddingLeft final : public Longhand {
 public:
  constexpr PaddingLeft() : Longhand(CSSPropertyID::kPaddingLeft, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-right
class PaddingRight final : public Longhand {
 public:
  constexpr PaddingRight() : Longhand(CSSPropertyID::kPaddingRight, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// padding-top
class PaddingTop final : public Longhand {
 public:
  constexpr PaddingTop() : Longhand(CSSPropertyID::kPaddingTop, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// page
class Page final : public Longhand {
 public:
  constexpr Page() : Longhand(CSSPropertyID::kPage, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// page-orientation
class PageOrientation final : public Longhand {
 public:
  constexpr PageOrientation() : Longhand(CSSPropertyID::kPageOrientation, kDescriptor | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// paint-order
class PaintOrder final : public Longhand {
 public:
  constexpr PaintOrder() : Longhand(CSSPropertyID::kPaintOrder, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// perspective
class Perspective final : public Longhand {
 public:
  constexpr Perspective() : Longhand(CSSPropertyID::kPerspective, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// perspective-origin
class PerspectiveOrigin final : public Longhand {
 public:
  constexpr PerspectiveOrigin() : Longhand(CSSPropertyID::kPerspectiveOrigin, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// pointer-events
class PointerEvents final : public Longhand {
 public:
  constexpr PointerEvents() : Longhand(CSSPropertyID::kPointerEvents, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// position
class Position final : public Longhand {
 public:
  constexpr Position() : Longhand(CSSPropertyID::kPosition, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// quotes
class Quotes final : public Longhand {
 public:
  constexpr Quotes() : Longhand(CSSPropertyID::kQuotes, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// r
class R final : public Longhand {
 public:
  constexpr R() : Longhand(CSSPropertyID::kR, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// resize
class Resize final : public Longhand {
 public:
  constexpr Resize() : Longhand(CSSPropertyID::kResize, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// right
class Right final : public Longhand {
 public:
  constexpr Right() : Longhand(CSSPropertyID::kRight, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// rotate
class Rotate final : public Longhand {
 public:
  constexpr Rotate() : Longhand(CSSPropertyID::kRotate, kInterpolable | kCompositableProperty | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// row-gap
class RowGap final : public Longhand {
 public:
  constexpr RowGap() : Longhand(CSSPropertyID::kRowGap, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// ruby-position
class RubyPosition final : public Longhand {
 public:
  constexpr RubyPosition() : Longhand(CSSPropertyID::kRubyPosition, kProperty | kInherited | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// rx
class Rx final : public Longhand {
 public:
  constexpr Rx() : Longhand(CSSPropertyID::kRx, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// ry
class Ry final : public Longhand {
 public:
  constexpr Ry() : Longhand(CSSPropertyID::kRy, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scale
class Scale final : public Longhand {
 public:
  constexpr Scale() : Longhand(CSSPropertyID::kScale, kInterpolable | kCompositableProperty | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-behavior
class ScrollBehavior final : public Longhand {
 public:
  constexpr ScrollBehavior() : Longhand(CSSPropertyID::kScrollBehavior, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-customization
class ScrollCustomization final : public Longhand {
 public:
  constexpr ScrollCustomization() : Longhand(CSSPropertyID::kScrollCustomization, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-block-end
class ScrollMarginBlockEnd final : public Longhand {
 public:
  constexpr ScrollMarginBlockEnd() : Longhand(CSSPropertyID::kScrollMarginBlockEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-block-start
class ScrollMarginBlockStart final : public Longhand {
 public:
  constexpr ScrollMarginBlockStart() : Longhand(CSSPropertyID::kScrollMarginBlockStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-bottom
class ScrollMarginBottom final : public Longhand {
 public:
  constexpr ScrollMarginBottom() : Longhand(CSSPropertyID::kScrollMarginBottom, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-inline-end
class ScrollMarginInlineEnd final : public Longhand {
 public:
  constexpr ScrollMarginInlineEnd() : Longhand(CSSPropertyID::kScrollMarginInlineEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-inline-start
class ScrollMarginInlineStart final : public Longhand {
 public:
  constexpr ScrollMarginInlineStart() : Longhand(CSSPropertyID::kScrollMarginInlineStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-left
class ScrollMarginLeft final : public Longhand {
 public:
  constexpr ScrollMarginLeft() : Longhand(CSSPropertyID::kScrollMarginLeft, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-right
class ScrollMarginRight final : public Longhand {
 public:
  constexpr ScrollMarginRight() : Longhand(CSSPropertyID::kScrollMarginRight, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-margin-top
class ScrollMarginTop final : public Longhand {
 public:
  constexpr ScrollMarginTop() : Longhand(CSSPropertyID::kScrollMarginTop, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-block-end
class ScrollPaddingBlockEnd final : public Longhand {
 public:
  constexpr ScrollPaddingBlockEnd() : Longhand(CSSPropertyID::kScrollPaddingBlockEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-block-start
class ScrollPaddingBlockStart final : public Longhand {
 public:
  constexpr ScrollPaddingBlockStart() : Longhand(CSSPropertyID::kScrollPaddingBlockStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-bottom
class ScrollPaddingBottom final : public Longhand {
 public:
  constexpr ScrollPaddingBottom() : Longhand(CSSPropertyID::kScrollPaddingBottom, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-inline-end
class ScrollPaddingInlineEnd final : public Longhand {
 public:
  constexpr ScrollPaddingInlineEnd() : Longhand(CSSPropertyID::kScrollPaddingInlineEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-inline-start
class ScrollPaddingInlineStart final : public Longhand {
 public:
  constexpr ScrollPaddingInlineStart() : Longhand(CSSPropertyID::kScrollPaddingInlineStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSProperty& ResolveDirectionAwareProperty(TextDirection, blink::WritingMode) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(
      const ComputedStyle&,
      const SVGComputedStyle&,
      const LayoutObject*,
      bool allow_visited_style) const override {
    // Directional properties are resolved by CSSDirectionAwareResolver
    // before calling CSSValueFromComputedStyleInternal.
    NOTREACHED();
    return nullptr;
  }
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-left
class ScrollPaddingLeft final : public Longhand {
 public:
  constexpr ScrollPaddingLeft() : Longhand(CSSPropertyID::kScrollPaddingLeft, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-right
class ScrollPaddingRight final : public Longhand {
 public:
  constexpr ScrollPaddingRight() : Longhand(CSSPropertyID::kScrollPaddingRight, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-padding-top
class ScrollPaddingTop final : public Longhand {
 public:
  constexpr ScrollPaddingTop() : Longhand(CSSPropertyID::kScrollPaddingTop, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-snap-align
class ScrollSnapAlign final : public Longhand {
 public:
  constexpr ScrollSnapAlign() : Longhand(CSSPropertyID::kScrollSnapAlign, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-snap-stop
class ScrollSnapStop final : public Longhand {
 public:
  constexpr ScrollSnapStop() : Longhand(CSSPropertyID::kScrollSnapStop, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// scroll-snap-type
class ScrollSnapType final : public Longhand {
 public:
  constexpr ScrollSnapType() : Longhand(CSSPropertyID::kScrollSnapType, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// shape-image-threshold
class ShapeImageThreshold final : public Longhand {
 public:
  constexpr ShapeImageThreshold() : Longhand(CSSPropertyID::kShapeImageThreshold, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// shape-margin
class ShapeMargin final : public Longhand {
 public:
  constexpr ShapeMargin() : Longhand(CSSPropertyID::kShapeMargin, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// shape-outside
class ShapeOutside final : public Longhand {
 public:
  constexpr ShapeOutside() : Longhand(CSSPropertyID::kShapeOutside, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// shape-rendering
class ShapeRendering final : public Longhand {
 public:
  constexpr ShapeRendering() : Longhand(CSSPropertyID::kShapeRendering, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// size
class Size final : public Longhand {
 public:
  constexpr Size() : Longhand(CSSPropertyID::kSize, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// source
class Source final : public Longhand {
 public:
  constexpr Source() : Longhand(CSSPropertyID::kSource, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// speak
class Speak final : public Longhand {
 public:
  constexpr Speak() : Longhand(CSSPropertyID::kSpeak, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// src
class Src final : public Longhand {
 public:
  constexpr Src() : Longhand(CSSPropertyID::kSrc, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// start
class Start final : public Longhand {
 public:
  constexpr Start() : Longhand(CSSPropertyID::kStart, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// stop-color
class StopColor final : public Longhand {
 public:
  constexpr StopColor() : Longhand(CSSPropertyID::kStopColor, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stop-opacity
class StopOpacity final : public Longhand {
 public:
  constexpr StopOpacity() : Longhand(CSSPropertyID::kStopOpacity, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke
class Stroke final : public Longhand {
 public:
  constexpr Stroke() : Longhand(CSSPropertyID::kStroke, kInterpolable | kProperty | kInherited | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-dasharray
class StrokeDasharray final : public Longhand {
 public:
  constexpr StrokeDasharray() : Longhand(CSSPropertyID::kStrokeDasharray, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-dashoffset
class StrokeDashoffset final : public Longhand {
 public:
  constexpr StrokeDashoffset() : Longhand(CSSPropertyID::kStrokeDashoffset, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-linecap
class StrokeLinecap final : public Longhand {
 public:
  constexpr StrokeLinecap() : Longhand(CSSPropertyID::kStrokeLinecap, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-linejoin
class StrokeLinejoin final : public Longhand {
 public:
  constexpr StrokeLinejoin() : Longhand(CSSPropertyID::kStrokeLinejoin, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-miterlimit
class StrokeMiterlimit final : public Longhand {
 public:
  constexpr StrokeMiterlimit() : Longhand(CSSPropertyID::kStrokeMiterlimit, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-opacity
class StrokeOpacity final : public Longhand {
 public:
  constexpr StrokeOpacity() : Longhand(CSSPropertyID::kStrokeOpacity, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// stroke-width
class StrokeWidth final : public Longhand {
 public:
  constexpr StrokeWidth() : Longhand(CSSPropertyID::kStrokeWidth, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// syntax
class Syntax final : public Longhand {
 public:
  constexpr Syntax() : Longhand(CSSPropertyID::kSyntax, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// tab-size
class TabSize final : public Longhand {
 public:
  constexpr TabSize() : Longhand(CSSPropertyID::kTabSize, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// table-layout
class TableLayout final : public Longhand {
 public:
  constexpr TableLayout() : Longhand(CSSPropertyID::kTableLayout, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-align
class TextAlign final : public Longhand {
 public:
  constexpr TextAlign() : Longhand(CSSPropertyID::kTextAlign, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-align-last
class TextAlignLast final : public Longhand {
 public:
  constexpr TextAlignLast() : Longhand(CSSPropertyID::kTextAlignLast, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-anchor
class TextAnchor final : public Longhand {
 public:
  constexpr TextAnchor() : Longhand(CSSPropertyID::kTextAnchor, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-combine-upright
class TextCombineUpright final : public Longhand {
 public:
  constexpr TextCombineUpright() : Longhand(CSSPropertyID::kTextCombineUpright, kProperty | kInherited | kValidForMarker, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-decoration-color
class TextDecorationColor final : public Longhand {
 public:
  constexpr TextDecorationColor() : Longhand(CSSPropertyID::kTextDecorationColor, kInterpolable | kProperty | kIsAffectedByForcedColors | kValidForFirstLetter | kValidForCue | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-decoration-line
class TextDecorationLine final : public Longhand {
 public:
  constexpr TextDecorationLine() : Longhand(CSSPropertyID::kTextDecorationLine, kProperty | kValidForFirstLetter | kValidForCue | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-decoration-skip-ink
class TextDecorationSkipInk final : public Longhand {
 public:
  constexpr TextDecorationSkipInk() : Longhand(CSSPropertyID::kTextDecorationSkipInk, kProperty | kInherited | kValidForFirstLetter | kValidForCue | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-decoration-style
class TextDecorationStyle final : public Longhand {
 public:
  constexpr TextDecorationStyle() : Longhand(CSSPropertyID::kTextDecorationStyle, kProperty | kValidForFirstLetter | kValidForCue | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-decoration-thickness
class TextDecorationThickness final : public Longhand {
 public:
  constexpr TextDecorationThickness() : Longhand(CSSPropertyID::kTextDecorationThickness, kProperty | kInherited | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-indent
class TextIndent final : public Longhand {
 public:
  constexpr TextIndent() : Longhand(CSSPropertyID::kTextIndent, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-justify
class TextJustify final : public Longhand {
 public:
  constexpr TextJustify() : Longhand(CSSPropertyID::kTextJustify, kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-overflow
class TextOverflow final : public Longhand {
 public:
  constexpr TextOverflow() : Longhand(CSSPropertyID::kTextOverflow, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-shadow
class TextShadow final : public Longhand {
 public:
  constexpr TextShadow() : Longhand(CSSPropertyID::kTextShadow, kInterpolable | kProperty | kInherited | kIsAffectedByForcedColors | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-size-adjust
class TextSizeAdjust final : public Longhand {
 public:
  constexpr TextSizeAdjust() : Longhand(CSSPropertyID::kTextSizeAdjust, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-transform
class TextTransform final : public Longhand {
 public:
  constexpr TextTransform() : Longhand(CSSPropertyID::kTextTransform, kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-underline-offset
class TextUnderlineOffset final : public Longhand {
 public:
  constexpr TextUnderlineOffset() : Longhand(CSSPropertyID::kTextUnderlineOffset, kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// text-underline-position
class TextUnderlinePosition final : public Longhand {
 public:
  constexpr TextUnderlinePosition() : Longhand(CSSPropertyID::kTextUnderlinePosition, kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// time-range
class TimeRange final : public Longhand {
 public:
  constexpr TimeRange() : Longhand(CSSPropertyID::kTimeRange, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// top
class Top final : public Longhand {
 public:
  constexpr Top() : Longhand(CSSPropertyID::kTop, kInterpolable | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// touch-action
class TouchAction final : public Longhand {
 public:
  constexpr TouchAction() : Longhand(CSSPropertyID::kTouchAction, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transform
class Transform final : public Longhand {
 public:
  constexpr Transform() : Longhand(CSSPropertyID::kTransform, kInterpolable | kCompositableProperty | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transform-box
class TransformBox final : public Longhand {
 public:
  constexpr TransformBox() : Longhand(CSSPropertyID::kTransformBox, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transform-origin
class TransformOrigin final : public Longhand {
 public:
  constexpr TransformOrigin() : Longhand(CSSPropertyID::kTransformOrigin, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// transform-style
class TransformStyle final : public Longhand {
 public:
  constexpr TransformStyle() : Longhand(CSSPropertyID::kTransformStyle, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// translate
class Translate final : public Longhand {
 public:
  constexpr Translate() : Longhand(CSSPropertyID::kTranslate, kInterpolable | kCompositableProperty | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// unicode-bidi
class UnicodeBidi final : public Longhand {
 public:
  constexpr UnicodeBidi() : Longhand(CSSPropertyID::kUnicodeBidi, kProperty | kValidForMarker, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsAffectedByAll() const override { return false; }
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// unicode-range
class UnicodeRange final : public Longhand {
 public:
  constexpr UnicodeRange() : Longhand(CSSPropertyID::kUnicodeRange, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// user-select
class UserSelect final : public Longhand {
 public:
  constexpr UserSelect() : Longhand(CSSPropertyID::kUserSelect, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// user-zoom
class UserZoom final : public Longhand {
 public:
  constexpr UserZoom() : Longhand(CSSPropertyID::kUserZoom, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// vector-effect
class VectorEffect final : public Longhand {
 public:
  constexpr VectorEffect() : Longhand(CSSPropertyID::kVectorEffect, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// vertical-align
class VerticalAlign final : public Longhand {
 public:
  constexpr VerticalAlign() : Longhand(CSSPropertyID::kVerticalAlign, kInterpolable | kProperty | kValidForFirstLetter | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// viewport-fit
class ViewportFit final : public Longhand {
 public:
  constexpr ViewportFit() : Longhand(CSSPropertyID::kViewportFit, kDescriptor, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
 };

// visibility
class Visibility final : public Longhand {
 public:
  constexpr Visibility() : Longhand(CSSPropertyID::kVisibility, kInterpolable | kProperty | kInherited | kValidForFirstLetter | kValidForCue, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-app-region
class WebkitAppRegion final : public Longhand {
 public:
  constexpr WebkitAppRegion() : Longhand(CSSPropertyID::kWebkitAppRegion, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-border-horizontal-spacing
class WebkitBorderHorizontalSpacing final : public Longhand {
 public:
  constexpr WebkitBorderHorizontalSpacing() : Longhand(CSSPropertyID::kWebkitBorderHorizontalSpacing, kInterpolable | kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-border-image
class WebkitBorderImage final : public Longhand {
 public:
  constexpr WebkitBorderImage() : Longhand(CSSPropertyID::kWebkitBorderImage, kProperty | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-border-vertical-spacing
class WebkitBorderVerticalSpacing final : public Longhand {
 public:
  constexpr WebkitBorderVerticalSpacing() : Longhand(CSSPropertyID::kWebkitBorderVerticalSpacing, kInterpolable | kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-align
class WebkitBoxAlign final : public Longhand {
 public:
  constexpr WebkitBoxAlign() : Longhand(CSSPropertyID::kWebkitBoxAlign, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-decoration-break
class WebkitBoxDecorationBreak final : public Longhand {
 public:
  constexpr WebkitBoxDecorationBreak() : Longhand(CSSPropertyID::kWebkitBoxDecorationBreak, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-direction
class WebkitBoxDirection final : public Longhand {
 public:
  constexpr WebkitBoxDirection() : Longhand(CSSPropertyID::kWebkitBoxDirection, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-flex
class WebkitBoxFlex final : public Longhand {
 public:
  constexpr WebkitBoxFlex() : Longhand(CSSPropertyID::kWebkitBoxFlex, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-ordinal-group
class WebkitBoxOrdinalGroup final : public Longhand {
 public:
  constexpr WebkitBoxOrdinalGroup() : Longhand(CSSPropertyID::kWebkitBoxOrdinalGroup, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-orient
class WebkitBoxOrient final : public Longhand {
 public:
  constexpr WebkitBoxOrient() : Longhand(CSSPropertyID::kWebkitBoxOrient, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-pack
class WebkitBoxPack final : public Longhand {
 public:
  constexpr WebkitBoxPack() : Longhand(CSSPropertyID::kWebkitBoxPack, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-box-reflect
class WebkitBoxReflect final : public Longhand {
 public:
  constexpr WebkitBoxReflect() : Longhand(CSSPropertyID::kWebkitBoxReflect, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-font-size-delta
class WebkitFontSizeDelta final : public Longhand {
 public:
  constexpr WebkitFontSizeDelta() : Longhand(CSSPropertyID::kWebkitFontSizeDelta, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-highlight
class WebkitHighlight final : public Longhand {
 public:
  constexpr WebkitHighlight() : Longhand(CSSPropertyID::kWebkitHighlight, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-hyphenate-character
class WebkitHyphenateCharacter final : public Longhand {
 public:
  constexpr WebkitHyphenateCharacter() : Longhand(CSSPropertyID::kWebkitHyphenateCharacter, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-line-break
class WebkitLineBreak final : public Longhand {
 public:
  constexpr WebkitLineBreak() : Longhand(CSSPropertyID::kWebkitLineBreak, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-line-clamp
class WebkitLineClamp final : public Longhand {
 public:
  constexpr WebkitLineClamp() : Longhand(CSSPropertyID::kWebkitLineClamp, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-box-image-outset
class WebkitMaskBoxImageOutset final : public Longhand {
 public:
  constexpr WebkitMaskBoxImageOutset() : Longhand(CSSPropertyID::kWebkitMaskBoxImageOutset, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-box-image-repeat
class WebkitMaskBoxImageRepeat final : public Longhand {
 public:
  constexpr WebkitMaskBoxImageRepeat() : Longhand(CSSPropertyID::kWebkitMaskBoxImageRepeat, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-box-image-slice
class WebkitMaskBoxImageSlice final : public Longhand {
 public:
  constexpr WebkitMaskBoxImageSlice() : Longhand(CSSPropertyID::kWebkitMaskBoxImageSlice, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-box-image-source
class WebkitMaskBoxImageSource final : public Longhand {
 public:
  constexpr WebkitMaskBoxImageSource() : Longhand(CSSPropertyID::kWebkitMaskBoxImageSource, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-box-image-width
class WebkitMaskBoxImageWidth final : public Longhand {
 public:
  constexpr WebkitMaskBoxImageWidth() : Longhand(CSSPropertyID::kWebkitMaskBoxImageWidth, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-clip
class WebkitMaskClip final : public Longhand {
 public:
  constexpr WebkitMaskClip() : Longhand(CSSPropertyID::kWebkitMaskClip, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-composite
class WebkitMaskComposite final : public Longhand {
 public:
  constexpr WebkitMaskComposite() : Longhand(CSSPropertyID::kWebkitMaskComposite, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-image
class WebkitMaskImage final : public Longhand {
 public:
  constexpr WebkitMaskImage() : Longhand(CSSPropertyID::kWebkitMaskImage, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-origin
class WebkitMaskOrigin final : public Longhand {
 public:
  constexpr WebkitMaskOrigin() : Longhand(CSSPropertyID::kWebkitMaskOrigin, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-position-x
class WebkitMaskPositionX final : public Longhand {
 public:
  constexpr WebkitMaskPositionX() : Longhand(CSSPropertyID::kWebkitMaskPositionX, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-position-y
class WebkitMaskPositionY final : public Longhand {
 public:
  constexpr WebkitMaskPositionY() : Longhand(CSSPropertyID::kWebkitMaskPositionY, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-repeat-x
class WebkitMaskRepeatX final : public Longhand {
 public:
  constexpr WebkitMaskRepeatX() : Longhand(CSSPropertyID::kWebkitMaskRepeatX, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-repeat-y
class WebkitMaskRepeatY final : public Longhand {
 public:
  constexpr WebkitMaskRepeatY() : Longhand(CSSPropertyID::kWebkitMaskRepeatY, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-mask-size
class WebkitMaskSize final : public Longhand {
 public:
  constexpr WebkitMaskSize() : Longhand(CSSPropertyID::kWebkitMaskSize, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-perspective-origin-x
class WebkitPerspectiveOriginX final : public Longhand {
 public:
  constexpr WebkitPerspectiveOriginX() : Longhand(CSSPropertyID::kWebkitPerspectiveOriginX, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-perspective-origin-y
class WebkitPerspectiveOriginY final : public Longhand {
 public:
  constexpr WebkitPerspectiveOriginY() : Longhand(CSSPropertyID::kWebkitPerspectiveOriginY, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-print-color-adjust
class WebkitPrintColorAdjust final : public Longhand {
 public:
  constexpr WebkitPrintColorAdjust() : Longhand(CSSPropertyID::kWebkitPrintColorAdjust, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-rtl-ordering
class WebkitRtlOrdering final : public Longhand {
 public:
  constexpr WebkitRtlOrdering() : Longhand(CSSPropertyID::kWebkitRtlOrdering, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-ruby-position
class WebkitRubyPosition final : public Longhand {
 public:
  constexpr WebkitRubyPosition() : Longhand(CSSPropertyID::kWebkitRubyPosition, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-tap-highlight-color
class WebkitTapHighlightColor final : public Longhand {
 public:
  constexpr WebkitTapHighlightColor() : Longhand(CSSPropertyID::kWebkitTapHighlightColor, kProperty | kInherited | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-combine
class WebkitTextCombine final : public Longhand {
 public:
  constexpr WebkitTextCombine() : Longhand(CSSPropertyID::kWebkitTextCombine, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-decorations-in-effect
class WebkitTextDecorationsInEffect final : public Longhand {
 public:
  constexpr WebkitTextDecorationsInEffect() : Longhand(CSSPropertyID::kWebkitTextDecorationsInEffect, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-emphasis-color
class WebkitTextEmphasisColor final : public Longhand {
 public:
  constexpr WebkitTextEmphasisColor() : Longhand(CSSPropertyID::kWebkitTextEmphasisColor, kProperty | kInherited | kIsAffectedByForcedColors, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-emphasis-position
class WebkitTextEmphasisPosition final : public Longhand {
 public:
  constexpr WebkitTextEmphasisPosition() : Longhand(CSSPropertyID::kWebkitTextEmphasisPosition, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-emphasis-style
class WebkitTextEmphasisStyle final : public Longhand {
 public:
  constexpr WebkitTextEmphasisStyle() : Longhand(CSSPropertyID::kWebkitTextEmphasisStyle, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-fill-color
class WebkitTextFillColor final : public Longhand {
 public:
  constexpr WebkitTextFillColor() : Longhand(CSSPropertyID::kWebkitTextFillColor, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-security
class WebkitTextSecurity final : public Longhand {
 public:
  constexpr WebkitTextSecurity() : Longhand(CSSPropertyID::kWebkitTextSecurity, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-stroke-color
class WebkitTextStrokeColor final : public Longhand {
 public:
  constexpr WebkitTextStrokeColor() : Longhand(CSSPropertyID::kWebkitTextStrokeColor, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* GetVisitedProperty() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  const blink::Color ColorIncludingFallback(bool, const ComputedStyle&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-text-stroke-width
class WebkitTextStrokeWidth final : public Longhand {
 public:
  constexpr WebkitTextStrokeWidth() : Longhand(CSSPropertyID::kWebkitTextStrokeWidth, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-transform-origin-x
class WebkitTransformOriginX final : public Longhand {
 public:
  constexpr WebkitTransformOriginX() : Longhand(CSSPropertyID::kWebkitTransformOriginX, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-transform-origin-y
class WebkitTransformOriginY final : public Longhand {
 public:
  constexpr WebkitTransformOriginY() : Longhand(CSSPropertyID::kWebkitTransformOriginY, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-transform-origin-z
class WebkitTransformOriginZ final : public Longhand {
 public:
  constexpr WebkitTransformOriginZ() : Longhand(CSSPropertyID::kWebkitTransformOriginZ, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-user-drag
class WebkitUserDrag final : public Longhand {
 public:
  constexpr WebkitUserDrag() : Longhand(CSSPropertyID::kWebkitUserDrag, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-user-modify
class WebkitUserModify final : public Longhand {
 public:
  constexpr WebkitUserModify() : Longhand(CSSPropertyID::kWebkitUserModify, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// white-space
class WhiteSpace final : public Longhand {
 public:
  constexpr WhiteSpace() : Longhand(CSSPropertyID::kWhiteSpace, kProperty | kInherited | kValidForCue | kValidForMarker, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// widows
class Widows final : public Longhand {
 public:
  constexpr Widows() : Longhand(CSSPropertyID::kWidows, kInterpolable | kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// width
class Width final : public Longhand {
 public:
  constexpr Width() : Longhand(CSSPropertyID::kWidth, kInterpolable | kDescriptor | kProperty | kComputedValueComparable, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  bool ComputedValuesEqual(const ComputedStyle& a, const ComputedStyle& b) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// will-change
class WillChange final : public Longhand {
 public:
  constexpr WillChange() : Longhand(CSSPropertyID::kWillChange, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// word-break
class WordBreak final : public Longhand {
 public:
  constexpr WordBreak() : Longhand(CSSPropertyID::kWordBreak, kProperty | kInherited, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// word-spacing
class WordSpacing final : public Longhand {
 public:
  constexpr WordSpacing() : Longhand(CSSPropertyID::kWordSpacing, kInterpolable | kProperty | kInherited | kValidForFirstLetter, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// x
class X final : public Longhand {
 public:
  constexpr X() : Longhand(CSSPropertyID::kX, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// y
class Y final : public Longhand {
 public:
  constexpr Y() : Longhand(CSSPropertyID::kY, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// z-index
class ZIndex final : public Longhand {
 public:
  constexpr ZIndex() : Longhand(CSSPropertyID::kZIndex, kInterpolable | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSValue* ParseSingleValue(CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
  void ApplyInitial(StyleResolverState&) const override;
  void ApplyInherit(StyleResolverState&) const override;
  void ApplyValue(StyleResolverState&, const CSSValue&) const  override;
 };

// -webkit-appearance
class WebkitAppearance final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAppearance() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-end-color
class WebkitBorderEndColor final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderEndColor() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-end-style
class WebkitBorderEndStyle final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderEndStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-end-width
class WebkitBorderEndWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderEndWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-start-color
class WebkitBorderStartColor final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderStartColor() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-start-style
class WebkitBorderStartStyle final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderStartStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-start-width
class WebkitBorderStartWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderStartWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-before-color
class WebkitBorderBeforeColor final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderBeforeColor() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-before-style
class WebkitBorderBeforeStyle final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderBeforeStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-before-width
class WebkitBorderBeforeWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderBeforeWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-after-color
class WebkitBorderAfterColor final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderAfterColor() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-after-style
class WebkitBorderAfterStyle final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderAfterStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-after-width
class WebkitBorderAfterWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderAfterWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-margin-end
class WebkitMarginEnd final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMarginEnd() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-margin-start
class WebkitMarginStart final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMarginStart() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-margin-before
class WebkitMarginBefore final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMarginBefore() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-margin-after
class WebkitMarginAfter final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMarginAfter() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-padding-end
class WebkitPaddingEnd final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitPaddingEnd() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-padding-start
class WebkitPaddingStart final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitPaddingStart() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-padding-before
class WebkitPaddingBefore final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitPaddingBefore() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-padding-after
class WebkitPaddingAfter final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitPaddingAfter() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-logical-width
class WebkitLogicalWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitLogicalWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-logical-height
class WebkitLogicalHeight final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitLogicalHeight() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-min-logical-width
class WebkitMinLogicalWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMinLogicalWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-min-logical-height
class WebkitMinLogicalHeight final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMinLogicalHeight() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-max-logical-width
class WebkitMaxLogicalWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMaxLogicalWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-max-logical-height
class WebkitMaxLogicalHeight final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitMaxLogicalHeight() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-caption-side
class EpubCaptionSide final : public CSSUnresolvedProperty {
 public:
  constexpr EpubCaptionSide() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-text-combine
class EpubTextCombine final : public CSSUnresolvedProperty {
 public:
  constexpr EpubTextCombine() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-text-emphasis-color
class EpubTextEmphasisColor final : public CSSUnresolvedProperty {
 public:
  constexpr EpubTextEmphasisColor() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-text-emphasis-style
class EpubTextEmphasisStyle final : public CSSUnresolvedProperty {
 public:
  constexpr EpubTextEmphasisStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-text-orientation
class EpubTextOrientation final : public CSSUnresolvedProperty {
 public:
  constexpr EpubTextOrientation() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-text-transform
class EpubTextTransform final : public CSSUnresolvedProperty {
 public:
  constexpr EpubTextTransform() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-word-break
class EpubWordBreak final : public CSSUnresolvedProperty {
 public:
  constexpr EpubWordBreak() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-writing-mode
class EpubWritingMode final : public CSSUnresolvedProperty {
 public:
  constexpr EpubWritingMode() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-align-content
class WebkitAlignContent final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAlignContent() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-align-items
class WebkitAlignItems final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAlignItems() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-align-self
class WebkitAlignSelf final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAlignSelf() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-delay
class WebkitAnimationDelay final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationDelay() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-direction
class WebkitAnimationDirection final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationDirection() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-duration
class WebkitAnimationDuration final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationDuration() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-fill-mode
class WebkitAnimationFillMode final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationFillMode() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-iteration-count
class WebkitAnimationIterationCount final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationIterationCount() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-name
class WebkitAnimationName final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationName() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-play-state
class WebkitAnimationPlayState final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationPlayState() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation-timing-function
class WebkitAnimationTimingFunction final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimationTimingFunction() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-backface-visibility
class WebkitBackfaceVisibility final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBackfaceVisibility() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-background-clip
class WebkitBackgroundClip final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBackgroundClip() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-background-origin
class WebkitBackgroundOrigin final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBackgroundOrigin() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-background-size
class WebkitBackgroundSize final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBackgroundSize() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-bottom-left-radius
class WebkitBorderBottomLeftRadius final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderBottomLeftRadius() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-bottom-right-radius
class WebkitBorderBottomRightRadius final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderBottomRightRadius() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-top-left-radius
class WebkitBorderTopLeftRadius final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderTopLeftRadius() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-top-right-radius
class WebkitBorderTopRightRadius final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderTopRightRadius() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-box-shadow
class WebkitBoxShadow final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBoxShadow() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-box-sizing
class WebkitBoxSizing final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBoxSizing() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-clip-path
class WebkitClipPath final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitClipPath() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-count
class WebkitColumnCount final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnCount() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-gap
class WebkitColumnGap final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnGap() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-rule-color
class WebkitColumnRuleColor final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnRuleColor() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-rule-style
class WebkitColumnRuleStyle final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnRuleStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-rule-width
class WebkitColumnRuleWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnRuleWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-span
class WebkitColumnSpan final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnSpan() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-width
class WebkitColumnWidth final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnWidth() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-filter
class WebkitFilter final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFilter() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex-basis
class WebkitFlexBasis final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlexBasis() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex-direction
class WebkitFlexDirection final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlexDirection() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex-grow
class WebkitFlexGrow final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlexGrow() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex-shrink
class WebkitFlexShrink final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlexShrink() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex-wrap
class WebkitFlexWrap final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlexWrap() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-font-feature-settings
class WebkitFontFeatureSettings final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFontFeatureSettings() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-justify-content
class WebkitJustifyContent final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitJustifyContent() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-opacity
class WebkitOpacity final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitOpacity() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-order
class WebkitOrder final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitOrder() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-perspective
class WebkitPerspective final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitPerspective() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-perspective-origin
class WebkitPerspectiveOrigin final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitPerspectiveOrigin() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-shape-image-threshold
class WebkitShapeImageThreshold final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitShapeImageThreshold() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-shape-margin
class WebkitShapeMargin final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitShapeMargin() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-shape-outside
class WebkitShapeOutside final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitShapeOutside() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-text-size-adjust
class WebkitTextSizeAdjust final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTextSizeAdjust() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transform
class WebkitTransform final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransform() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transform-origin
class WebkitTransformOrigin final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransformOrigin() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transform-style
class WebkitTransformStyle final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransformStyle() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transition-delay
class WebkitTransitionDelay final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransitionDelay() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transition-duration
class WebkitTransitionDuration final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransitionDuration() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transition-property
class WebkitTransitionProperty final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransitionProperty() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transition-timing-function
class WebkitTransitionTimingFunction final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransitionTimingFunction() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-user-select
class WebkitUserSelect final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitUserSelect() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// word-wrap
class WordWrap final : public CSSUnresolvedProperty {
 public:
  constexpr WordWrap() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

 
}  // namespace css_longhand
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTIES_CSS_PROPERTIES_LONGHANDS_H_
