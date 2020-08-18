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



#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTIES_CSS_PROPERTIES_SHORTHANDS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTIES_CSS_PROPERTIES_SHORTHANDS_H_

#include "third_party/blink/renderer/core/css/properties/shorthand.h"

namespace blink {

class ComputedStyle;
class CSSParserContext;
class CSSParserLocalContext;
class CSSValue;
class LayoutObject;
class Node;
class SVGComputedStyle;

namespace css_shorthand {

// animation
class Animation final : public Shorthand {
 public:
  constexpr Animation() : Shorthand(CSSPropertyID::kAnimation, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// background
class Background final : public Shorthand {
 public:
  constexpr Background() : Shorthand(CSSPropertyID::kBackground, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// background-position
class BackgroundPosition final : public Shorthand {
 public:
  constexpr BackgroundPosition() : Shorthand(CSSPropertyID::kBackgroundPosition, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// background-repeat
class BackgroundRepeat final : public Shorthand {
 public:
  constexpr BackgroundRepeat() : Shorthand(CSSPropertyID::kBackgroundRepeat, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border
class Border final : public Shorthand {
 public:
  constexpr Border() : Shorthand(CSSPropertyID::kBorder, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-block
class BorderBlock final : public Shorthand {
 public:
  constexpr BorderBlock() : Shorthand(CSSPropertyID::kBorderBlock, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-block-color
class BorderBlockColor final : public Shorthand {
 public:
  constexpr BorderBlockColor() : Shorthand(CSSPropertyID::kBorderBlockColor, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-block-end
class BorderBlockEnd final : public Shorthand {
 public:
  constexpr BorderBlockEnd() : Shorthand(CSSPropertyID::kBorderBlockEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
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
 };

// border-block-start
class BorderBlockStart final : public Shorthand {
 public:
  constexpr BorderBlockStart() : Shorthand(CSSPropertyID::kBorderBlockStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
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
 };

// border-block-style
class BorderBlockStyle final : public Shorthand {
 public:
  constexpr BorderBlockStyle() : Shorthand(CSSPropertyID::kBorderBlockStyle, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-block-width
class BorderBlockWidth final : public Shorthand {
 public:
  constexpr BorderBlockWidth() : Shorthand(CSSPropertyID::kBorderBlockWidth, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-bottom
class BorderBottom final : public Shorthand {
 public:
  constexpr BorderBottom() : Shorthand(CSSPropertyID::kBorderBottom, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-color
class BorderColor final : public Shorthand {
 public:
  constexpr BorderColor() : Shorthand(CSSPropertyID::kBorderColor, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-image
class BorderImage final : public Shorthand {
 public:
  constexpr BorderImage() : Shorthand(CSSPropertyID::kBorderImage, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-inline
class BorderInline final : public Shorthand {
 public:
  constexpr BorderInline() : Shorthand(CSSPropertyID::kBorderInline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-inline-color
class BorderInlineColor final : public Shorthand {
 public:
  constexpr BorderInlineColor() : Shorthand(CSSPropertyID::kBorderInlineColor, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-inline-end
class BorderInlineEnd final : public Shorthand {
 public:
  constexpr BorderInlineEnd() : Shorthand(CSSPropertyID::kBorderInlineEnd, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
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
 };

// border-inline-start
class BorderInlineStart final : public Shorthand {
 public:
  constexpr BorderInlineStart() : Shorthand(CSSPropertyID::kBorderInlineStart, kProperty | kSurrogate, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  const CSSProperty* SurrogateFor(TextDirection, blink::WritingMode) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
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
 };

// border-inline-style
class BorderInlineStyle final : public Shorthand {
 public:
  constexpr BorderInlineStyle() : Shorthand(CSSPropertyID::kBorderInlineStyle, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-inline-width
class BorderInlineWidth final : public Shorthand {
 public:
  constexpr BorderInlineWidth() : Shorthand(CSSPropertyID::kBorderInlineWidth, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-left
class BorderLeft final : public Shorthand {
 public:
  constexpr BorderLeft() : Shorthand(CSSPropertyID::kBorderLeft, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-radius
class BorderRadius final : public Shorthand {
 public:
  constexpr BorderRadius() : Shorthand(CSSPropertyID::kBorderRadius, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-right
class BorderRight final : public Shorthand {
 public:
  constexpr BorderRight() : Shorthand(CSSPropertyID::kBorderRight, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-spacing
class BorderSpacing final : public Shorthand {
 public:
  constexpr BorderSpacing() : Shorthand(CSSPropertyID::kBorderSpacing, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-style
class BorderStyle final : public Shorthand {
 public:
  constexpr BorderStyle() : Shorthand(CSSPropertyID::kBorderStyle, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-top
class BorderTop final : public Shorthand {
 public:
  constexpr BorderTop() : Shorthand(CSSPropertyID::kBorderTop, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// border-width
class BorderWidth final : public Shorthand {
 public:
  constexpr BorderWidth() : Shorthand(CSSPropertyID::kBorderWidth, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// column-rule
class ColumnRule final : public Shorthand {
 public:
  constexpr ColumnRule() : Shorthand(CSSPropertyID::kColumnRule, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// columns
class Columns final : public Shorthand {
 public:
  constexpr Columns() : Shorthand(CSSPropertyID::kColumns, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// flex
class Flex final : public Shorthand {
 public:
  constexpr Flex() : Shorthand(CSSPropertyID::kFlex, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// flex-flow
class FlexFlow final : public Shorthand {
 public:
  constexpr FlexFlow() : Shorthand(CSSPropertyID::kFlexFlow, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// font
class Font final : public Shorthand {
 public:
  constexpr Font() : Shorthand(CSSPropertyID::kFont, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// font-variant
class FontVariant final : public Shorthand {
 public:
  constexpr FontVariant() : Shorthand(CSSPropertyID::kFontVariant, kDescriptor | kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// gap
class Gap final : public Shorthand {
 public:
  constexpr Gap() : Shorthand(CSSPropertyID::kGap, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid
class Grid final : public Shorthand {
 public:
  constexpr Grid() : Shorthand(CSSPropertyID::kGrid, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-area
class GridArea final : public Shorthand {
 public:
  constexpr GridArea() : Shorthand(CSSPropertyID::kGridArea, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-column
class GridColumn final : public Shorthand {
 public:
  constexpr GridColumn() : Shorthand(CSSPropertyID::kGridColumn, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-column-gap
class GridColumnGap final : public Shorthand {
 public:
  constexpr GridColumnGap() : Shorthand(CSSPropertyID::kGridColumnGap, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-gap
class GridGap final : public Shorthand {
 public:
  constexpr GridGap() : Shorthand(CSSPropertyID::kGridGap, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-row
class GridRow final : public Shorthand {
 public:
  constexpr GridRow() : Shorthand(CSSPropertyID::kGridRow, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-row-gap
class GridRowGap final : public Shorthand {
 public:
  constexpr GridRowGap() : Shorthand(CSSPropertyID::kGridRowGap, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// grid-template
class GridTemplate final : public Shorthand {
 public:
  constexpr GridTemplate() : Shorthand(CSSPropertyID::kGridTemplate, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// inset
class Inset final : public Shorthand {
 public:
  constexpr Inset() : Shorthand(CSSPropertyID::kInset, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// inset-block
class InsetBlock final : public Shorthand {
 public:
  constexpr InsetBlock() : Shorthand(CSSPropertyID::kInsetBlock, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// inset-inline
class InsetInline final : public Shorthand {
 public:
  constexpr InsetInline() : Shorthand(CSSPropertyID::kInsetInline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// list-style
class ListStyle final : public Shorthand {
 public:
  constexpr ListStyle() : Shorthand(CSSPropertyID::kListStyle, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// margin
class Margin final : public Shorthand {
 public:
  constexpr Margin() : Shorthand(CSSPropertyID::kMargin, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// margin-block
class MarginBlock final : public Shorthand {
 public:
  constexpr MarginBlock() : Shorthand(CSSPropertyID::kMarginBlock, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// margin-inline
class MarginInline final : public Shorthand {
 public:
  constexpr MarginInline() : Shorthand(CSSPropertyID::kMarginInline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// marker
class Marker final : public Shorthand {
 public:
  constexpr Marker() : Shorthand(CSSPropertyID::kMarker, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// offset
class Offset final : public Shorthand {
 public:
  constexpr Offset() : Shorthand(CSSPropertyID::kOffset, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// outline
class Outline final : public Shorthand {
 public:
  constexpr Outline() : Shorthand(CSSPropertyID::kOutline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// overflow
class Overflow final : public Shorthand {
 public:
  constexpr Overflow() : Shorthand(CSSPropertyID::kOverflow, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// overscroll-behavior
class OverscrollBehavior final : public Shorthand {
 public:
  constexpr OverscrollBehavior() : Shorthand(CSSPropertyID::kOverscrollBehavior, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// padding
class Padding final : public Shorthand {
 public:
  constexpr Padding() : Shorthand(CSSPropertyID::kPadding, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool IsLayoutDependentProperty() const override { return true; }
  bool IsLayoutDependent(const ComputedStyle*, LayoutObject*) const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// padding-block
class PaddingBlock final : public Shorthand {
 public:
  constexpr PaddingBlock() : Shorthand(CSSPropertyID::kPaddingBlock, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// padding-inline
class PaddingInline final : public Shorthand {
 public:
  constexpr PaddingInline() : Shorthand(CSSPropertyID::kPaddingInline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  CSSExposure Exposure() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// page-break-after
class PageBreakAfter final : public Shorthand {
 public:
  constexpr PageBreakAfter() : Shorthand(CSSPropertyID::kPageBreakAfter, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// page-break-before
class PageBreakBefore final : public Shorthand {
 public:
  constexpr PageBreakBefore() : Shorthand(CSSPropertyID::kPageBreakBefore, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// page-break-inside
class PageBreakInside final : public Shorthand {
 public:
  constexpr PageBreakInside() : Shorthand(CSSPropertyID::kPageBreakInside, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// place-content
class PlaceContent final : public Shorthand {
 public:
  constexpr PlaceContent() : Shorthand(CSSPropertyID::kPlaceContent, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// place-items
class PlaceItems final : public Shorthand {
 public:
  constexpr PlaceItems() : Shorthand(CSSPropertyID::kPlaceItems, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// place-self
class PlaceSelf final : public Shorthand {
 public:
  constexpr PlaceSelf() : Shorthand(CSSPropertyID::kPlaceSelf, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// scroll-margin
class ScrollMargin final : public Shorthand {
 public:
  constexpr ScrollMargin() : Shorthand(CSSPropertyID::kScrollMargin, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// scroll-margin-block
class ScrollMarginBlock final : public Shorthand {
 public:
  constexpr ScrollMarginBlock() : Shorthand(CSSPropertyID::kScrollMarginBlock, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// scroll-margin-inline
class ScrollMarginInline final : public Shorthand {
 public:
  constexpr ScrollMarginInline() : Shorthand(CSSPropertyID::kScrollMarginInline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// scroll-padding
class ScrollPadding final : public Shorthand {
 public:
  constexpr ScrollPadding() : Shorthand(CSSPropertyID::kScrollPadding, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// scroll-padding-block
class ScrollPaddingBlock final : public Shorthand {
 public:
  constexpr ScrollPaddingBlock() : Shorthand(CSSPropertyID::kScrollPaddingBlock, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// scroll-padding-inline
class ScrollPaddingInline final : public Shorthand {
 public:
  constexpr ScrollPaddingInline() : Shorthand(CSSPropertyID::kScrollPaddingInline, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// text-decoration
class TextDecoration final : public Shorthand {
 public:
  constexpr TextDecoration() : Shorthand(CSSPropertyID::kTextDecoration, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// transition
class Transition final : public Shorthand {
 public:
  constexpr Transition() : Shorthand(CSSPropertyID::kTransition, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-column-break-after
class WebkitColumnBreakAfter final : public Shorthand {
 public:
  constexpr WebkitColumnBreakAfter() : Shorthand(CSSPropertyID::kWebkitColumnBreakAfter, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-column-break-before
class WebkitColumnBreakBefore final : public Shorthand {
 public:
  constexpr WebkitColumnBreakBefore() : Shorthand(CSSPropertyID::kWebkitColumnBreakBefore, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-column-break-inside
class WebkitColumnBreakInside final : public Shorthand {
 public:
  constexpr WebkitColumnBreakInside() : Shorthand(CSSPropertyID::kWebkitColumnBreakInside, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-mask
class WebkitMask final : public Shorthand {
 public:
  constexpr WebkitMask() : Shorthand(CSSPropertyID::kWebkitMask, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
 };

// -webkit-mask-box-image
class WebkitMaskBoxImage final : public Shorthand {
 public:
  constexpr WebkitMaskBoxImage() : Shorthand(CSSPropertyID::kWebkitMaskBoxImage, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-mask-position
class WebkitMaskPosition final : public Shorthand {
 public:
  constexpr WebkitMaskPosition() : Shorthand(CSSPropertyID::kWebkitMaskPosition, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-mask-repeat
class WebkitMaskRepeat final : public Shorthand {
 public:
  constexpr WebkitMaskRepeat() : Shorthand(CSSPropertyID::kWebkitMaskRepeat, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
  const CSSValue* CSSValueFromComputedStyleInternal(const ComputedStyle&, const SVGComputedStyle&, const LayoutObject*, bool allow_visited_style) const override;
 };

// -webkit-text-emphasis
class WebkitTextEmphasis final : public Shorthand {
 public:
  constexpr WebkitTextEmphasis() : Shorthand(CSSPropertyID::kWebkitTextEmphasis, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
 };

// -webkit-text-stroke
class WebkitTextStroke final : public Shorthand {
 public:
  constexpr WebkitTextStroke() : Shorthand(CSSPropertyID::kWebkitTextStroke, kProperty, '\0') { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
  bool ParseShorthand(bool, CSSParserTokenRange&, const CSSParserContext&, const CSSParserLocalContext&, HeapVector<CSSPropertyValue, 256>&) const override;
 };

// -webkit-border-after
class WebkitBorderAfter final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderAfter() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-before
class WebkitBorderBefore final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderBefore() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-end
class WebkitBorderEnd final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderEnd() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-start
class WebkitBorderStart final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderStart() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -epub-text-emphasis
class EpubTextEmphasis final : public CSSUnresolvedProperty {
 public:
  constexpr EpubTextEmphasis() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-animation
class WebkitAnimation final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitAnimation() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-border-radius
class WebkitBorderRadius final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitBorderRadius() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-column-rule
class WebkitColumnRule final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumnRule() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-columns
class WebkitColumns final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitColumns() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex
class WebkitFlex final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlex() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-flex-flow
class WebkitFlexFlow final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitFlexFlow() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

// -webkit-transition
class WebkitTransition final : public CSSUnresolvedProperty {
 public:
  constexpr WebkitTransition() : CSSUnresolvedProperty() { }
  const char* GetPropertyName() const override;
  const WTF::AtomicString& GetPropertyNameAtomicString() const override;
  const char* GetJSPropertyName() const override;
 };

 
}  // namespace css_shorthand
}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PROPERTIES_CSS_PROPERTIES_SHORTHANDS_H_
