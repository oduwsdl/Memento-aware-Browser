// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CSS_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CSS_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_css.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<css::StyleSheetOrigin> {
  static css::StyleSheetOrigin Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return css::StyleSheetOrigin::INJECTED;
    }
    if (value.GetString() == "injected")
      return css::StyleSheetOrigin::INJECTED;
    if (value.GetString() == "user-agent")
      return css::StyleSheetOrigin::USER_AGENT;
    if (value.GetString() == "inspector")
      return css::StyleSheetOrigin::INSPECTOR;
    if (value.GetString() == "regular")
      return css::StyleSheetOrigin::REGULAR;
    errors->AddError("invalid enum value");
    return css::StyleSheetOrigin::INJECTED;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StyleSheetOrigin& value) {
  switch (value) {
    case css::StyleSheetOrigin::INJECTED:
      return std::make_unique<base::Value>("injected");
    case css::StyleSheetOrigin::USER_AGENT:
      return std::make_unique<base::Value>("user-agent");
    case css::StyleSheetOrigin::INSPECTOR:
      return std::make_unique<base::Value>("inspector");
    case css::StyleSheetOrigin::REGULAR:
      return std::make_unique<base::Value>("regular");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<css::PseudoElementMatches> {
  static std::unique_ptr<css::PseudoElementMatches> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::PseudoElementMatches::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::PseudoElementMatches& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::InheritedStyleEntry> {
  static std::unique_ptr<css::InheritedStyleEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::InheritedStyleEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::InheritedStyleEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::RuleMatch> {
  static std::unique_ptr<css::RuleMatch> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::RuleMatch::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::RuleMatch& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::Value> {
  static std::unique_ptr<css::Value> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::Value::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::Value& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SelectorList> {
  static std::unique_ptr<css::SelectorList> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SelectorList::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SelectorList& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSStyleSheetHeader> {
  static std::unique_ptr<css::CSSStyleSheetHeader> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSStyleSheetHeader::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSStyleSheetHeader& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSRule> {
  static std::unique_ptr<css::CSSRule> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSRule::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSRule& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::RuleUsage> {
  static std::unique_ptr<css::RuleUsage> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::RuleUsage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::RuleUsage& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SourceRange> {
  static std::unique_ptr<css::SourceRange> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SourceRange::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SourceRange& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::ShorthandEntry> {
  static std::unique_ptr<css::ShorthandEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::ShorthandEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::ShorthandEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSComputedStyleProperty> {
  static std::unique_ptr<css::CSSComputedStyleProperty> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSComputedStyleProperty::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSComputedStyleProperty& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSStyle> {
  static std::unique_ptr<css::CSSStyle> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSStyle::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSStyle& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSProperty> {
  static std::unique_ptr<css::CSSProperty> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSProperty::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSProperty& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSMedia> {
  static std::unique_ptr<css::CSSMedia> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSMedia::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSMedia& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::MediaQuery> {
  static std::unique_ptr<css::MediaQuery> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::MediaQuery::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::MediaQuery& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::MediaQueryExpression> {
  static std::unique_ptr<css::MediaQueryExpression> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::MediaQueryExpression::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::MediaQueryExpression& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::PlatformFontUsage> {
  static std::unique_ptr<css::PlatformFontUsage> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::PlatformFontUsage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::PlatformFontUsage& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::FontFace> {
  static std::unique_ptr<css::FontFace> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::FontFace::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::FontFace& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSKeyframesRule> {
  static std::unique_ptr<css::CSSKeyframesRule> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSKeyframesRule::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSKeyframesRule& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CSSKeyframeRule> {
  static std::unique_ptr<css::CSSKeyframeRule> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CSSKeyframeRule::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSKeyframeRule& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StyleDeclarationEdit> {
  static std::unique_ptr<css::StyleDeclarationEdit> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StyleDeclarationEdit::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StyleDeclarationEdit& value) {
  return value.Serialize();
}

template <>
struct FromValue<css::CSSMediaSource> {
  static css::CSSMediaSource Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return css::CSSMediaSource::MEDIA_RULE;
    }
    if (value.GetString() == "mediaRule")
      return css::CSSMediaSource::MEDIA_RULE;
    if (value.GetString() == "importRule")
      return css::CSSMediaSource::IMPORT_RULE;
    if (value.GetString() == "linkedSheet")
      return css::CSSMediaSource::LINKED_SHEET;
    if (value.GetString() == "inlineSheet")
      return css::CSSMediaSource::INLINE_SHEET;
    errors->AddError("invalid enum value");
    return css::CSSMediaSource::MEDIA_RULE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CSSMediaSource& value) {
  switch (value) {
    case css::CSSMediaSource::MEDIA_RULE:
      return std::make_unique<base::Value>("mediaRule");
    case css::CSSMediaSource::IMPORT_RULE:
      return std::make_unique<base::Value>("importRule");
    case css::CSSMediaSource::LINKED_SHEET:
      return std::make_unique<base::Value>("linkedSheet");
    case css::CSSMediaSource::INLINE_SHEET:
      return std::make_unique<base::Value>("inlineSheet");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<css::AddRuleParams> {
  static std::unique_ptr<css::AddRuleParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::AddRuleParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::AddRuleParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::AddRuleResult> {
  static std::unique_ptr<css::AddRuleResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::AddRuleResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::AddRuleResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CollectClassNamesParams> {
  static std::unique_ptr<css::CollectClassNamesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CollectClassNamesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CollectClassNamesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CollectClassNamesResult> {
  static std::unique_ptr<css::CollectClassNamesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CollectClassNamesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CollectClassNamesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CreateStyleSheetParams> {
  static std::unique_ptr<css::CreateStyleSheetParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CreateStyleSheetParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CreateStyleSheetParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::CreateStyleSheetResult> {
  static std::unique_ptr<css::CreateStyleSheetResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::CreateStyleSheetResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::CreateStyleSheetResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::DisableParams> {
  static std::unique_ptr<css::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::DisableResult> {
  static std::unique_ptr<css::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::EnableParams> {
  static std::unique_ptr<css::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::EnableResult> {
  static std::unique_ptr<css::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::ForcePseudoStateParams> {
  static std::unique_ptr<css::ForcePseudoStateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::ForcePseudoStateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::ForcePseudoStateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::ForcePseudoStateResult> {
  static std::unique_ptr<css::ForcePseudoStateResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::ForcePseudoStateResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::ForcePseudoStateResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetBackgroundColorsParams> {
  static std::unique_ptr<css::GetBackgroundColorsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetBackgroundColorsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetBackgroundColorsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetBackgroundColorsResult> {
  static std::unique_ptr<css::GetBackgroundColorsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetBackgroundColorsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetBackgroundColorsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetComputedStyleForNodeParams> {
  static std::unique_ptr<css::GetComputedStyleForNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetComputedStyleForNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetComputedStyleForNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetComputedStyleForNodeResult> {
  static std::unique_ptr<css::GetComputedStyleForNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetComputedStyleForNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetComputedStyleForNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetInlineStylesForNodeParams> {
  static std::unique_ptr<css::GetInlineStylesForNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetInlineStylesForNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetInlineStylesForNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetInlineStylesForNodeResult> {
  static std::unique_ptr<css::GetInlineStylesForNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetInlineStylesForNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetInlineStylesForNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetMatchedStylesForNodeParams> {
  static std::unique_ptr<css::GetMatchedStylesForNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetMatchedStylesForNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetMatchedStylesForNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetMatchedStylesForNodeResult> {
  static std::unique_ptr<css::GetMatchedStylesForNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetMatchedStylesForNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetMatchedStylesForNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetMediaQueriesParams> {
  static std::unique_ptr<css::GetMediaQueriesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetMediaQueriesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetMediaQueriesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetMediaQueriesResult> {
  static std::unique_ptr<css::GetMediaQueriesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetMediaQueriesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetMediaQueriesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetPlatformFontsForNodeParams> {
  static std::unique_ptr<css::GetPlatformFontsForNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetPlatformFontsForNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetPlatformFontsForNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetPlatformFontsForNodeResult> {
  static std::unique_ptr<css::GetPlatformFontsForNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetPlatformFontsForNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetPlatformFontsForNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetStyleSheetTextParams> {
  static std::unique_ptr<css::GetStyleSheetTextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetStyleSheetTextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetStyleSheetTextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::GetStyleSheetTextResult> {
  static std::unique_ptr<css::GetStyleSheetTextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::GetStyleSheetTextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::GetStyleSheetTextResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetEffectivePropertyValueForNodeParams> {
  static std::unique_ptr<css::SetEffectivePropertyValueForNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetEffectivePropertyValueForNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetEffectivePropertyValueForNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetEffectivePropertyValueForNodeResult> {
  static std::unique_ptr<css::SetEffectivePropertyValueForNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetEffectivePropertyValueForNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetEffectivePropertyValueForNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetKeyframeKeyParams> {
  static std::unique_ptr<css::SetKeyframeKeyParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetKeyframeKeyParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetKeyframeKeyParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetKeyframeKeyResult> {
  static std::unique_ptr<css::SetKeyframeKeyResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetKeyframeKeyResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetKeyframeKeyResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetMediaTextParams> {
  static std::unique_ptr<css::SetMediaTextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetMediaTextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetMediaTextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetMediaTextResult> {
  static std::unique_ptr<css::SetMediaTextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetMediaTextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetMediaTextResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetRuleSelectorParams> {
  static std::unique_ptr<css::SetRuleSelectorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetRuleSelectorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetRuleSelectorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetRuleSelectorResult> {
  static std::unique_ptr<css::SetRuleSelectorResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetRuleSelectorResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetRuleSelectorResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetStyleSheetTextParams> {
  static std::unique_ptr<css::SetStyleSheetTextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetStyleSheetTextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetStyleSheetTextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetStyleSheetTextResult> {
  static std::unique_ptr<css::SetStyleSheetTextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetStyleSheetTextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetStyleSheetTextResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetStyleTextsParams> {
  static std::unique_ptr<css::SetStyleTextsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetStyleTextsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetStyleTextsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::SetStyleTextsResult> {
  static std::unique_ptr<css::SetStyleTextsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::SetStyleTextsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::SetStyleTextsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StartRuleUsageTrackingParams> {
  static std::unique_ptr<css::StartRuleUsageTrackingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StartRuleUsageTrackingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StartRuleUsageTrackingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StartRuleUsageTrackingResult> {
  static std::unique_ptr<css::StartRuleUsageTrackingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StartRuleUsageTrackingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StartRuleUsageTrackingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StopRuleUsageTrackingParams> {
  static std::unique_ptr<css::StopRuleUsageTrackingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StopRuleUsageTrackingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StopRuleUsageTrackingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StopRuleUsageTrackingResult> {
  static std::unique_ptr<css::StopRuleUsageTrackingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StopRuleUsageTrackingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StopRuleUsageTrackingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::TakeCoverageDeltaParams> {
  static std::unique_ptr<css::TakeCoverageDeltaParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::TakeCoverageDeltaParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::TakeCoverageDeltaParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::TakeCoverageDeltaResult> {
  static std::unique_ptr<css::TakeCoverageDeltaResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::TakeCoverageDeltaResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::TakeCoverageDeltaResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::FontsUpdatedParams> {
  static std::unique_ptr<css::FontsUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::FontsUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::FontsUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::MediaQueryResultChangedParams> {
  static std::unique_ptr<css::MediaQueryResultChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::MediaQueryResultChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::MediaQueryResultChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StyleSheetAddedParams> {
  static std::unique_ptr<css::StyleSheetAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StyleSheetAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StyleSheetAddedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StyleSheetChangedParams> {
  static std::unique_ptr<css::StyleSheetChangedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StyleSheetChangedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StyleSheetChangedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<css::StyleSheetRemovedParams> {
  static std::unique_ptr<css::StyleSheetRemovedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return css::StyleSheetRemovedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const css::StyleSheetRemovedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_CSS_H_
