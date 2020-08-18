/*
 * (C) 1999-2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2013 Intel Corporation. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

// Generated from template:
//   core/css/templates/style_property_shorthand.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5


#include "third_party/blink/renderer/core/style_property_shorthand.h"

#include "base/stl_util.h"  // for base::size()
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"


namespace blink {

const StylePropertyShorthand& animationShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyAnimationDuration(),
    &GetCSSPropertyAnimationTimingFunction(),
    &GetCSSPropertyAnimationDelay(),
    &GetCSSPropertyAnimationIterationCount(),
    &GetCSSPropertyAnimationDirection(),
    &GetCSSPropertyAnimationFillMode(),
    &GetCSSPropertyAnimationPlayState(),
    &GetCSSPropertyAnimationName(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kAnimation, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& backgroundShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBackgroundImage(),
    &GetCSSPropertyBackgroundPositionX(),
    &GetCSSPropertyBackgroundPositionY(),
    &GetCSSPropertyBackgroundSize(),
    &GetCSSPropertyBackgroundRepeatX(),
    &GetCSSPropertyBackgroundRepeatY(),
    &GetCSSPropertyBackgroundAttachment(),
    &GetCSSPropertyBackgroundOrigin(),
    &GetCSSPropertyBackgroundClip(),
    &GetCSSPropertyBackgroundColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBackground, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& backgroundPositionShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBackgroundPositionX(),
    &GetCSSPropertyBackgroundPositionY(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBackgroundPosition, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& backgroundRepeatShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBackgroundRepeatX(),
    &GetCSSPropertyBackgroundRepeatY(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBackgroundRepeat, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderTopColor(),
    &GetCSSPropertyBorderTopStyle(),
    &GetCSSPropertyBorderTopWidth(),
    &GetCSSPropertyBorderRightColor(),
    &GetCSSPropertyBorderRightStyle(),
    &GetCSSPropertyBorderRightWidth(),
    &GetCSSPropertyBorderBottomColor(),
    &GetCSSPropertyBorderBottomStyle(),
    &GetCSSPropertyBorderBottomWidth(),
    &GetCSSPropertyBorderLeftColor(),
    &GetCSSPropertyBorderLeftStyle(),
    &GetCSSPropertyBorderLeftWidth(),
    &GetCSSPropertyBorderImageSource(),
    &GetCSSPropertyBorderImageSlice(),
    &GetCSSPropertyBorderImageWidth(),
    &GetCSSPropertyBorderImageOutset(),
    &GetCSSPropertyBorderImageRepeat(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorder, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBlockShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBlockStartColor(),
    &GetCSSPropertyBorderBlockStartStyle(),
    &GetCSSPropertyBorderBlockStartWidth(),
    &GetCSSPropertyBorderBlockEndColor(),
    &GetCSSPropertyBorderBlockEndStyle(),
    &GetCSSPropertyBorderBlockEndWidth(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBlock, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBlockColorShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBlockStartColor(),
    &GetCSSPropertyBorderBlockEndColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBlockColor, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBlockEndShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBlockEndWidth(),
    &GetCSSPropertyBorderBlockEndStyle(),
    &GetCSSPropertyBorderBlockEndColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBlockEnd, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBlockStartShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBlockStartWidth(),
    &GetCSSPropertyBorderBlockStartStyle(),
    &GetCSSPropertyBorderBlockStartColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBlockStart, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBlockStyleShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBlockStartStyle(),
    &GetCSSPropertyBorderBlockEndStyle(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBlockStyle, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBlockWidthShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBlockStartWidth(),
    &GetCSSPropertyBorderBlockEndWidth(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBlockWidth, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderBottomShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderBottomWidth(),
    &GetCSSPropertyBorderBottomStyle(),
    &GetCSSPropertyBorderBottomColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderBottom, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderColorShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderTopColor(),
    &GetCSSPropertyBorderRightColor(),
    &GetCSSPropertyBorderBottomColor(),
    &GetCSSPropertyBorderLeftColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderColor, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderImageShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderImageSource(),
    &GetCSSPropertyBorderImageSlice(),
    &GetCSSPropertyBorderImageWidth(),
    &GetCSSPropertyBorderImageOutset(),
    &GetCSSPropertyBorderImageRepeat(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderImage, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderInlineShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderInlineStartColor(),
    &GetCSSPropertyBorderInlineStartStyle(),
    &GetCSSPropertyBorderInlineStartWidth(),
    &GetCSSPropertyBorderInlineEndColor(),
    &GetCSSPropertyBorderInlineEndStyle(),
    &GetCSSPropertyBorderInlineEndWidth(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderInline, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderInlineColorShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderInlineStartColor(),
    &GetCSSPropertyBorderInlineEndColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderInlineColor, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderInlineEndShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderInlineEndWidth(),
    &GetCSSPropertyBorderInlineEndStyle(),
    &GetCSSPropertyBorderInlineEndColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderInlineEnd, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderInlineStartShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderInlineStartWidth(),
    &GetCSSPropertyBorderInlineStartStyle(),
    &GetCSSPropertyBorderInlineStartColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderInlineStart, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderInlineStyleShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderInlineStartStyle(),
    &GetCSSPropertyBorderInlineEndStyle(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderInlineStyle, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderInlineWidthShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderInlineStartWidth(),
    &GetCSSPropertyBorderInlineEndWidth(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderInlineWidth, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderLeftShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderLeftWidth(),
    &GetCSSPropertyBorderLeftStyle(),
    &GetCSSPropertyBorderLeftColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderLeft, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderRadiusShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderTopLeftRadius(),
    &GetCSSPropertyBorderTopRightRadius(),
    &GetCSSPropertyBorderBottomRightRadius(),
    &GetCSSPropertyBorderBottomLeftRadius(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderRadius, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderRightShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderRightWidth(),
    &GetCSSPropertyBorderRightStyle(),
    &GetCSSPropertyBorderRightColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderRight, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderSpacingShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitBorderHorizontalSpacing(),
    &GetCSSPropertyWebkitBorderVerticalSpacing(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderSpacing, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderStyleShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderTopStyle(),
    &GetCSSPropertyBorderRightStyle(),
    &GetCSSPropertyBorderBottomStyle(),
    &GetCSSPropertyBorderLeftStyle(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderStyle, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderTopShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderTopWidth(),
    &GetCSSPropertyBorderTopStyle(),
    &GetCSSPropertyBorderTopColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderTop, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& borderWidthShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBorderTopWidth(),
    &GetCSSPropertyBorderRightWidth(),
    &GetCSSPropertyBorderBottomWidth(),
    &GetCSSPropertyBorderLeftWidth(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kBorderWidth, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& columnRuleShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyColumnRuleWidth(),
    &GetCSSPropertyColumnRuleStyle(),
    &GetCSSPropertyColumnRuleColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kColumnRule, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& columnsShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyColumnWidth(),
    &GetCSSPropertyColumnCount(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kColumns, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& flexShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyFlexGrow(),
    &GetCSSPropertyFlexShrink(),
    &GetCSSPropertyFlexBasis(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kFlex, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& flexFlowShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyFlexDirection(),
    &GetCSSPropertyFlexWrap(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kFlexFlow, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& fontShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyFontStyle(),
    &GetCSSPropertyFontVariantLigatures(),
    &GetCSSPropertyFontVariantCaps(),
    &GetCSSPropertyFontVariantNumeric(),
    &GetCSSPropertyFontVariantEastAsian(),
    &GetCSSPropertyFontWeight(),
    &GetCSSPropertyFontStretch(),
    &GetCSSPropertyFontSize(),
    &GetCSSPropertyLineHeight(),
    &GetCSSPropertyFontFamily(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kFont, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& fontVariantShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyFontVariantLigatures(),
    &GetCSSPropertyFontVariantCaps(),
    &GetCSSPropertyFontVariantNumeric(),
    &GetCSSPropertyFontVariantEastAsian(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kFontVariant, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gapShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyRowGap(),
    &GetCSSPropertyColumnGap(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGap, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyGridTemplateRows(),
    &GetCSSPropertyGridTemplateColumns(),
    &GetCSSPropertyGridTemplateAreas(),
    &GetCSSPropertyGridAutoFlow(),
    &GetCSSPropertyGridAutoRows(),
    &GetCSSPropertyGridAutoColumns(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGrid, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridAreaShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyGridRowStart(),
    &GetCSSPropertyGridColumnStart(),
    &GetCSSPropertyGridRowEnd(),
    &GetCSSPropertyGridColumnEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridArea, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridColumnShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyGridColumnStart(),
    &GetCSSPropertyGridColumnEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridColumn, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridColumnGapShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyColumnGap(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridColumnGap, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridGapShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyRowGap(),
    &GetCSSPropertyColumnGap(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridGap, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridRowShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyGridRowStart(),
    &GetCSSPropertyGridRowEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridRow, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridRowGapShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyRowGap(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridRowGap, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& gridTemplateShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyGridTemplateRows(),
    &GetCSSPropertyGridTemplateColumns(),
    &GetCSSPropertyGridTemplateAreas(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kGridTemplate, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& insetShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyTop(),
    &GetCSSPropertyRight(),
    &GetCSSPropertyBottom(),
    &GetCSSPropertyLeft(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kInset, longhands, base::size(longhands));
  return shorthand;
}

static const StylePropertyShorthand* insetBlockShorthand1() {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return nullptr;

  static const CSSProperty* longhands[] = {
    &GetCSSPropertyInsetBlockStart(),
    &GetCSSPropertyInsetBlockEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kInsetBlock, longhands, base::size(longhands));
  return &shorthand;
}

const StylePropertyShorthand& insetBlockShorthand() {
  if (const auto* s = insetBlockShorthand1())
    return *s;

  DCHECK(!RuntimeEnabledFeatures::CSSLogicalEnabled());

  static StylePropertyShorthand empty_shorthand;
  return empty_shorthand;
}

static const StylePropertyShorthand* insetInlineShorthand1() {
  if (!RuntimeEnabledFeatures::CSSLogicalEnabled())
    return nullptr;

  static const CSSProperty* longhands[] = {
    &GetCSSPropertyInsetInlineStart(),
    &GetCSSPropertyInsetInlineEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kInsetInline, longhands, base::size(longhands));
  return &shorthand;
}

const StylePropertyShorthand& insetInlineShorthand() {
  if (const auto* s = insetInlineShorthand1())
    return *s;

  DCHECK(!RuntimeEnabledFeatures::CSSLogicalEnabled());

  static StylePropertyShorthand empty_shorthand;
  return empty_shorthand;
}

const StylePropertyShorthand& listStyleShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyListStylePosition(),
    &GetCSSPropertyListStyleImage(),
    &GetCSSPropertyListStyleType(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kListStyle, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& marginShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyMarginTop(),
    &GetCSSPropertyMarginRight(),
    &GetCSSPropertyMarginBottom(),
    &GetCSSPropertyMarginLeft(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kMargin, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& marginBlockShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyMarginBlockStart(),
    &GetCSSPropertyMarginBlockEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kMarginBlock, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& marginInlineShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyMarginInlineStart(),
    &GetCSSPropertyMarginInlineEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kMarginInline, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& markerShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyMarkerStart(),
    &GetCSSPropertyMarkerMid(),
    &GetCSSPropertyMarkerEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kMarker, longhands, base::size(longhands));
  return shorthand;
}

static const StylePropertyShorthand* offsetShorthand1() {
  if (!RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled())
    return nullptr;

  static const CSSProperty* longhands[] = {
    &GetCSSPropertyOffsetPosition(),
    &GetCSSPropertyOffsetPath(),
    &GetCSSPropertyOffsetDistance(),
    &GetCSSPropertyOffsetRotate(),
    &GetCSSPropertyOffsetAnchor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kOffset, longhands, base::size(longhands));
  return &shorthand;
}

const StylePropertyShorthand& offsetShorthand() {
  if (const auto* s = offsetShorthand1())
    return *s;

  DCHECK(!RuntimeEnabledFeatures::CSSOffsetPositionAnchorEnabled());

  static const CSSProperty* longhands[] = {
    &GetCSSPropertyOffsetPath(),
    &GetCSSPropertyOffsetDistance(),
    &GetCSSPropertyOffsetRotate(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kOffset, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& outlineShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyOutlineColor(),
    &GetCSSPropertyOutlineStyle(),
    &GetCSSPropertyOutlineWidth(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kOutline, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& overflowShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyOverflowX(),
    &GetCSSPropertyOverflowY(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kOverflow, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& overscrollBehaviorShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyOverscrollBehaviorX(),
    &GetCSSPropertyOverscrollBehaviorY(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kOverscrollBehavior, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& paddingShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyPaddingTop(),
    &GetCSSPropertyPaddingRight(),
    &GetCSSPropertyPaddingBottom(),
    &GetCSSPropertyPaddingLeft(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPadding, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& paddingBlockShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyPaddingBlockStart(),
    &GetCSSPropertyPaddingBlockEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPaddingBlock, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& paddingInlineShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyPaddingInlineStart(),
    &GetCSSPropertyPaddingInlineEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPaddingInline, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& pageBreakAfterShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBreakAfter(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPageBreakAfter, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& pageBreakBeforeShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBreakBefore(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPageBreakBefore, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& pageBreakInsideShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBreakInside(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPageBreakInside, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& placeContentShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyAlignContent(),
    &GetCSSPropertyJustifyContent(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPlaceContent, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& placeItemsShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyAlignItems(),
    &GetCSSPropertyJustifyItems(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPlaceItems, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& placeSelfShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyAlignSelf(),
    &GetCSSPropertyJustifySelf(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kPlaceSelf, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& scrollMarginShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyScrollMarginTop(),
    &GetCSSPropertyScrollMarginRight(),
    &GetCSSPropertyScrollMarginBottom(),
    &GetCSSPropertyScrollMarginLeft(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kScrollMargin, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& scrollMarginBlockShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyScrollMarginBlockStart(),
    &GetCSSPropertyScrollMarginBlockEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kScrollMarginBlock, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& scrollMarginInlineShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyScrollMarginInlineStart(),
    &GetCSSPropertyScrollMarginInlineEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kScrollMarginInline, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& scrollPaddingShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyScrollPaddingTop(),
    &GetCSSPropertyScrollPaddingRight(),
    &GetCSSPropertyScrollPaddingBottom(),
    &GetCSSPropertyScrollPaddingLeft(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kScrollPadding, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& scrollPaddingBlockShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyScrollPaddingBlockStart(),
    &GetCSSPropertyScrollPaddingBlockEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kScrollPaddingBlock, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& scrollPaddingInlineShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyScrollPaddingInlineStart(),
    &GetCSSPropertyScrollPaddingInlineEnd(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kScrollPaddingInline, longhands, base::size(longhands));
  return shorthand;
}

static const StylePropertyShorthand* textDecorationShorthand1() {
  if (!RuntimeEnabledFeatures::UnderlineOffsetThicknessEnabled())
    return nullptr;

  static const CSSProperty* longhands[] = {
    &GetCSSPropertyTextDecorationLine(),
    &GetCSSPropertyTextDecorationThickness(),
    &GetCSSPropertyTextDecorationStyle(),
    &GetCSSPropertyTextDecorationColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kTextDecoration, longhands, base::size(longhands));
  return &shorthand;
}

const StylePropertyShorthand& textDecorationShorthand() {
  if (const auto* s = textDecorationShorthand1())
    return *s;

  DCHECK(!RuntimeEnabledFeatures::UnderlineOffsetThicknessEnabled());

  static const CSSProperty* longhands[] = {
    &GetCSSPropertyTextDecorationLine(),
    &GetCSSPropertyTextDecorationStyle(),
    &GetCSSPropertyTextDecorationColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kTextDecoration, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& transitionShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyTransitionProperty(),
    &GetCSSPropertyTransitionDuration(),
    &GetCSSPropertyTransitionTimingFunction(),
    &GetCSSPropertyTransitionDelay(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kTransition, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitColumnBreakAfterShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBreakAfter(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitColumnBreakAfter, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitColumnBreakBeforeShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBreakBefore(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitColumnBreakBefore, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitColumnBreakInsideShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyBreakInside(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitColumnBreakInside, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitMaskShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitMaskImage(),
    &GetCSSPropertyWebkitMaskPositionX(),
    &GetCSSPropertyWebkitMaskPositionY(),
    &GetCSSPropertyWebkitMaskSize(),
    &GetCSSPropertyWebkitMaskRepeatX(),
    &GetCSSPropertyWebkitMaskRepeatY(),
    &GetCSSPropertyWebkitMaskOrigin(),
    &GetCSSPropertyWebkitMaskClip(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitMask, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitMaskBoxImageShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitMaskBoxImageSource(),
    &GetCSSPropertyWebkitMaskBoxImageSlice(),
    &GetCSSPropertyWebkitMaskBoxImageWidth(),
    &GetCSSPropertyWebkitMaskBoxImageOutset(),
    &GetCSSPropertyWebkitMaskBoxImageRepeat(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitMaskBoxImage, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitMaskPositionShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitMaskPositionX(),
    &GetCSSPropertyWebkitMaskPositionY(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitMaskPosition, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitMaskRepeatShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitMaskRepeatX(),
    &GetCSSPropertyWebkitMaskRepeatY(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitMaskRepeat, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitTextEmphasisShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitTextEmphasisStyle(),
    &GetCSSPropertyWebkitTextEmphasisColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitTextEmphasis, longhands, base::size(longhands));
  return shorthand;
}

const StylePropertyShorthand& webkitTextStrokeShorthand() {
  static const CSSProperty* longhands[] = {
    &GetCSSPropertyWebkitTextStrokeWidth(),
    &GetCSSPropertyWebkitTextStrokeColor(),
  };

  static const StylePropertyShorthand shorthand(
      CSSPropertyID::kWebkitTextStroke, longhands, base::size(longhands));
  return shorthand;
}

// Returns an empty list if the property is not a shorthand
const StylePropertyShorthand& shorthandForProperty(CSSPropertyID propertyID) {
  // FIXME: We shouldn't switch between shorthand/not shorthand based on a runtime flag
  static StylePropertyShorthand empty_shorthand;

  switch (propertyID) {
    case CSSPropertyID::kAnimation:
      return animationShorthand();
    case CSSPropertyID::kBackground:
      return backgroundShorthand();
    case CSSPropertyID::kBackgroundPosition:
      return backgroundPositionShorthand();
    case CSSPropertyID::kBackgroundRepeat:
      return backgroundRepeatShorthand();
    case CSSPropertyID::kBorder:
      return borderShorthand();
    case CSSPropertyID::kBorderBlock:
      return borderBlockShorthand();
    case CSSPropertyID::kBorderBlockColor:
      return borderBlockColorShorthand();
    case CSSPropertyID::kBorderBlockEnd:
      return borderBlockEndShorthand();
    case CSSPropertyID::kBorderBlockStart:
      return borderBlockStartShorthand();
    case CSSPropertyID::kBorderBlockStyle:
      return borderBlockStyleShorthand();
    case CSSPropertyID::kBorderBlockWidth:
      return borderBlockWidthShorthand();
    case CSSPropertyID::kBorderBottom:
      return borderBottomShorthand();
    case CSSPropertyID::kBorderColor:
      return borderColorShorthand();
    case CSSPropertyID::kBorderImage:
      return borderImageShorthand();
    case CSSPropertyID::kBorderInline:
      return borderInlineShorthand();
    case CSSPropertyID::kBorderInlineColor:
      return borderInlineColorShorthand();
    case CSSPropertyID::kBorderInlineEnd:
      return borderInlineEndShorthand();
    case CSSPropertyID::kBorderInlineStart:
      return borderInlineStartShorthand();
    case CSSPropertyID::kBorderInlineStyle:
      return borderInlineStyleShorthand();
    case CSSPropertyID::kBorderInlineWidth:
      return borderInlineWidthShorthand();
    case CSSPropertyID::kBorderLeft:
      return borderLeftShorthand();
    case CSSPropertyID::kBorderRadius:
      return borderRadiusShorthand();
    case CSSPropertyID::kBorderRight:
      return borderRightShorthand();
    case CSSPropertyID::kBorderSpacing:
      return borderSpacingShorthand();
    case CSSPropertyID::kBorderStyle:
      return borderStyleShorthand();
    case CSSPropertyID::kBorderTop:
      return borderTopShorthand();
    case CSSPropertyID::kBorderWidth:
      return borderWidthShorthand();
    case CSSPropertyID::kColumnRule:
      return columnRuleShorthand();
    case CSSPropertyID::kColumns:
      return columnsShorthand();
    case CSSPropertyID::kFlex:
      return flexShorthand();
    case CSSPropertyID::kFlexFlow:
      return flexFlowShorthand();
    case CSSPropertyID::kFont:
      return fontShorthand();
    case CSSPropertyID::kFontVariant:
      return fontVariantShorthand();
    case CSSPropertyID::kGap:
      return gapShorthand();
    case CSSPropertyID::kGrid:
      return gridShorthand();
    case CSSPropertyID::kGridArea:
      return gridAreaShorthand();
    case CSSPropertyID::kGridColumn:
      return gridColumnShorthand();
    case CSSPropertyID::kGridColumnGap:
      return gridColumnGapShorthand();
    case CSSPropertyID::kGridGap:
      return gridGapShorthand();
    case CSSPropertyID::kGridRow:
      return gridRowShorthand();
    case CSSPropertyID::kGridRowGap:
      return gridRowGapShorthand();
    case CSSPropertyID::kGridTemplate:
      return gridTemplateShorthand();
    case CSSPropertyID::kInset:
      return insetShorthand();
    case CSSPropertyID::kInsetBlock:
      return insetBlockShorthand();
    case CSSPropertyID::kInsetInline:
      return insetInlineShorthand();
    case CSSPropertyID::kListStyle:
      return listStyleShorthand();
    case CSSPropertyID::kMargin:
      return marginShorthand();
    case CSSPropertyID::kMarginBlock:
      return marginBlockShorthand();
    case CSSPropertyID::kMarginInline:
      return marginInlineShorthand();
    case CSSPropertyID::kMarker:
      return markerShorthand();
    case CSSPropertyID::kOffset:
      return offsetShorthand();
    case CSSPropertyID::kOutline:
      return outlineShorthand();
    case CSSPropertyID::kOverflow:
      return overflowShorthand();
    case CSSPropertyID::kOverscrollBehavior:
      return overscrollBehaviorShorthand();
    case CSSPropertyID::kPadding:
      return paddingShorthand();
    case CSSPropertyID::kPaddingBlock:
      return paddingBlockShorthand();
    case CSSPropertyID::kPaddingInline:
      return paddingInlineShorthand();
    case CSSPropertyID::kPageBreakAfter:
      return pageBreakAfterShorthand();
    case CSSPropertyID::kPageBreakBefore:
      return pageBreakBeforeShorthand();
    case CSSPropertyID::kPageBreakInside:
      return pageBreakInsideShorthand();
    case CSSPropertyID::kPlaceContent:
      return placeContentShorthand();
    case CSSPropertyID::kPlaceItems:
      return placeItemsShorthand();
    case CSSPropertyID::kPlaceSelf:
      return placeSelfShorthand();
    case CSSPropertyID::kScrollMargin:
      return scrollMarginShorthand();
    case CSSPropertyID::kScrollMarginBlock:
      return scrollMarginBlockShorthand();
    case CSSPropertyID::kScrollMarginInline:
      return scrollMarginInlineShorthand();
    case CSSPropertyID::kScrollPadding:
      return scrollPaddingShorthand();
    case CSSPropertyID::kScrollPaddingBlock:
      return scrollPaddingBlockShorthand();
    case CSSPropertyID::kScrollPaddingInline:
      return scrollPaddingInlineShorthand();
    case CSSPropertyID::kTextDecoration:
      return textDecorationShorthand();
    case CSSPropertyID::kTransition:
      return transitionShorthand();
    case CSSPropertyID::kWebkitColumnBreakAfter:
      return webkitColumnBreakAfterShorthand();
    case CSSPropertyID::kWebkitColumnBreakBefore:
      return webkitColumnBreakBeforeShorthand();
    case CSSPropertyID::kWebkitColumnBreakInside:
      return webkitColumnBreakInsideShorthand();
    case CSSPropertyID::kWebkitMask:
      return webkitMaskShorthand();
    case CSSPropertyID::kWebkitMaskBoxImage:
      return webkitMaskBoxImageShorthand();
    case CSSPropertyID::kWebkitMaskPosition:
      return webkitMaskPositionShorthand();
    case CSSPropertyID::kWebkitMaskRepeat:
      return webkitMaskRepeatShorthand();
    case CSSPropertyID::kWebkitTextEmphasis:
      return webkitTextEmphasisShorthand();
    case CSSPropertyID::kWebkitTextStroke:
      return webkitTextStrokeShorthand();
    default: {
      return empty_shorthand;
    }
  }
}

void getMatchingShorthandsForLonghand(
    CSSPropertyID propertyID, Vector<StylePropertyShorthand, 4>* result) {
  DCHECK(!result->size());
  switch (propertyID) {
    case CSSPropertyID::kTop: {
      if (CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed())
        result->UncheckedAppend(insetShorthand());
      break;
    }
    case CSSPropertyID::kBorderBlockStartWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed())
        result->UncheckedAppend(borderBlockShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockStart).IsWebExposed())
        result->UncheckedAppend(borderBlockStartShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockWidth).IsWebExposed())
        result->UncheckedAppend(borderBlockWidthShorthand());
      break;
    }
    case CSSPropertyID::kOutlineStyle: {
      if (CSSProperty::Get(CSSPropertyID::kOutline).IsWebExposed())
        result->UncheckedAppend(outlineShorthand());
      break;
    }
    case CSSPropertyID::kRowGap: {
      if (CSSProperty::Get(CSSPropertyID::kGap).IsWebExposed())
        result->UncheckedAppend(gapShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridGap).IsWebExposed())
        result->UncheckedAppend(gridGapShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridRowGap).IsWebExposed())
        result->UncheckedAppend(gridRowGapShorthand());
      break;
    }
    case CSSPropertyID::kAnimationDuration: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kBorderTopStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed())
        result->UncheckedAppend(borderStyleShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderTop).IsWebExposed())
        result->UncheckedAppend(borderTopShorthand());
      break;
    }
    case CSSPropertyID::kFontVariantNumeric: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      if (CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed())
        result->UncheckedAppend(fontVariantShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundRepeatX: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBackgroundRepeat).IsWebExposed())
        result->UncheckedAppend(backgroundRepeatShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundRepeatY: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBackgroundRepeat).IsWebExposed())
        result->UncheckedAppend(backgroundRepeatShorthand());
      break;
    }
    case CSSPropertyID::kFontFamily: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      break;
    }
    case CSSPropertyID::kBorderBlockStartStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed())
        result->UncheckedAppend(borderBlockShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockStart).IsWebExposed())
        result->UncheckedAppend(borderBlockStartShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockStyle).IsWebExposed())
        result->UncheckedAppend(borderBlockStyleShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginInlineStart: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMarginInline).IsWebExposed())
        result->UncheckedAppend(scrollMarginInlineShorthand());
      break;
    }
    case CSSPropertyID::kBorderLeftStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed())
        result->UncheckedAppend(borderStyleShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderLeft).IsWebExposed())
        result->UncheckedAppend(borderLeftShorthand());
      break;
    }
    case CSSPropertyID::kGridTemplateColumns: {
      if (CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed())
        result->UncheckedAppend(gridShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridTemplate).IsWebExposed())
        result->UncheckedAppend(gridTemplateShorthand());
      break;
    }
    case CSSPropertyID::kPaddingRight: {
      if (CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed())
        result->UncheckedAppend(paddingShorthand());
      break;
    }
    case CSSPropertyID::kMarginRight: {
      if (CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed())
        result->UncheckedAppend(marginShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskClip: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      break;
    }
    case CSSPropertyID::kAnimationDirection: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kAnimationFillMode: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kWebkitBorderVerticalSpacing: {
      if (CSSProperty::Get(CSSPropertyID::kBorderSpacing).IsWebExposed())
        result->UncheckedAppend(borderSpacingShorthand());
      break;
    }
    case CSSPropertyID::kColumnRuleStyle: {
      if (CSSProperty::Get(CSSPropertyID::kColumnRule).IsWebExposed())
        result->UncheckedAppend(columnRuleShorthand());
      break;
    }
    case CSSPropertyID::kGridAutoFlow: {
      if (CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed())
        result->UncheckedAppend(gridShorthand());
      break;
    }
    case CSSPropertyID::kBorderBlockEndWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed())
        result->UncheckedAppend(borderBlockShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockEnd).IsWebExposed())
        result->UncheckedAppend(borderBlockEndShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockWidth).IsWebExposed())
        result->UncheckedAppend(borderBlockWidthShorthand());
      break;
    }
    case CSSPropertyID::kMarginBlockEnd: {
      if (CSSProperty::Get(CSSPropertyID::kMarginBlock).IsWebExposed())
        result->UncheckedAppend(marginBlockShorthand());
      break;
    }
    case CSSPropertyID::kTransitionTimingFunction: {
      if (CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed())
        result->UncheckedAppend(transitionShorthand());
      break;
    }
    case CSSPropertyID::kAlignSelf: {
      if (CSSProperty::Get(CSSPropertyID::kPlaceSelf).IsWebExposed())
        result->UncheckedAppend(placeSelfShorthand());
      break;
    }
    case CSSPropertyID::kMarginInlineEnd: {
      if (CSSProperty::Get(CSSPropertyID::kMarginInline).IsWebExposed())
        result->UncheckedAppend(marginInlineShorthand());
      break;
    }
    case CSSPropertyID::kBorderBlockEndStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed())
        result->UncheckedAppend(borderBlockShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockEnd).IsWebExposed())
        result->UncheckedAppend(borderBlockEndShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockStyle).IsWebExposed())
        result->UncheckedAppend(borderBlockStyleShorthand());
      break;
    }
    case CSSPropertyID::kOffsetRotate: {
      if (CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed())
        result->UncheckedAppend(offsetShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingBlockEnd: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPaddingBlock).IsWebExposed())
        result->UncheckedAppend(scrollPaddingBlockShorthand());
      break;
    }
    case CSSPropertyID::kBreakInside: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitColumnBreakInside).IsWebExposed())
        result->UncheckedAppend(webkitColumnBreakInsideShorthand());
      if (CSSProperty::Get(CSSPropertyID::kPageBreakInside).IsWebExposed())
        result->UncheckedAppend(pageBreakInsideShorthand());
      break;
    }
    case CSSPropertyID::kAnimationIterationCount: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kPaddingLeft: {
      if (CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed())
        result->UncheckedAppend(paddingShorthand());
      break;
    }
    case CSSPropertyID::kInsetInlineStart: {
      if (CSSProperty::Get(CSSPropertyID::kInsetInline).IsWebExposed())
        result->UncheckedAppend(insetInlineShorthand());
      break;
    }
    case CSSPropertyID::kBreakAfter: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitColumnBreakAfter).IsWebExposed())
        result->UncheckedAppend(webkitColumnBreakAfterShorthand());
      if (CSSProperty::Get(CSSPropertyID::kPageBreakAfter).IsWebExposed())
        result->UncheckedAppend(pageBreakAfterShorthand());
      break;
    }
    case CSSPropertyID::kAlignContent: {
      if (CSSProperty::Get(CSSPropertyID::kPlaceContent).IsWebExposed())
        result->UncheckedAppend(placeContentShorthand());
      break;
    }
    case CSSPropertyID::kBorderInlineStartStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed())
        result->UncheckedAppend(borderInlineShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineStart).IsWebExposed())
        result->UncheckedAppend(borderInlineStartShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineStyle).IsWebExposed())
        result->UncheckedAppend(borderInlineStyleShorthand());
      break;
    }
    case CSSPropertyID::kWebkitTextEmphasisStyle: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitTextEmphasis).IsWebExposed())
        result->UncheckedAppend(webkitTextEmphasisShorthand());
      break;
    }
    case CSSPropertyID::kBorderImageSlice: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed())
        result->UncheckedAppend(borderImageShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginBlockStart: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMarginBlock).IsWebExposed())
        result->UncheckedAppend(scrollMarginBlockShorthand());
      break;
    }
    case CSSPropertyID::kBorderRightWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed())
        result->UncheckedAppend(borderWidthShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderRight).IsWebExposed())
        result->UncheckedAppend(borderRightShorthand());
      break;
    }
    case CSSPropertyID::kAnimationDelay: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundClip: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      break;
    }
    case CSSPropertyID::kPaddingBottom: {
      if (CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed())
        result->UncheckedAppend(paddingShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingInlineStart: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPaddingInline).IsWebExposed())
        result->UncheckedAppend(scrollPaddingInlineShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingLeft: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed())
        result->UncheckedAppend(scrollPaddingShorthand());
      break;
    }
    case CSSPropertyID::kColumnWidth: {
      if (CSSProperty::Get(CSSPropertyID::kColumns).IsWebExposed())
        result->UncheckedAppend(columnsShorthand());
      break;
    }
    case CSSPropertyID::kOutlineWidth: {
      if (CSSProperty::Get(CSSPropertyID::kOutline).IsWebExposed())
        result->UncheckedAppend(outlineShorthand());
      break;
    }
    case CSSPropertyID::kMarkerStart: {
      if (CSSProperty::Get(CSSPropertyID::kMarker).IsWebExposed())
        result->UncheckedAppend(markerShorthand());
      break;
    }
    case CSSPropertyID::kAnimationName: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kGridColumnEnd: {
      if (CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed())
        result->UncheckedAppend(gridAreaShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridColumn).IsWebExposed())
        result->UncheckedAppend(gridColumnShorthand());
      break;
    }
    case CSSPropertyID::kFontSize: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      break;
    }
    case CSSPropertyID::kPaddingInlineEnd: {
      if (CSSProperty::Get(CSSPropertyID::kPaddingInline).IsWebExposed())
        result->UncheckedAppend(paddingInlineShorthand());
      break;
    }
    case CSSPropertyID::kBorderBlockEndColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed())
        result->UncheckedAppend(borderBlockShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockEnd).IsWebExposed())
        result->UncheckedAppend(borderBlockEndShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockColor).IsWebExposed())
        result->UncheckedAppend(borderBlockColorShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginTop: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed())
        result->UncheckedAppend(scrollMarginShorthand());
      break;
    }
    case CSSPropertyID::kPaddingTop: {
      if (CSSProperty::Get(CSSPropertyID::kPadding).IsWebExposed())
        result->UncheckedAppend(paddingShorthand());
      break;
    }
    case CSSPropertyID::kMarginBlockStart: {
      if (CSSProperty::Get(CSSPropertyID::kMarginBlock).IsWebExposed())
        result->UncheckedAppend(marginBlockShorthand());
      break;
    }
    case CSSPropertyID::kLineHeight: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundAttachment: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageSlice: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed())
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
      break;
    }
    case CSSPropertyID::kAnimationTimingFunction: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kGridColumnStart: {
      if (CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed())
        result->UncheckedAppend(gridAreaShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridColumn).IsWebExposed())
        result->UncheckedAppend(gridColumnShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingBottom: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed())
        result->UncheckedAppend(scrollPaddingShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskRepeatX: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskRepeat).IsWebExposed())
        result->UncheckedAppend(webkitMaskRepeatShorthand());
      break;
    }
    case CSSPropertyID::kTransitionDuration: {
      if (CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed())
        result->UncheckedAppend(transitionShorthand());
      break;
    }
    case CSSPropertyID::kFontVariantCaps: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      if (CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed())
        result->UncheckedAppend(fontVariantShorthand());
      break;
    }
    case CSSPropertyID::kListStylePosition: {
      if (CSSProperty::Get(CSSPropertyID::kListStyle).IsWebExposed())
        result->UncheckedAppend(listStyleShorthand());
      break;
    }
    case CSSPropertyID::kBorderBlockStartColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorderBlock).IsWebExposed())
        result->UncheckedAppend(borderBlockShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockStart).IsWebExposed())
        result->UncheckedAppend(borderBlockStartShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBlockColor).IsWebExposed())
        result->UncheckedAppend(borderBlockColorShorthand());
      break;
    }
    case CSSPropertyID::kBorderTopWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed())
        result->UncheckedAppend(borderWidthShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderTop).IsWebExposed())
        result->UncheckedAppend(borderTopShorthand());
      break;
    }
    case CSSPropertyID::kBorderLeftColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed())
        result->UncheckedAppend(borderColorShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderLeft).IsWebExposed())
        result->UncheckedAppend(borderLeftShorthand());
      break;
    }
    case CSSPropertyID::kOverflowY: {
      if (CSSProperty::Get(CSSPropertyID::kOverflow).IsWebExposed())
        result->UncheckedAppend(overflowShorthand());
      break;
    }
    case CSSPropertyID::kOverflowX: {
      if (CSSProperty::Get(CSSPropertyID::kOverflow).IsWebExposed())
        result->UncheckedAppend(overflowShorthand());
      break;
    }
    case CSSPropertyID::kRight: {
      if (CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed())
        result->UncheckedAppend(insetShorthand());
      break;
    }
    case CSSPropertyID::kAnimationPlayState: {
      if (CSSProperty::Get(CSSPropertyID::kAnimation).IsWebExposed())
        result->UncheckedAppend(animationShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundColor: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      break;
    }
    case CSSPropertyID::kFlexWrap: {
      if (CSSProperty::Get(CSSPropertyID::kFlexFlow).IsWebExposed())
        result->UncheckedAppend(flexFlowShorthand());
      break;
    }
    case CSSPropertyID::kGridRowStart: {
      if (CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed())
        result->UncheckedAppend(gridAreaShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridRow).IsWebExposed())
        result->UncheckedAppend(gridRowShorthand());
      break;
    }
    case CSSPropertyID::kGridAutoColumns: {
      if (CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed())
        result->UncheckedAppend(gridShorthand());
      break;
    }
    case CSSPropertyID::kFlexGrow: {
      if (CSSProperty::Get(CSSPropertyID::kFlex).IsWebExposed())
        result->UncheckedAppend(flexShorthand());
      break;
    }
    case CSSPropertyID::kOffsetPosition: {
      if (CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed())
        result->UncheckedAppend(offsetShorthand());
      break;
    }
    case CSSPropertyID::kMarkerEnd: {
      if (CSSProperty::Get(CSSPropertyID::kMarker).IsWebExposed())
        result->UncheckedAppend(markerShorthand());
      break;
    }
    case CSSPropertyID::kBorderInlineEndWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed())
        result->UncheckedAppend(borderInlineShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineEnd).IsWebExposed())
        result->UncheckedAppend(borderInlineEndShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineWidth).IsWebExposed())
        result->UncheckedAppend(borderInlineWidthShorthand());
      break;
    }
    case CSSPropertyID::kMarginTop: {
      if (CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed())
        result->UncheckedAppend(marginShorthand());
      break;
    }
    case CSSPropertyID::kJustifyContent: {
      if (CSSProperty::Get(CSSPropertyID::kPlaceContent).IsWebExposed())
        result->UncheckedAppend(placeContentShorthand());
      break;
    }
    case CSSPropertyID::kListStyleType: {
      if (CSSProperty::Get(CSSPropertyID::kListStyle).IsWebExposed())
        result->UncheckedAppend(listStyleShorthand());
      break;
    }
    case CSSPropertyID::kBorderImageWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed())
        result->UncheckedAppend(borderImageShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingBlockStart: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPaddingBlock).IsWebExposed())
        result->UncheckedAppend(scrollPaddingBlockShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskImage: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      break;
    }
    case CSSPropertyID::kTextDecorationStyle: {
      if (CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed())
        result->UncheckedAppend(textDecorationShorthand());
      break;
    }
    case CSSPropertyID::kInsetBlockEnd: {
      if (CSSProperty::Get(CSSPropertyID::kInsetBlock).IsWebExposed())
        result->UncheckedAppend(insetBlockShorthand());
      break;
    }
    case CSSPropertyID::kInsetBlockStart: {
      if (CSSProperty::Get(CSSPropertyID::kInsetBlock).IsWebExposed())
        result->UncheckedAppend(insetBlockShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundImage: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      break;
    }
    case CSSPropertyID::kBorderInlineStartWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed())
        result->UncheckedAppend(borderInlineShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineStart).IsWebExposed())
        result->UncheckedAppend(borderInlineStartShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineWidth).IsWebExposed())
        result->UncheckedAppend(borderInlineWidthShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskOrigin: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageWidth: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed())
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
      break;
    }
    case CSSPropertyID::kJustifyItems: {
      if (CSSProperty::Get(CSSPropertyID::kPlaceItems).IsWebExposed())
        result->UncheckedAppend(placeItemsShorthand());
      break;
    }
    case CSSPropertyID::kBorderImageOutset: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed())
        result->UncheckedAppend(borderImageShorthand());
      break;
    }
    case CSSPropertyID::kTextDecorationThickness: {
      if (CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed())
        result->UncheckedAppend(textDecorationShorthand());
      break;
    }
    case CSSPropertyID::kBorderBottomRightRadius: {
      if (CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed())
        result->UncheckedAppend(borderRadiusShorthand());
      break;
    }
    case CSSPropertyID::kFlexShrink: {
      if (CSSProperty::Get(CSSPropertyID::kFlex).IsWebExposed())
        result->UncheckedAppend(flexShorthand());
      break;
    }
    case CSSPropertyID::kFontStretch: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      break;
    }
    case CSSPropertyID::kBorderImageRepeat: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed())
        result->UncheckedAppend(borderImageShorthand());
      break;
    }
    case CSSPropertyID::kFontWeight: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      break;
    }
    case CSSPropertyID::kFontVariantLigatures: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      if (CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed())
        result->UncheckedAppend(fontVariantShorthand());
      break;
    }
    case CSSPropertyID::kWebkitTextEmphasisColor: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitTextEmphasis).IsWebExposed())
        result->UncheckedAppend(webkitTextEmphasisShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingInlineEnd: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPaddingInline).IsWebExposed())
        result->UncheckedAppend(scrollPaddingInlineShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskRepeatY: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskRepeat).IsWebExposed())
        result->UncheckedAppend(webkitMaskRepeatShorthand());
      break;
    }
    case CSSPropertyID::kFontStyle: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginBottom: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed())
        result->UncheckedAppend(scrollMarginShorthand());
      break;
    }
    case CSSPropertyID::kMarkerMid: {
      if (CSSProperty::Get(CSSPropertyID::kMarker).IsWebExposed())
        result->UncheckedAppend(markerShorthand());
      break;
    }
    case CSSPropertyID::kAlignItems: {
      if (CSSProperty::Get(CSSPropertyID::kPlaceItems).IsWebExposed())
        result->UncheckedAppend(placeItemsShorthand());
      break;
    }
    case CSSPropertyID::kInsetInlineEnd: {
      if (CSSProperty::Get(CSSPropertyID::kInsetInline).IsWebExposed())
        result->UncheckedAppend(insetInlineShorthand());
      break;
    }
    case CSSPropertyID::kBorderBottomLeftRadius: {
      if (CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed())
        result->UncheckedAppend(borderRadiusShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginLeft: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed())
        result->UncheckedAppend(scrollMarginShorthand());
      break;
    }
    case CSSPropertyID::kBreakBefore: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitColumnBreakBefore).IsWebExposed())
        result->UncheckedAppend(webkitColumnBreakBeforeShorthand());
      if (CSSProperty::Get(CSSPropertyID::kPageBreakBefore).IsWebExposed())
        result->UncheckedAppend(pageBreakBeforeShorthand());
      break;
    }
    case CSSPropertyID::kBorderImageSource: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderImage).IsWebExposed())
        result->UncheckedAppend(borderImageShorthand());
      break;
    }
    case CSSPropertyID::kBorderRightStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed())
        result->UncheckedAppend(borderStyleShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderRight).IsWebExposed())
        result->UncheckedAppend(borderRightShorthand());
      break;
    }
    case CSSPropertyID::kLeft: {
      if (CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed())
        result->UncheckedAppend(insetShorthand());
      break;
    }
    case CSSPropertyID::kFontVariantEastAsian: {
      if (CSSProperty::Get(CSSPropertyID::kFont).IsWebExposed())
        result->UncheckedAppend(fontShorthand());
      if (CSSProperty::Get(CSSPropertyID::kFontVariant).IsWebExposed())
        result->UncheckedAppend(fontVariantShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundPositionX: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBackgroundPosition).IsWebExposed())
        result->UncheckedAppend(backgroundPositionShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundPositionY: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBackgroundPosition).IsWebExposed())
        result->UncheckedAppend(backgroundPositionShorthand());
      break;
    }
    case CSSPropertyID::kOffsetPath: {
      if (CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed())
        result->UncheckedAppend(offsetShorthand());
      break;
    }
    case CSSPropertyID::kTransitionDelay: {
      if (CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed())
        result->UncheckedAppend(transitionShorthand());
      break;
    }
    case CSSPropertyID::kColumnRuleWidth: {
      if (CSSProperty::Get(CSSPropertyID::kColumnRule).IsWebExposed())
        result->UncheckedAppend(columnRuleShorthand());
      break;
    }
    case CSSPropertyID::kOffsetAnchor: {
      if (CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed())
        result->UncheckedAppend(offsetShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageOutset: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed())
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
      break;
    }
    case CSSPropertyID::kGridAutoRows: {
      if (CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed())
        result->UncheckedAppend(gridShorthand());
      break;
    }
    case CSSPropertyID::kTextDecorationLine: {
      if (CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed())
        result->UncheckedAppend(textDecorationShorthand());
      break;
    }
    case CSSPropertyID::kTransitionProperty: {
      if (CSSProperty::Get(CSSPropertyID::kTransition).IsWebExposed())
        result->UncheckedAppend(transitionShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingTop: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed())
        result->UncheckedAppend(scrollPaddingShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskSize: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      break;
    }
    case CSSPropertyID::kGridRowEnd: {
      if (CSSProperty::Get(CSSPropertyID::kGridArea).IsWebExposed())
        result->UncheckedAppend(gridAreaShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridRow).IsWebExposed())
        result->UncheckedAppend(gridRowShorthand());
      break;
    }
    case CSSPropertyID::kPaddingInlineStart: {
      if (CSSProperty::Get(CSSPropertyID::kPaddingInline).IsWebExposed())
        result->UncheckedAppend(paddingInlineShorthand());
      break;
    }
    case CSSPropertyID::kGridTemplateAreas: {
      if (CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed())
        result->UncheckedAppend(gridShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridTemplate).IsWebExposed())
        result->UncheckedAppend(gridTemplateShorthand());
      break;
    }
    case CSSPropertyID::kBorderBottomStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderStyle).IsWebExposed())
        result->UncheckedAppend(borderStyleShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBottom).IsWebExposed())
        result->UncheckedAppend(borderBottomShorthand());
      break;
    }
    case CSSPropertyID::kPaddingBlockEnd: {
      if (CSSProperty::Get(CSSPropertyID::kPaddingBlock).IsWebExposed())
        result->UncheckedAppend(paddingBlockShorthand());
      break;
    }
    case CSSPropertyID::kFlexBasis: {
      if (CSSProperty::Get(CSSPropertyID::kFlex).IsWebExposed())
        result->UncheckedAppend(flexShorthand());
      break;
    }
    case CSSPropertyID::kBorderTopRightRadius: {
      if (CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed())
        result->UncheckedAppend(borderRadiusShorthand());
      break;
    }
    case CSSPropertyID::kBorderInlineStartColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed())
        result->UncheckedAppend(borderInlineShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineStart).IsWebExposed())
        result->UncheckedAppend(borderInlineStartShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineColor).IsWebExposed())
        result->UncheckedAppend(borderInlineColorShorthand());
      break;
    }
    case CSSPropertyID::kBorderLeftWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed())
        result->UncheckedAppend(borderWidthShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderLeft).IsWebExposed())
        result->UncheckedAppend(borderLeftShorthand());
      break;
    }
    case CSSPropertyID::kBorderRightColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed())
        result->UncheckedAppend(borderColorShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderRight).IsWebExposed())
        result->UncheckedAppend(borderRightShorthand());
      break;
    }
    case CSSPropertyID::kTextDecorationColor: {
      if (CSSProperty::Get(CSSPropertyID::kTextDecoration).IsWebExposed())
        result->UncheckedAppend(textDecorationShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundOrigin: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      break;
    }
    case CSSPropertyID::kOverscrollBehaviorY: {
      if (CSSProperty::Get(CSSPropertyID::kOverscrollBehavior).IsWebExposed())
        result->UncheckedAppend(overscrollBehaviorShorthand());
      break;
    }
    case CSSPropertyID::kColumnCount: {
      if (CSSProperty::Get(CSSPropertyID::kColumns).IsWebExposed())
        result->UncheckedAppend(columnsShorthand());
      break;
    }
    case CSSPropertyID::kGridTemplateRows: {
      if (CSSProperty::Get(CSSPropertyID::kGrid).IsWebExposed())
        result->UncheckedAppend(gridShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridTemplate).IsWebExposed())
        result->UncheckedAppend(gridTemplateShorthand());
      break;
    }
    case CSSPropertyID::kPaddingBlockStart: {
      if (CSSProperty::Get(CSSPropertyID::kPaddingBlock).IsWebExposed())
        result->UncheckedAppend(paddingBlockShorthand());
      break;
    }
    case CSSPropertyID::kOffsetDistance: {
      if (CSSProperty::Get(CSSPropertyID::kOffset).IsWebExposed())
        result->UncheckedAppend(offsetShorthand());
      break;
    }
    case CSSPropertyID::kBorderBottomColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed())
        result->UncheckedAppend(borderColorShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBottom).IsWebExposed())
        result->UncheckedAppend(borderBottomShorthand());
      break;
    }
    case CSSPropertyID::kListStyleImage: {
      if (CSSProperty::Get(CSSPropertyID::kListStyle).IsWebExposed())
        result->UncheckedAppend(listStyleShorthand());
      break;
    }
    case CSSPropertyID::kBackgroundSize: {
      if (CSSProperty::Get(CSSPropertyID::kBackground).IsWebExposed())
        result->UncheckedAppend(backgroundShorthand());
      break;
    }
    case CSSPropertyID::kOutlineColor: {
      if (CSSProperty::Get(CSSPropertyID::kOutline).IsWebExposed())
        result->UncheckedAppend(outlineShorthand());
      break;
    }
    case CSSPropertyID::kFlexDirection: {
      if (CSSProperty::Get(CSSPropertyID::kFlexFlow).IsWebExposed())
        result->UncheckedAppend(flexFlowShorthand());
      break;
    }
    case CSSPropertyID::kMarginLeft: {
      if (CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed())
        result->UncheckedAppend(marginShorthand());
      break;
    }
    case CSSPropertyID::kMarginBottom: {
      if (CSSProperty::Get(CSSPropertyID::kMargin).IsWebExposed())
        result->UncheckedAppend(marginShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginRight: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMargin).IsWebExposed())
        result->UncheckedAppend(scrollMarginShorthand());
      break;
    }
    case CSSPropertyID::kColumnGap: {
      if (CSSProperty::Get(CSSPropertyID::kGap).IsWebExposed())
        result->UncheckedAppend(gapShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridGap).IsWebExposed())
        result->UncheckedAppend(gridGapShorthand());
      if (CSSProperty::Get(CSSPropertyID::kGridColumnGap).IsWebExposed())
        result->UncheckedAppend(gridColumnGapShorthand());
      break;
    }
    case CSSPropertyID::kOverscrollBehaviorX: {
      if (CSSProperty::Get(CSSPropertyID::kOverscrollBehavior).IsWebExposed())
        result->UncheckedAppend(overscrollBehaviorShorthand());
      break;
    }
    case CSSPropertyID::kJustifySelf: {
      if (CSSProperty::Get(CSSPropertyID::kPlaceSelf).IsWebExposed())
        result->UncheckedAppend(placeSelfShorthand());
      break;
    }
    case CSSPropertyID::kBorderInlineEndStyle: {
      if (CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed())
        result->UncheckedAppend(borderInlineShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineEnd).IsWebExposed())
        result->UncheckedAppend(borderInlineEndShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineStyle).IsWebExposed())
        result->UncheckedAppend(borderInlineStyleShorthand());
      break;
    }
    case CSSPropertyID::kColumnRuleColor: {
      if (CSSProperty::Get(CSSPropertyID::kColumnRule).IsWebExposed())
        result->UncheckedAppend(columnRuleShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginBlockEnd: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMarginBlock).IsWebExposed())
        result->UncheckedAppend(scrollMarginBlockShorthand());
      break;
    }
    case CSSPropertyID::kScrollMarginInlineEnd: {
      if (CSSProperty::Get(CSSPropertyID::kScrollMarginInline).IsWebExposed())
        result->UncheckedAppend(scrollMarginInlineShorthand());
      break;
    }
    case CSSPropertyID::kMarginInlineStart: {
      if (CSSProperty::Get(CSSPropertyID::kMarginInline).IsWebExposed())
        result->UncheckedAppend(marginInlineShorthand());
      break;
    }
    case CSSPropertyID::kBorderBottomWidth: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderWidth).IsWebExposed())
        result->UncheckedAppend(borderWidthShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderBottom).IsWebExposed())
        result->UncheckedAppend(borderBottomShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageRepeat: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed())
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
      break;
    }
    case CSSPropertyID::kWebkitTextStrokeColor: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitTextStroke).IsWebExposed())
        result->UncheckedAppend(webkitTextStrokeShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskPositionX: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskPosition).IsWebExposed())
        result->UncheckedAppend(webkitMaskPositionShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskPositionY: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMask).IsWebExposed())
        result->UncheckedAppend(webkitMaskShorthand());
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskPosition).IsWebExposed())
        result->UncheckedAppend(webkitMaskPositionShorthand());
      break;
    }
    case CSSPropertyID::kWebkitMaskBoxImageSource: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitMaskBoxImage).IsWebExposed())
        result->UncheckedAppend(webkitMaskBoxImageShorthand());
      break;
    }
    case CSSPropertyID::kScrollPaddingRight: {
      if (CSSProperty::Get(CSSPropertyID::kScrollPadding).IsWebExposed())
        result->UncheckedAppend(scrollPaddingShorthand());
      break;
    }
    case CSSPropertyID::kBorderTopColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorder).IsWebExposed())
        result->UncheckedAppend(borderShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderColor).IsWebExposed())
        result->UncheckedAppend(borderColorShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderTop).IsWebExposed())
        result->UncheckedAppend(borderTopShorthand());
      break;
    }
    case CSSPropertyID::kBorderTopLeftRadius: {
      if (CSSProperty::Get(CSSPropertyID::kBorderRadius).IsWebExposed())
        result->UncheckedAppend(borderRadiusShorthand());
      break;
    }
    case CSSPropertyID::kWebkitBorderHorizontalSpacing: {
      if (CSSProperty::Get(CSSPropertyID::kBorderSpacing).IsWebExposed())
        result->UncheckedAppend(borderSpacingShorthand());
      break;
    }
    case CSSPropertyID::kBottom: {
      if (CSSProperty::Get(CSSPropertyID::kInset).IsWebExposed())
        result->UncheckedAppend(insetShorthand());
      break;
    }
    case CSSPropertyID::kWebkitTextStrokeWidth: {
      if (CSSProperty::Get(CSSPropertyID::kWebkitTextStroke).IsWebExposed())
        result->UncheckedAppend(webkitTextStrokeShorthand());
      break;
    }
    case CSSPropertyID::kBorderInlineEndColor: {
      if (CSSProperty::Get(CSSPropertyID::kBorderInline).IsWebExposed())
        result->UncheckedAppend(borderInlineShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineEnd).IsWebExposed())
        result->UncheckedAppend(borderInlineEndShorthand());
      if (CSSProperty::Get(CSSPropertyID::kBorderInlineColor).IsWebExposed())
        result->UncheckedAppend(borderInlineColorShorthand());
      break;
    }
    default:
      break;
  }
}

} // namespace blink
