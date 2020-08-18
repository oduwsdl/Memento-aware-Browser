// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_css.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_css.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace css {

std::unique_ptr<PseudoElementMatches> PseudoElementMatches::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PseudoElementMatches");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PseudoElementMatches> result(new PseudoElementMatches());
  errors->Push();
  errors->SetName("PseudoElementMatches");
  const base::Value* pseudo_type_value = value.FindKey("pseudoType");
  if (pseudo_type_value) {
    errors->SetName("pseudoType");
    result->pseudo_type_ = internal::FromValue<::headless::dom::PseudoType>::Parse(*pseudo_type_value, errors);
  } else {
    errors->AddError("required property missing: pseudoType");
  }
  const base::Value* matches_value = value.FindKey("matches");
  if (matches_value) {
    errors->SetName("matches");
    result->matches_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::RuleMatch>>>::Parse(*matches_value, errors);
  } else {
    errors->AddError("required property missing: matches");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PseudoElementMatches::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("pseudoType", internal::ToValue(pseudo_type_));
  result->Set("matches", internal::ToValue(matches_));
  return std::move(result);
}

std::unique_ptr<PseudoElementMatches> PseudoElementMatches::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PseudoElementMatches> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<InheritedStyleEntry> InheritedStyleEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("InheritedStyleEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<InheritedStyleEntry> result(new InheritedStyleEntry());
  errors->Push();
  errors->SetName("InheritedStyleEntry");
  const base::Value* inline_style_value = value.FindKey("inlineStyle");
  if (inline_style_value) {
    errors->SetName("inlineStyle");
    result->inline_style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*inline_style_value, errors);
  }
  const base::Value* matchedcss_rules_value = value.FindKey("matchedCSSRules");
  if (matchedcss_rules_value) {
    errors->SetName("matchedCSSRules");
    result->matchedcss_rules_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::RuleMatch>>>::Parse(*matchedcss_rules_value, errors);
  } else {
    errors->AddError("required property missing: matchedCSSRules");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> InheritedStyleEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (inline_style_)
    result->Set("inlineStyle", internal::ToValue(*inline_style_.value()));
  result->Set("matchedCSSRules", internal::ToValue(matchedcss_rules_));
  return std::move(result);
}

std::unique_ptr<InheritedStyleEntry> InheritedStyleEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<InheritedStyleEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RuleMatch> RuleMatch::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RuleMatch");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RuleMatch> result(new RuleMatch());
  errors->Push();
  errors->SetName("RuleMatch");
  const base::Value* rule_value = value.FindKey("rule");
  if (rule_value) {
    errors->SetName("rule");
    result->rule_ = internal::FromValue<::headless::css::CSSRule>::Parse(*rule_value, errors);
  } else {
    errors->AddError("required property missing: rule");
  }
  const base::Value* matching_selectors_value = value.FindKey("matchingSelectors");
  if (matching_selectors_value) {
    errors->SetName("matchingSelectors");
    result->matching_selectors_ = internal::FromValue<std::vector<int>>::Parse(*matching_selectors_value, errors);
  } else {
    errors->AddError("required property missing: matchingSelectors");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RuleMatch::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("rule", internal::ToValue(*rule_));
  result->Set("matchingSelectors", internal::ToValue(matching_selectors_));
  return std::move(result);
}

std::unique_ptr<RuleMatch> RuleMatch::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RuleMatch> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Value> Value::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Value");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Value> result(new Value());
  errors->Push();
  errors->SetName("Value");
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Value::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("text", internal::ToValue(text_));
  if (range_)
    result->Set("range", internal::ToValue(*range_.value()));
  return std::move(result);
}

std::unique_ptr<Value> Value::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Value> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SelectorList> SelectorList::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SelectorList");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SelectorList> result(new SelectorList());
  errors->Push();
  errors->SetName("SelectorList");
  const base::Value* selectors_value = value.FindKey("selectors");
  if (selectors_value) {
    errors->SetName("selectors");
    result->selectors_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::Value>>>::Parse(*selectors_value, errors);
  } else {
    errors->AddError("required property missing: selectors");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SelectorList::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("selectors", internal::ToValue(selectors_));
  result->Set("text", internal::ToValue(text_));
  return std::move(result);
}

std::unique_ptr<SelectorList> SelectorList::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SelectorList> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSStyleSheetHeader> CSSStyleSheetHeader::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSStyleSheetHeader");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSStyleSheetHeader> result(new CSSStyleSheetHeader());
  errors->Push();
  errors->SetName("CSSStyleSheetHeader");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  const base::Value* sourceurl_value = value.FindKey("sourceURL");
  if (sourceurl_value) {
    errors->SetName("sourceURL");
    result->sourceurl_ = internal::FromValue<std::string>::Parse(*sourceurl_value, errors);
  } else {
    errors->AddError("required property missing: sourceURL");
  }
  const base::Value* source_mapurl_value = value.FindKey("sourceMapURL");
  if (source_mapurl_value) {
    errors->SetName("sourceMapURL");
    result->source_mapurl_ = internal::FromValue<std::string>::Parse(*source_mapurl_value, errors);
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<::headless::css::StyleSheetOrigin>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* title_value = value.FindKey("title");
  if (title_value) {
    errors->SetName("title");
    result->title_ = internal::FromValue<std::string>::Parse(*title_value, errors);
  } else {
    errors->AddError("required property missing: title");
  }
  const base::Value* owner_node_value = value.FindKey("ownerNode");
  if (owner_node_value) {
    errors->SetName("ownerNode");
    result->owner_node_ = internal::FromValue<int>::Parse(*owner_node_value, errors);
  }
  const base::Value* disabled_value = value.FindKey("disabled");
  if (disabled_value) {
    errors->SetName("disabled");
    result->disabled_ = internal::FromValue<bool>::Parse(*disabled_value, errors);
  } else {
    errors->AddError("required property missing: disabled");
  }
  const base::Value* has_sourceurl_value = value.FindKey("hasSourceURL");
  if (has_sourceurl_value) {
    errors->SetName("hasSourceURL");
    result->has_sourceurl_ = internal::FromValue<bool>::Parse(*has_sourceurl_value, errors);
  }
  const base::Value* is_inline_value = value.FindKey("isInline");
  if (is_inline_value) {
    errors->SetName("isInline");
    result->is_inline_ = internal::FromValue<bool>::Parse(*is_inline_value, errors);
  } else {
    errors->AddError("required property missing: isInline");
  }
  const base::Value* is_mutable_value = value.FindKey("isMutable");
  if (is_mutable_value) {
    errors->SetName("isMutable");
    result->is_mutable_ = internal::FromValue<bool>::Parse(*is_mutable_value, errors);
  } else {
    errors->AddError("required property missing: isMutable");
  }
  const base::Value* start_line_value = value.FindKey("startLine");
  if (start_line_value) {
    errors->SetName("startLine");
    result->start_line_ = internal::FromValue<double>::Parse(*start_line_value, errors);
  } else {
    errors->AddError("required property missing: startLine");
  }
  const base::Value* start_column_value = value.FindKey("startColumn");
  if (start_column_value) {
    errors->SetName("startColumn");
    result->start_column_ = internal::FromValue<double>::Parse(*start_column_value, errors);
  } else {
    errors->AddError("required property missing: startColumn");
  }
  const base::Value* length_value = value.FindKey("length");
  if (length_value) {
    errors->SetName("length");
    result->length_ = internal::FromValue<double>::Parse(*length_value, errors);
  } else {
    errors->AddError("required property missing: length");
  }
  const base::Value* end_line_value = value.FindKey("endLine");
  if (end_line_value) {
    errors->SetName("endLine");
    result->end_line_ = internal::FromValue<double>::Parse(*end_line_value, errors);
  } else {
    errors->AddError("required property missing: endLine");
  }
  const base::Value* end_column_value = value.FindKey("endColumn");
  if (end_column_value) {
    errors->SetName("endColumn");
    result->end_column_ = internal::FromValue<double>::Parse(*end_column_value, errors);
  } else {
    errors->AddError("required property missing: endColumn");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSStyleSheetHeader::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("frameId", internal::ToValue(frame_id_));
  result->Set("sourceURL", internal::ToValue(sourceurl_));
  if (source_mapurl_)
    result->Set("sourceMapURL", internal::ToValue(source_mapurl_.value()));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("title", internal::ToValue(title_));
  if (owner_node_)
    result->Set("ownerNode", internal::ToValue(owner_node_.value()));
  result->Set("disabled", internal::ToValue(disabled_));
  if (has_sourceurl_)
    result->Set("hasSourceURL", internal::ToValue(has_sourceurl_.value()));
  result->Set("isInline", internal::ToValue(is_inline_));
  result->Set("isMutable", internal::ToValue(is_mutable_));
  result->Set("startLine", internal::ToValue(start_line_));
  result->Set("startColumn", internal::ToValue(start_column_));
  result->Set("length", internal::ToValue(length_));
  result->Set("endLine", internal::ToValue(end_line_));
  result->Set("endColumn", internal::ToValue(end_column_));
  return std::move(result);
}

std::unique_ptr<CSSStyleSheetHeader> CSSStyleSheetHeader::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSStyleSheetHeader> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSRule> CSSRule::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSRule");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSRule> result(new CSSRule());
  errors->Push();
  errors->SetName("CSSRule");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  }
  const base::Value* selector_list_value = value.FindKey("selectorList");
  if (selector_list_value) {
    errors->SetName("selectorList");
    result->selector_list_ = internal::FromValue<::headless::css::SelectorList>::Parse(*selector_list_value, errors);
  } else {
    errors->AddError("required property missing: selectorList");
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<::headless::css::StyleSheetOrigin>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* style_value = value.FindKey("style");
  if (style_value) {
    errors->SetName("style");
    result->style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*style_value, errors);
  } else {
    errors->AddError("required property missing: style");
  }
  const base::Value* media_value = value.FindKey("media");
  if (media_value) {
    errors->SetName("media");
    result->media_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSMedia>>>::Parse(*media_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSRule::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (style_sheet_id_)
    result->Set("styleSheetId", internal::ToValue(style_sheet_id_.value()));
  result->Set("selectorList", internal::ToValue(*selector_list_));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("style", internal::ToValue(*style_));
  if (media_)
    result->Set("media", internal::ToValue(media_.value()));
  return std::move(result);
}

std::unique_ptr<CSSRule> CSSRule::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSRule> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<RuleUsage> RuleUsage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("RuleUsage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<RuleUsage> result(new RuleUsage());
  errors->Push();
  errors->SetName("RuleUsage");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* start_offset_value = value.FindKey("startOffset");
  if (start_offset_value) {
    errors->SetName("startOffset");
    result->start_offset_ = internal::FromValue<double>::Parse(*start_offset_value, errors);
  } else {
    errors->AddError("required property missing: startOffset");
  }
  const base::Value* end_offset_value = value.FindKey("endOffset");
  if (end_offset_value) {
    errors->SetName("endOffset");
    result->end_offset_ = internal::FromValue<double>::Parse(*end_offset_value, errors);
  } else {
    errors->AddError("required property missing: endOffset");
  }
  const base::Value* used_value = value.FindKey("used");
  if (used_value) {
    errors->SetName("used");
    result->used_ = internal::FromValue<bool>::Parse(*used_value, errors);
  } else {
    errors->AddError("required property missing: used");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> RuleUsage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("startOffset", internal::ToValue(start_offset_));
  result->Set("endOffset", internal::ToValue(end_offset_));
  result->Set("used", internal::ToValue(used_));
  return std::move(result);
}

std::unique_ptr<RuleUsage> RuleUsage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<RuleUsage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SourceRange> SourceRange::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SourceRange");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SourceRange> result(new SourceRange());
  errors->Push();
  errors->SetName("SourceRange");
  const base::Value* start_line_value = value.FindKey("startLine");
  if (start_line_value) {
    errors->SetName("startLine");
    result->start_line_ = internal::FromValue<int>::Parse(*start_line_value, errors);
  } else {
    errors->AddError("required property missing: startLine");
  }
  const base::Value* start_column_value = value.FindKey("startColumn");
  if (start_column_value) {
    errors->SetName("startColumn");
    result->start_column_ = internal::FromValue<int>::Parse(*start_column_value, errors);
  } else {
    errors->AddError("required property missing: startColumn");
  }
  const base::Value* end_line_value = value.FindKey("endLine");
  if (end_line_value) {
    errors->SetName("endLine");
    result->end_line_ = internal::FromValue<int>::Parse(*end_line_value, errors);
  } else {
    errors->AddError("required property missing: endLine");
  }
  const base::Value* end_column_value = value.FindKey("endColumn");
  if (end_column_value) {
    errors->SetName("endColumn");
    result->end_column_ = internal::FromValue<int>::Parse(*end_column_value, errors);
  } else {
    errors->AddError("required property missing: endColumn");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SourceRange::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("startLine", internal::ToValue(start_line_));
  result->Set("startColumn", internal::ToValue(start_column_));
  result->Set("endLine", internal::ToValue(end_line_));
  result->Set("endColumn", internal::ToValue(end_column_));
  return std::move(result);
}

std::unique_ptr<SourceRange> SourceRange::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SourceRange> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ShorthandEntry> ShorthandEntry::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ShorthandEntry");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ShorthandEntry> result(new ShorthandEntry());
  errors->Push();
  errors->SetName("ShorthandEntry");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  const base::Value* important_value = value.FindKey("important");
  if (important_value) {
    errors->SetName("important");
    result->important_ = internal::FromValue<bool>::Parse(*important_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ShorthandEntry::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  if (important_)
    result->Set("important", internal::ToValue(important_.value()));
  return std::move(result);
}

std::unique_ptr<ShorthandEntry> ShorthandEntry::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ShorthandEntry> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSComputedStyleProperty> CSSComputedStyleProperty::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSComputedStyleProperty");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSComputedStyleProperty> result(new CSSComputedStyleProperty());
  errors->Push();
  errors->SetName("CSSComputedStyleProperty");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSComputedStyleProperty::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<CSSComputedStyleProperty> CSSComputedStyleProperty::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSComputedStyleProperty> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSStyle> CSSStyle::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSStyle");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSStyle> result(new CSSStyle());
  errors->Push();
  errors->SetName("CSSStyle");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  }
  const base::Value* css_properties_value = value.FindKey("cssProperties");
  if (css_properties_value) {
    errors->SetName("cssProperties");
    result->css_properties_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSProperty>>>::Parse(*css_properties_value, errors);
  } else {
    errors->AddError("required property missing: cssProperties");
  }
  const base::Value* shorthand_entries_value = value.FindKey("shorthandEntries");
  if (shorthand_entries_value) {
    errors->SetName("shorthandEntries");
    result->shorthand_entries_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::ShorthandEntry>>>::Parse(*shorthand_entries_value, errors);
  } else {
    errors->AddError("required property missing: shorthandEntries");
  }
  const base::Value* css_text_value = value.FindKey("cssText");
  if (css_text_value) {
    errors->SetName("cssText");
    result->css_text_ = internal::FromValue<std::string>::Parse(*css_text_value, errors);
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSStyle::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (style_sheet_id_)
    result->Set("styleSheetId", internal::ToValue(style_sheet_id_.value()));
  result->Set("cssProperties", internal::ToValue(css_properties_));
  result->Set("shorthandEntries", internal::ToValue(shorthand_entries_));
  if (css_text_)
    result->Set("cssText", internal::ToValue(css_text_.value()));
  if (range_)
    result->Set("range", internal::ToValue(*range_.value()));
  return std::move(result);
}

std::unique_ptr<CSSStyle> CSSStyle::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSStyle> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSProperty> CSSProperty::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSProperty");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSProperty> result(new CSSProperty());
  errors->Push();
  errors->SetName("CSSProperty");
  const base::Value* name_value = value.FindKey("name");
  if (name_value) {
    errors->SetName("name");
    result->name_ = internal::FromValue<std::string>::Parse(*name_value, errors);
  } else {
    errors->AddError("required property missing: name");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  const base::Value* important_value = value.FindKey("important");
  if (important_value) {
    errors->SetName("important");
    result->important_ = internal::FromValue<bool>::Parse(*important_value, errors);
  }
  const base::Value* implicit_value = value.FindKey("implicit");
  if (implicit_value) {
    errors->SetName("implicit");
    result->implicit_ = internal::FromValue<bool>::Parse(*implicit_value, errors);
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  }
  const base::Value* parsed_ok_value = value.FindKey("parsedOk");
  if (parsed_ok_value) {
    errors->SetName("parsedOk");
    result->parsed_ok_ = internal::FromValue<bool>::Parse(*parsed_ok_value, errors);
  }
  const base::Value* disabled_value = value.FindKey("disabled");
  if (disabled_value) {
    errors->SetName("disabled");
    result->disabled_ = internal::FromValue<bool>::Parse(*disabled_value, errors);
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSProperty::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("name", internal::ToValue(name_));
  result->Set("value", internal::ToValue(value_));
  if (important_)
    result->Set("important", internal::ToValue(important_.value()));
  if (implicit_)
    result->Set("implicit", internal::ToValue(implicit_.value()));
  if (text_)
    result->Set("text", internal::ToValue(text_.value()));
  if (parsed_ok_)
    result->Set("parsedOk", internal::ToValue(parsed_ok_.value()));
  if (disabled_)
    result->Set("disabled", internal::ToValue(disabled_.value()));
  if (range_)
    result->Set("range", internal::ToValue(*range_.value()));
  return std::move(result);
}

std::unique_ptr<CSSProperty> CSSProperty::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSProperty> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSMedia> CSSMedia::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSMedia");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSMedia> result(new CSSMedia());
  errors->Push();
  errors->SetName("CSSMedia");
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  const base::Value* source_value = value.FindKey("source");
  if (source_value) {
    errors->SetName("source");
    result->source_ = internal::FromValue<::headless::css::CSSMediaSource>::Parse(*source_value, errors);
  } else {
    errors->AddError("required property missing: source");
  }
  const base::Value* sourceurl_value = value.FindKey("sourceURL");
  if (sourceurl_value) {
    errors->SetName("sourceURL");
    result->sourceurl_ = internal::FromValue<std::string>::Parse(*sourceurl_value, errors);
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  }
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  }
  const base::Value* media_list_value = value.FindKey("mediaList");
  if (media_list_value) {
    errors->SetName("mediaList");
    result->media_list_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::MediaQuery>>>::Parse(*media_list_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSMedia::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("text", internal::ToValue(text_));
  result->Set("source", internal::ToValue(source_));
  if (sourceurl_)
    result->Set("sourceURL", internal::ToValue(sourceurl_.value()));
  if (range_)
    result->Set("range", internal::ToValue(*range_.value()));
  if (style_sheet_id_)
    result->Set("styleSheetId", internal::ToValue(style_sheet_id_.value()));
  if (media_list_)
    result->Set("mediaList", internal::ToValue(media_list_.value()));
  return std::move(result);
}

std::unique_ptr<CSSMedia> CSSMedia::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSMedia> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MediaQuery> MediaQuery::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MediaQuery");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MediaQuery> result(new MediaQuery());
  errors->Push();
  errors->SetName("MediaQuery");
  const base::Value* expressions_value = value.FindKey("expressions");
  if (expressions_value) {
    errors->SetName("expressions");
    result->expressions_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::MediaQueryExpression>>>::Parse(*expressions_value, errors);
  } else {
    errors->AddError("required property missing: expressions");
  }
  const base::Value* active_value = value.FindKey("active");
  if (active_value) {
    errors->SetName("active");
    result->active_ = internal::FromValue<bool>::Parse(*active_value, errors);
  } else {
    errors->AddError("required property missing: active");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MediaQuery::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("expressions", internal::ToValue(expressions_));
  result->Set("active", internal::ToValue(active_));
  return std::move(result);
}

std::unique_ptr<MediaQuery> MediaQuery::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MediaQuery> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MediaQueryExpression> MediaQueryExpression::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MediaQueryExpression");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MediaQueryExpression> result(new MediaQueryExpression());
  errors->Push();
  errors->SetName("MediaQueryExpression");
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<double>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  const base::Value* unit_value = value.FindKey("unit");
  if (unit_value) {
    errors->SetName("unit");
    result->unit_ = internal::FromValue<std::string>::Parse(*unit_value, errors);
  } else {
    errors->AddError("required property missing: unit");
  }
  const base::Value* feature_value = value.FindKey("feature");
  if (feature_value) {
    errors->SetName("feature");
    result->feature_ = internal::FromValue<std::string>::Parse(*feature_value, errors);
  } else {
    errors->AddError("required property missing: feature");
  }
  const base::Value* value_range_value = value.FindKey("valueRange");
  if (value_range_value) {
    errors->SetName("valueRange");
    result->value_range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*value_range_value, errors);
  }
  const base::Value* computed_length_value = value.FindKey("computedLength");
  if (computed_length_value) {
    errors->SetName("computedLength");
    result->computed_length_ = internal::FromValue<double>::Parse(*computed_length_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MediaQueryExpression::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("value", internal::ToValue(value_));
  result->Set("unit", internal::ToValue(unit_));
  result->Set("feature", internal::ToValue(feature_));
  if (value_range_)
    result->Set("valueRange", internal::ToValue(*value_range_.value()));
  if (computed_length_)
    result->Set("computedLength", internal::ToValue(computed_length_.value()));
  return std::move(result);
}

std::unique_ptr<MediaQueryExpression> MediaQueryExpression::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MediaQueryExpression> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PlatformFontUsage> PlatformFontUsage::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PlatformFontUsage");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PlatformFontUsage> result(new PlatformFontUsage());
  errors->Push();
  errors->SetName("PlatformFontUsage");
  const base::Value* family_name_value = value.FindKey("familyName");
  if (family_name_value) {
    errors->SetName("familyName");
    result->family_name_ = internal::FromValue<std::string>::Parse(*family_name_value, errors);
  } else {
    errors->AddError("required property missing: familyName");
  }
  const base::Value* is_custom_font_value = value.FindKey("isCustomFont");
  if (is_custom_font_value) {
    errors->SetName("isCustomFont");
    result->is_custom_font_ = internal::FromValue<bool>::Parse(*is_custom_font_value, errors);
  } else {
    errors->AddError("required property missing: isCustomFont");
  }
  const base::Value* glyph_count_value = value.FindKey("glyphCount");
  if (glyph_count_value) {
    errors->SetName("glyphCount");
    result->glyph_count_ = internal::FromValue<double>::Parse(*glyph_count_value, errors);
  } else {
    errors->AddError("required property missing: glyphCount");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PlatformFontUsage::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("familyName", internal::ToValue(family_name_));
  result->Set("isCustomFont", internal::ToValue(is_custom_font_));
  result->Set("glyphCount", internal::ToValue(glyph_count_));
  return std::move(result);
}

std::unique_ptr<PlatformFontUsage> PlatformFontUsage::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PlatformFontUsage> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FontFace> FontFace::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FontFace");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FontFace> result(new FontFace());
  errors->Push();
  errors->SetName("FontFace");
  const base::Value* font_family_value = value.FindKey("fontFamily");
  if (font_family_value) {
    errors->SetName("fontFamily");
    result->font_family_ = internal::FromValue<std::string>::Parse(*font_family_value, errors);
  } else {
    errors->AddError("required property missing: fontFamily");
  }
  const base::Value* font_style_value = value.FindKey("fontStyle");
  if (font_style_value) {
    errors->SetName("fontStyle");
    result->font_style_ = internal::FromValue<std::string>::Parse(*font_style_value, errors);
  } else {
    errors->AddError("required property missing: fontStyle");
  }
  const base::Value* font_variant_value = value.FindKey("fontVariant");
  if (font_variant_value) {
    errors->SetName("fontVariant");
    result->font_variant_ = internal::FromValue<std::string>::Parse(*font_variant_value, errors);
  } else {
    errors->AddError("required property missing: fontVariant");
  }
  const base::Value* font_weight_value = value.FindKey("fontWeight");
  if (font_weight_value) {
    errors->SetName("fontWeight");
    result->font_weight_ = internal::FromValue<std::string>::Parse(*font_weight_value, errors);
  } else {
    errors->AddError("required property missing: fontWeight");
  }
  const base::Value* font_stretch_value = value.FindKey("fontStretch");
  if (font_stretch_value) {
    errors->SetName("fontStretch");
    result->font_stretch_ = internal::FromValue<std::string>::Parse(*font_stretch_value, errors);
  } else {
    errors->AddError("required property missing: fontStretch");
  }
  const base::Value* unicode_range_value = value.FindKey("unicodeRange");
  if (unicode_range_value) {
    errors->SetName("unicodeRange");
    result->unicode_range_ = internal::FromValue<std::string>::Parse(*unicode_range_value, errors);
  } else {
    errors->AddError("required property missing: unicodeRange");
  }
  const base::Value* src_value = value.FindKey("src");
  if (src_value) {
    errors->SetName("src");
    result->src_ = internal::FromValue<std::string>::Parse(*src_value, errors);
  } else {
    errors->AddError("required property missing: src");
  }
  const base::Value* platform_font_family_value = value.FindKey("platformFontFamily");
  if (platform_font_family_value) {
    errors->SetName("platformFontFamily");
    result->platform_font_family_ = internal::FromValue<std::string>::Parse(*platform_font_family_value, errors);
  } else {
    errors->AddError("required property missing: platformFontFamily");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FontFace::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("fontFamily", internal::ToValue(font_family_));
  result->Set("fontStyle", internal::ToValue(font_style_));
  result->Set("fontVariant", internal::ToValue(font_variant_));
  result->Set("fontWeight", internal::ToValue(font_weight_));
  result->Set("fontStretch", internal::ToValue(font_stretch_));
  result->Set("unicodeRange", internal::ToValue(unicode_range_));
  result->Set("src", internal::ToValue(src_));
  result->Set("platformFontFamily", internal::ToValue(platform_font_family_));
  return std::move(result);
}

std::unique_ptr<FontFace> FontFace::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FontFace> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSKeyframesRule> CSSKeyframesRule::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSKeyframesRule");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSKeyframesRule> result(new CSSKeyframesRule());
  errors->Push();
  errors->SetName("CSSKeyframesRule");
  const base::Value* animation_name_value = value.FindKey("animationName");
  if (animation_name_value) {
    errors->SetName("animationName");
    result->animation_name_ = internal::FromValue<::headless::css::Value>::Parse(*animation_name_value, errors);
  } else {
    errors->AddError("required property missing: animationName");
  }
  const base::Value* keyframes_value = value.FindKey("keyframes");
  if (keyframes_value) {
    errors->SetName("keyframes");
    result->keyframes_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSKeyframeRule>>>::Parse(*keyframes_value, errors);
  } else {
    errors->AddError("required property missing: keyframes");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSKeyframesRule::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("animationName", internal::ToValue(*animation_name_));
  result->Set("keyframes", internal::ToValue(keyframes_));
  return std::move(result);
}

std::unique_ptr<CSSKeyframesRule> CSSKeyframesRule::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSKeyframesRule> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CSSKeyframeRule> CSSKeyframeRule::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CSSKeyframeRule");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CSSKeyframeRule> result(new CSSKeyframeRule());
  errors->Push();
  errors->SetName("CSSKeyframeRule");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  }
  const base::Value* origin_value = value.FindKey("origin");
  if (origin_value) {
    errors->SetName("origin");
    result->origin_ = internal::FromValue<::headless::css::StyleSheetOrigin>::Parse(*origin_value, errors);
  } else {
    errors->AddError("required property missing: origin");
  }
  const base::Value* key_text_value = value.FindKey("keyText");
  if (key_text_value) {
    errors->SetName("keyText");
    result->key_text_ = internal::FromValue<::headless::css::Value>::Parse(*key_text_value, errors);
  } else {
    errors->AddError("required property missing: keyText");
  }
  const base::Value* style_value = value.FindKey("style");
  if (style_value) {
    errors->SetName("style");
    result->style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*style_value, errors);
  } else {
    errors->AddError("required property missing: style");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CSSKeyframeRule::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (style_sheet_id_)
    result->Set("styleSheetId", internal::ToValue(style_sheet_id_.value()));
  result->Set("origin", internal::ToValue(origin_));
  result->Set("keyText", internal::ToValue(*key_text_));
  result->Set("style", internal::ToValue(*style_));
  return std::move(result);
}

std::unique_ptr<CSSKeyframeRule> CSSKeyframeRule::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CSSKeyframeRule> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StyleDeclarationEdit> StyleDeclarationEdit::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StyleDeclarationEdit");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StyleDeclarationEdit> result(new StyleDeclarationEdit());
  errors->Push();
  errors->SetName("StyleDeclarationEdit");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  } else {
    errors->AddError("required property missing: range");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StyleDeclarationEdit::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("range", internal::ToValue(*range_));
  result->Set("text", internal::ToValue(text_));
  return std::move(result);
}

std::unique_ptr<StyleDeclarationEdit> StyleDeclarationEdit::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StyleDeclarationEdit> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddRuleParams> AddRuleParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddRuleParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddRuleParams> result(new AddRuleParams());
  errors->Push();
  errors->SetName("AddRuleParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* rule_text_value = value.FindKey("ruleText");
  if (rule_text_value) {
    errors->SetName("ruleText");
    result->rule_text_ = internal::FromValue<std::string>::Parse(*rule_text_value, errors);
  } else {
    errors->AddError("required property missing: ruleText");
  }
  const base::Value* location_value = value.FindKey("location");
  if (location_value) {
    errors->SetName("location");
    result->location_ = internal::FromValue<::headless::css::SourceRange>::Parse(*location_value, errors);
  } else {
    errors->AddError("required property missing: location");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddRuleParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("ruleText", internal::ToValue(rule_text_));
  result->Set("location", internal::ToValue(*location_));
  return std::move(result);
}

std::unique_ptr<AddRuleParams> AddRuleParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddRuleParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<AddRuleResult> AddRuleResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("AddRuleResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<AddRuleResult> result(new AddRuleResult());
  errors->Push();
  errors->SetName("AddRuleResult");
  const base::Value* rule_value = value.FindKey("rule");
  if (rule_value) {
    errors->SetName("rule");
    result->rule_ = internal::FromValue<::headless::css::CSSRule>::Parse(*rule_value, errors);
  } else {
    errors->AddError("required property missing: rule");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> AddRuleResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("rule", internal::ToValue(*rule_));
  return std::move(result);
}

std::unique_ptr<AddRuleResult> AddRuleResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<AddRuleResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CollectClassNamesParams> CollectClassNamesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CollectClassNamesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CollectClassNamesParams> result(new CollectClassNamesParams());
  errors->Push();
  errors->SetName("CollectClassNamesParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CollectClassNamesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  return std::move(result);
}

std::unique_ptr<CollectClassNamesParams> CollectClassNamesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CollectClassNamesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CollectClassNamesResult> CollectClassNamesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CollectClassNamesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CollectClassNamesResult> result(new CollectClassNamesResult());
  errors->Push();
  errors->SetName("CollectClassNamesResult");
  const base::Value* class_names_value = value.FindKey("classNames");
  if (class_names_value) {
    errors->SetName("classNames");
    result->class_names_ = internal::FromValue<std::vector<std::string>>::Parse(*class_names_value, errors);
  } else {
    errors->AddError("required property missing: classNames");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CollectClassNamesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("classNames", internal::ToValue(class_names_));
  return std::move(result);
}

std::unique_ptr<CollectClassNamesResult> CollectClassNamesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CollectClassNamesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateStyleSheetParams> CreateStyleSheetParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateStyleSheetParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateStyleSheetParams> result(new CreateStyleSheetParams());
  errors->Push();
  errors->SetName("CreateStyleSheetParams");
  const base::Value* frame_id_value = value.FindKey("frameId");
  if (frame_id_value) {
    errors->SetName("frameId");
    result->frame_id_ = internal::FromValue<std::string>::Parse(*frame_id_value, errors);
  } else {
    errors->AddError("required property missing: frameId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateStyleSheetParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("frameId", internal::ToValue(frame_id_));
  return std::move(result);
}

std::unique_ptr<CreateStyleSheetParams> CreateStyleSheetParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateStyleSheetParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CreateStyleSheetResult> CreateStyleSheetResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CreateStyleSheetResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CreateStyleSheetResult> result(new CreateStyleSheetResult());
  errors->Push();
  errors->SetName("CreateStyleSheetResult");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CreateStyleSheetResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  return std::move(result);
}

std::unique_ptr<CreateStyleSheetResult> CreateStyleSheetResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CreateStyleSheetResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableParams> DisableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableParams> result(new DisableParams());
  errors->Push();
  errors->SetName("DisableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableParams> DisableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<DisableResult> DisableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("DisableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<DisableResult> result(new DisableResult());
  errors->Push();
  errors->SetName("DisableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> DisableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<DisableResult> DisableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<DisableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableParams> EnableParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableParams> result(new EnableParams());
  errors->Push();
  errors->SetName("EnableParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableParams> EnableParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<EnableResult> EnableResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("EnableResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<EnableResult> result(new EnableResult());
  errors->Push();
  errors->SetName("EnableResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> EnableResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<EnableResult> EnableResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<EnableResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ForcePseudoStateParams> ForcePseudoStateParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ForcePseudoStateParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ForcePseudoStateParams> result(new ForcePseudoStateParams());
  errors->Push();
  errors->SetName("ForcePseudoStateParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* forced_pseudo_classes_value = value.FindKey("forcedPseudoClasses");
  if (forced_pseudo_classes_value) {
    errors->SetName("forcedPseudoClasses");
    result->forced_pseudo_classes_ = internal::FromValue<std::vector<std::string>>::Parse(*forced_pseudo_classes_value, errors);
  } else {
    errors->AddError("required property missing: forcedPseudoClasses");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ForcePseudoStateParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("forcedPseudoClasses", internal::ToValue(forced_pseudo_classes_));
  return std::move(result);
}

std::unique_ptr<ForcePseudoStateParams> ForcePseudoStateParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ForcePseudoStateParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ForcePseudoStateResult> ForcePseudoStateResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ForcePseudoStateResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ForcePseudoStateResult> result(new ForcePseudoStateResult());
  errors->Push();
  errors->SetName("ForcePseudoStateResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ForcePseudoStateResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ForcePseudoStateResult> ForcePseudoStateResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ForcePseudoStateResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBackgroundColorsParams> GetBackgroundColorsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBackgroundColorsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBackgroundColorsParams> result(new GetBackgroundColorsParams());
  errors->Push();
  errors->SetName("GetBackgroundColorsParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBackgroundColorsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetBackgroundColorsParams> GetBackgroundColorsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBackgroundColorsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetBackgroundColorsResult> GetBackgroundColorsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetBackgroundColorsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetBackgroundColorsResult> result(new GetBackgroundColorsResult());
  errors->Push();
  errors->SetName("GetBackgroundColorsResult");
  const base::Value* background_colors_value = value.FindKey("backgroundColors");
  if (background_colors_value) {
    errors->SetName("backgroundColors");
    result->background_colors_ = internal::FromValue<std::vector<std::string>>::Parse(*background_colors_value, errors);
  }
  const base::Value* computed_font_size_value = value.FindKey("computedFontSize");
  if (computed_font_size_value) {
    errors->SetName("computedFontSize");
    result->computed_font_size_ = internal::FromValue<std::string>::Parse(*computed_font_size_value, errors);
  }
  const base::Value* computed_font_weight_value = value.FindKey("computedFontWeight");
  if (computed_font_weight_value) {
    errors->SetName("computedFontWeight");
    result->computed_font_weight_ = internal::FromValue<std::string>::Parse(*computed_font_weight_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetBackgroundColorsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (background_colors_)
    result->Set("backgroundColors", internal::ToValue(background_colors_.value()));
  if (computed_font_size_)
    result->Set("computedFontSize", internal::ToValue(computed_font_size_.value()));
  if (computed_font_weight_)
    result->Set("computedFontWeight", internal::ToValue(computed_font_weight_.value()));
  return std::move(result);
}

std::unique_ptr<GetBackgroundColorsResult> GetBackgroundColorsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetBackgroundColorsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetComputedStyleForNodeParams> GetComputedStyleForNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetComputedStyleForNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetComputedStyleForNodeParams> result(new GetComputedStyleForNodeParams());
  errors->Push();
  errors->SetName("GetComputedStyleForNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetComputedStyleForNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetComputedStyleForNodeParams> GetComputedStyleForNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetComputedStyleForNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetComputedStyleForNodeResult> GetComputedStyleForNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetComputedStyleForNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetComputedStyleForNodeResult> result(new GetComputedStyleForNodeResult());
  errors->Push();
  errors->SetName("GetComputedStyleForNodeResult");
  const base::Value* computed_style_value = value.FindKey("computedStyle");
  if (computed_style_value) {
    errors->SetName("computedStyle");
    result->computed_style_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSComputedStyleProperty>>>::Parse(*computed_style_value, errors);
  } else {
    errors->AddError("required property missing: computedStyle");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetComputedStyleForNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("computedStyle", internal::ToValue(computed_style_));
  return std::move(result);
}

std::unique_ptr<GetComputedStyleForNodeResult> GetComputedStyleForNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetComputedStyleForNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetInlineStylesForNodeParams> GetInlineStylesForNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetInlineStylesForNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetInlineStylesForNodeParams> result(new GetInlineStylesForNodeParams());
  errors->Push();
  errors->SetName("GetInlineStylesForNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetInlineStylesForNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetInlineStylesForNodeParams> GetInlineStylesForNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetInlineStylesForNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetInlineStylesForNodeResult> GetInlineStylesForNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetInlineStylesForNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetInlineStylesForNodeResult> result(new GetInlineStylesForNodeResult());
  errors->Push();
  errors->SetName("GetInlineStylesForNodeResult");
  const base::Value* inline_style_value = value.FindKey("inlineStyle");
  if (inline_style_value) {
    errors->SetName("inlineStyle");
    result->inline_style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*inline_style_value, errors);
  }
  const base::Value* attributes_style_value = value.FindKey("attributesStyle");
  if (attributes_style_value) {
    errors->SetName("attributesStyle");
    result->attributes_style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*attributes_style_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetInlineStylesForNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (inline_style_)
    result->Set("inlineStyle", internal::ToValue(*inline_style_.value()));
  if (attributes_style_)
    result->Set("attributesStyle", internal::ToValue(*attributes_style_.value()));
  return std::move(result);
}

std::unique_ptr<GetInlineStylesForNodeResult> GetInlineStylesForNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetInlineStylesForNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetMatchedStylesForNodeParams> GetMatchedStylesForNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetMatchedStylesForNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetMatchedStylesForNodeParams> result(new GetMatchedStylesForNodeParams());
  errors->Push();
  errors->SetName("GetMatchedStylesForNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetMatchedStylesForNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetMatchedStylesForNodeParams> GetMatchedStylesForNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetMatchedStylesForNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetMatchedStylesForNodeResult> GetMatchedStylesForNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetMatchedStylesForNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetMatchedStylesForNodeResult> result(new GetMatchedStylesForNodeResult());
  errors->Push();
  errors->SetName("GetMatchedStylesForNodeResult");
  const base::Value* inline_style_value = value.FindKey("inlineStyle");
  if (inline_style_value) {
    errors->SetName("inlineStyle");
    result->inline_style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*inline_style_value, errors);
  }
  const base::Value* attributes_style_value = value.FindKey("attributesStyle");
  if (attributes_style_value) {
    errors->SetName("attributesStyle");
    result->attributes_style_ = internal::FromValue<::headless::css::CSSStyle>::Parse(*attributes_style_value, errors);
  }
  const base::Value* matchedcss_rules_value = value.FindKey("matchedCSSRules");
  if (matchedcss_rules_value) {
    errors->SetName("matchedCSSRules");
    result->matchedcss_rules_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::RuleMatch>>>::Parse(*matchedcss_rules_value, errors);
  }
  const base::Value* pseudo_elements_value = value.FindKey("pseudoElements");
  if (pseudo_elements_value) {
    errors->SetName("pseudoElements");
    result->pseudo_elements_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::PseudoElementMatches>>>::Parse(*pseudo_elements_value, errors);
  }
  const base::Value* inherited_value = value.FindKey("inherited");
  if (inherited_value) {
    errors->SetName("inherited");
    result->inherited_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::InheritedStyleEntry>>>::Parse(*inherited_value, errors);
  }
  const base::Value* css_keyframes_rules_value = value.FindKey("cssKeyframesRules");
  if (css_keyframes_rules_value) {
    errors->SetName("cssKeyframesRules");
    result->css_keyframes_rules_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSKeyframesRule>>>::Parse(*css_keyframes_rules_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetMatchedStylesForNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (inline_style_)
    result->Set("inlineStyle", internal::ToValue(*inline_style_.value()));
  if (attributes_style_)
    result->Set("attributesStyle", internal::ToValue(*attributes_style_.value()));
  if (matchedcss_rules_)
    result->Set("matchedCSSRules", internal::ToValue(matchedcss_rules_.value()));
  if (pseudo_elements_)
    result->Set("pseudoElements", internal::ToValue(pseudo_elements_.value()));
  if (inherited_)
    result->Set("inherited", internal::ToValue(inherited_.value()));
  if (css_keyframes_rules_)
    result->Set("cssKeyframesRules", internal::ToValue(css_keyframes_rules_.value()));
  return std::move(result);
}

std::unique_ptr<GetMatchedStylesForNodeResult> GetMatchedStylesForNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetMatchedStylesForNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetMediaQueriesParams> GetMediaQueriesParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetMediaQueriesParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetMediaQueriesParams> result(new GetMediaQueriesParams());
  errors->Push();
  errors->SetName("GetMediaQueriesParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetMediaQueriesParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<GetMediaQueriesParams> GetMediaQueriesParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetMediaQueriesParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetMediaQueriesResult> GetMediaQueriesResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetMediaQueriesResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetMediaQueriesResult> result(new GetMediaQueriesResult());
  errors->Push();
  errors->SetName("GetMediaQueriesResult");
  const base::Value* medias_value = value.FindKey("medias");
  if (medias_value) {
    errors->SetName("medias");
    result->medias_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSMedia>>>::Parse(*medias_value, errors);
  } else {
    errors->AddError("required property missing: medias");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetMediaQueriesResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("medias", internal::ToValue(medias_));
  return std::move(result);
}

std::unique_ptr<GetMediaQueriesResult> GetMediaQueriesResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetMediaQueriesResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetPlatformFontsForNodeParams> GetPlatformFontsForNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetPlatformFontsForNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetPlatformFontsForNodeParams> result(new GetPlatformFontsForNodeParams());
  errors->Push();
  errors->SetName("GetPlatformFontsForNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetPlatformFontsForNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  return std::move(result);
}

std::unique_ptr<GetPlatformFontsForNodeParams> GetPlatformFontsForNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetPlatformFontsForNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetPlatformFontsForNodeResult> GetPlatformFontsForNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetPlatformFontsForNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetPlatformFontsForNodeResult> result(new GetPlatformFontsForNodeResult());
  errors->Push();
  errors->SetName("GetPlatformFontsForNodeResult");
  const base::Value* fonts_value = value.FindKey("fonts");
  if (fonts_value) {
    errors->SetName("fonts");
    result->fonts_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::PlatformFontUsage>>>::Parse(*fonts_value, errors);
  } else {
    errors->AddError("required property missing: fonts");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetPlatformFontsForNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("fonts", internal::ToValue(fonts_));
  return std::move(result);
}

std::unique_ptr<GetPlatformFontsForNodeResult> GetPlatformFontsForNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetPlatformFontsForNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetStyleSheetTextParams> GetStyleSheetTextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetStyleSheetTextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetStyleSheetTextParams> result(new GetStyleSheetTextParams());
  errors->Push();
  errors->SetName("GetStyleSheetTextParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetStyleSheetTextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  return std::move(result);
}

std::unique_ptr<GetStyleSheetTextParams> GetStyleSheetTextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetStyleSheetTextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<GetStyleSheetTextResult> GetStyleSheetTextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("GetStyleSheetTextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<GetStyleSheetTextResult> result(new GetStyleSheetTextResult());
  errors->Push();
  errors->SetName("GetStyleSheetTextResult");
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> GetStyleSheetTextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("text", internal::ToValue(text_));
  return std::move(result);
}

std::unique_ptr<GetStyleSheetTextResult> GetStyleSheetTextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<GetStyleSheetTextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetEffectivePropertyValueForNodeParams> SetEffectivePropertyValueForNodeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetEffectivePropertyValueForNodeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetEffectivePropertyValueForNodeParams> result(new SetEffectivePropertyValueForNodeParams());
  errors->Push();
  errors->SetName("SetEffectivePropertyValueForNodeParams");
  const base::Value* node_id_value = value.FindKey("nodeId");
  if (node_id_value) {
    errors->SetName("nodeId");
    result->node_id_ = internal::FromValue<int>::Parse(*node_id_value, errors);
  } else {
    errors->AddError("required property missing: nodeId");
  }
  const base::Value* property_name_value = value.FindKey("propertyName");
  if (property_name_value) {
    errors->SetName("propertyName");
    result->property_name_ = internal::FromValue<std::string>::Parse(*property_name_value, errors);
  } else {
    errors->AddError("required property missing: propertyName");
  }
  const base::Value* value_value = value.FindKey("value");
  if (value_value) {
    errors->SetName("value");
    result->value_ = internal::FromValue<std::string>::Parse(*value_value, errors);
  } else {
    errors->AddError("required property missing: value");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetEffectivePropertyValueForNodeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("nodeId", internal::ToValue(node_id_));
  result->Set("propertyName", internal::ToValue(property_name_));
  result->Set("value", internal::ToValue(value_));
  return std::move(result);
}

std::unique_ptr<SetEffectivePropertyValueForNodeParams> SetEffectivePropertyValueForNodeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetEffectivePropertyValueForNodeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetEffectivePropertyValueForNodeResult> SetEffectivePropertyValueForNodeResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetEffectivePropertyValueForNodeResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetEffectivePropertyValueForNodeResult> result(new SetEffectivePropertyValueForNodeResult());
  errors->Push();
  errors->SetName("SetEffectivePropertyValueForNodeResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetEffectivePropertyValueForNodeResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<SetEffectivePropertyValueForNodeResult> SetEffectivePropertyValueForNodeResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetEffectivePropertyValueForNodeResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetKeyframeKeyParams> SetKeyframeKeyParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetKeyframeKeyParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetKeyframeKeyParams> result(new SetKeyframeKeyParams());
  errors->Push();
  errors->SetName("SetKeyframeKeyParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  } else {
    errors->AddError("required property missing: range");
  }
  const base::Value* key_text_value = value.FindKey("keyText");
  if (key_text_value) {
    errors->SetName("keyText");
    result->key_text_ = internal::FromValue<std::string>::Parse(*key_text_value, errors);
  } else {
    errors->AddError("required property missing: keyText");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetKeyframeKeyParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("range", internal::ToValue(*range_));
  result->Set("keyText", internal::ToValue(key_text_));
  return std::move(result);
}

std::unique_ptr<SetKeyframeKeyParams> SetKeyframeKeyParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetKeyframeKeyParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetKeyframeKeyResult> SetKeyframeKeyResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetKeyframeKeyResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetKeyframeKeyResult> result(new SetKeyframeKeyResult());
  errors->Push();
  errors->SetName("SetKeyframeKeyResult");
  const base::Value* key_text_value = value.FindKey("keyText");
  if (key_text_value) {
    errors->SetName("keyText");
    result->key_text_ = internal::FromValue<::headless::css::Value>::Parse(*key_text_value, errors);
  } else {
    errors->AddError("required property missing: keyText");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetKeyframeKeyResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("keyText", internal::ToValue(*key_text_));
  return std::move(result);
}

std::unique_ptr<SetKeyframeKeyResult> SetKeyframeKeyResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetKeyframeKeyResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetMediaTextParams> SetMediaTextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetMediaTextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetMediaTextParams> result(new SetMediaTextParams());
  errors->Push();
  errors->SetName("SetMediaTextParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  } else {
    errors->AddError("required property missing: range");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetMediaTextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("range", internal::ToValue(*range_));
  result->Set("text", internal::ToValue(text_));
  return std::move(result);
}

std::unique_ptr<SetMediaTextParams> SetMediaTextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetMediaTextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetMediaTextResult> SetMediaTextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetMediaTextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetMediaTextResult> result(new SetMediaTextResult());
  errors->Push();
  errors->SetName("SetMediaTextResult");
  const base::Value* media_value = value.FindKey("media");
  if (media_value) {
    errors->SetName("media");
    result->media_ = internal::FromValue<::headless::css::CSSMedia>::Parse(*media_value, errors);
  } else {
    errors->AddError("required property missing: media");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetMediaTextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("media", internal::ToValue(*media_));
  return std::move(result);
}

std::unique_ptr<SetMediaTextResult> SetMediaTextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetMediaTextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRuleSelectorParams> SetRuleSelectorParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRuleSelectorParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRuleSelectorParams> result(new SetRuleSelectorParams());
  errors->Push();
  errors->SetName("SetRuleSelectorParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* range_value = value.FindKey("range");
  if (range_value) {
    errors->SetName("range");
    result->range_ = internal::FromValue<::headless::css::SourceRange>::Parse(*range_value, errors);
  } else {
    errors->AddError("required property missing: range");
  }
  const base::Value* selector_value = value.FindKey("selector");
  if (selector_value) {
    errors->SetName("selector");
    result->selector_ = internal::FromValue<std::string>::Parse(*selector_value, errors);
  } else {
    errors->AddError("required property missing: selector");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRuleSelectorParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("range", internal::ToValue(*range_));
  result->Set("selector", internal::ToValue(selector_));
  return std::move(result);
}

std::unique_ptr<SetRuleSelectorParams> SetRuleSelectorParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRuleSelectorParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetRuleSelectorResult> SetRuleSelectorResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetRuleSelectorResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetRuleSelectorResult> result(new SetRuleSelectorResult());
  errors->Push();
  errors->SetName("SetRuleSelectorResult");
  const base::Value* selector_list_value = value.FindKey("selectorList");
  if (selector_list_value) {
    errors->SetName("selectorList");
    result->selector_list_ = internal::FromValue<::headless::css::SelectorList>::Parse(*selector_list_value, errors);
  } else {
    errors->AddError("required property missing: selectorList");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetRuleSelectorResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("selectorList", internal::ToValue(*selector_list_));
  return std::move(result);
}

std::unique_ptr<SetRuleSelectorResult> SetRuleSelectorResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetRuleSelectorResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetStyleSheetTextParams> SetStyleSheetTextParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetStyleSheetTextParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetStyleSheetTextParams> result(new SetStyleSheetTextParams());
  errors->Push();
  errors->SetName("SetStyleSheetTextParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  const base::Value* text_value = value.FindKey("text");
  if (text_value) {
    errors->SetName("text");
    result->text_ = internal::FromValue<std::string>::Parse(*text_value, errors);
  } else {
    errors->AddError("required property missing: text");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetStyleSheetTextParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  result->Set("text", internal::ToValue(text_));
  return std::move(result);
}

std::unique_ptr<SetStyleSheetTextParams> SetStyleSheetTextParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetStyleSheetTextParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetStyleSheetTextResult> SetStyleSheetTextResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetStyleSheetTextResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetStyleSheetTextResult> result(new SetStyleSheetTextResult());
  errors->Push();
  errors->SetName("SetStyleSheetTextResult");
  const base::Value* source_mapurl_value = value.FindKey("sourceMapURL");
  if (source_mapurl_value) {
    errors->SetName("sourceMapURL");
    result->source_mapurl_ = internal::FromValue<std::string>::Parse(*source_mapurl_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetStyleSheetTextResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (source_mapurl_)
    result->Set("sourceMapURL", internal::ToValue(source_mapurl_.value()));
  return std::move(result);
}

std::unique_ptr<SetStyleSheetTextResult> SetStyleSheetTextResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetStyleSheetTextResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetStyleTextsParams> SetStyleTextsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetStyleTextsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetStyleTextsParams> result(new SetStyleTextsParams());
  errors->Push();
  errors->SetName("SetStyleTextsParams");
  const base::Value* edits_value = value.FindKey("edits");
  if (edits_value) {
    errors->SetName("edits");
    result->edits_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::StyleDeclarationEdit>>>::Parse(*edits_value, errors);
  } else {
    errors->AddError("required property missing: edits");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetStyleTextsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("edits", internal::ToValue(edits_));
  return std::move(result);
}

std::unique_ptr<SetStyleTextsParams> SetStyleTextsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetStyleTextsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SetStyleTextsResult> SetStyleTextsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SetStyleTextsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SetStyleTextsResult> result(new SetStyleTextsResult());
  errors->Push();
  errors->SetName("SetStyleTextsResult");
  const base::Value* styles_value = value.FindKey("styles");
  if (styles_value) {
    errors->SetName("styles");
    result->styles_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::CSSStyle>>>::Parse(*styles_value, errors);
  } else {
    errors->AddError("required property missing: styles");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SetStyleTextsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styles", internal::ToValue(styles_));
  return std::move(result);
}

std::unique_ptr<SetStyleTextsResult> SetStyleTextsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SetStyleTextsResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartRuleUsageTrackingParams> StartRuleUsageTrackingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartRuleUsageTrackingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartRuleUsageTrackingParams> result(new StartRuleUsageTrackingParams());
  errors->Push();
  errors->SetName("StartRuleUsageTrackingParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartRuleUsageTrackingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartRuleUsageTrackingParams> StartRuleUsageTrackingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartRuleUsageTrackingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StartRuleUsageTrackingResult> StartRuleUsageTrackingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StartRuleUsageTrackingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StartRuleUsageTrackingResult> result(new StartRuleUsageTrackingResult());
  errors->Push();
  errors->SetName("StartRuleUsageTrackingResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StartRuleUsageTrackingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StartRuleUsageTrackingResult> StartRuleUsageTrackingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StartRuleUsageTrackingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopRuleUsageTrackingParams> StopRuleUsageTrackingParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopRuleUsageTrackingParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopRuleUsageTrackingParams> result(new StopRuleUsageTrackingParams());
  errors->Push();
  errors->SetName("StopRuleUsageTrackingParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopRuleUsageTrackingParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<StopRuleUsageTrackingParams> StopRuleUsageTrackingParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopRuleUsageTrackingParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StopRuleUsageTrackingResult> StopRuleUsageTrackingResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StopRuleUsageTrackingResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StopRuleUsageTrackingResult> result(new StopRuleUsageTrackingResult());
  errors->Push();
  errors->SetName("StopRuleUsageTrackingResult");
  const base::Value* rule_usage_value = value.FindKey("ruleUsage");
  if (rule_usage_value) {
    errors->SetName("ruleUsage");
    result->rule_usage_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::RuleUsage>>>::Parse(*rule_usage_value, errors);
  } else {
    errors->AddError("required property missing: ruleUsage");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StopRuleUsageTrackingResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("ruleUsage", internal::ToValue(rule_usage_));
  return std::move(result);
}

std::unique_ptr<StopRuleUsageTrackingResult> StopRuleUsageTrackingResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StopRuleUsageTrackingResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeCoverageDeltaParams> TakeCoverageDeltaParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeCoverageDeltaParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeCoverageDeltaParams> result(new TakeCoverageDeltaParams());
  errors->Push();
  errors->SetName("TakeCoverageDeltaParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeCoverageDeltaParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<TakeCoverageDeltaParams> TakeCoverageDeltaParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeCoverageDeltaParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<TakeCoverageDeltaResult> TakeCoverageDeltaResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("TakeCoverageDeltaResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<TakeCoverageDeltaResult> result(new TakeCoverageDeltaResult());
  errors->Push();
  errors->SetName("TakeCoverageDeltaResult");
  const base::Value* coverage_value = value.FindKey("coverage");
  if (coverage_value) {
    errors->SetName("coverage");
    result->coverage_ = internal::FromValue<std::vector<std::unique_ptr<::headless::css::RuleUsage>>>::Parse(*coverage_value, errors);
  } else {
    errors->AddError("required property missing: coverage");
  }
  const base::Value* timestamp_value = value.FindKey("timestamp");
  if (timestamp_value) {
    errors->SetName("timestamp");
    result->timestamp_ = internal::FromValue<double>::Parse(*timestamp_value, errors);
  } else {
    errors->AddError("required property missing: timestamp");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> TakeCoverageDeltaResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("coverage", internal::ToValue(coverage_));
  result->Set("timestamp", internal::ToValue(timestamp_));
  return std::move(result);
}

std::unique_ptr<TakeCoverageDeltaResult> TakeCoverageDeltaResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<TakeCoverageDeltaResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<FontsUpdatedParams> FontsUpdatedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("FontsUpdatedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<FontsUpdatedParams> result(new FontsUpdatedParams());
  errors->Push();
  errors->SetName("FontsUpdatedParams");
  const base::Value* font_value = value.FindKey("font");
  if (font_value) {
    errors->SetName("font");
    result->font_ = internal::FromValue<::headless::css::FontFace>::Parse(*font_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> FontsUpdatedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (font_)
    result->Set("font", internal::ToValue(*font_.value()));
  return std::move(result);
}

std::unique_ptr<FontsUpdatedParams> FontsUpdatedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<FontsUpdatedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MediaQueryResultChangedParams> MediaQueryResultChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MediaQueryResultChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MediaQueryResultChangedParams> result(new MediaQueryResultChangedParams());
  errors->Push();
  errors->SetName("MediaQueryResultChangedParams");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MediaQueryResultChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<MediaQueryResultChangedParams> MediaQueryResultChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MediaQueryResultChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StyleSheetAddedParams> StyleSheetAddedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StyleSheetAddedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StyleSheetAddedParams> result(new StyleSheetAddedParams());
  errors->Push();
  errors->SetName("StyleSheetAddedParams");
  const base::Value* header_value = value.FindKey("header");
  if (header_value) {
    errors->SetName("header");
    result->header_ = internal::FromValue<::headless::css::CSSStyleSheetHeader>::Parse(*header_value, errors);
  } else {
    errors->AddError("required property missing: header");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StyleSheetAddedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("header", internal::ToValue(*header_));
  return std::move(result);
}

std::unique_ptr<StyleSheetAddedParams> StyleSheetAddedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StyleSheetAddedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StyleSheetChangedParams> StyleSheetChangedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StyleSheetChangedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StyleSheetChangedParams> result(new StyleSheetChangedParams());
  errors->Push();
  errors->SetName("StyleSheetChangedParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StyleSheetChangedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  return std::move(result);
}

std::unique_ptr<StyleSheetChangedParams> StyleSheetChangedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StyleSheetChangedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StyleSheetRemovedParams> StyleSheetRemovedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StyleSheetRemovedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StyleSheetRemovedParams> result(new StyleSheetRemovedParams());
  errors->Push();
  errors->SetName("StyleSheetRemovedParams");
  const base::Value* style_sheet_id_value = value.FindKey("styleSheetId");
  if (style_sheet_id_value) {
    errors->SetName("styleSheetId");
    result->style_sheet_id_ = internal::FromValue<std::string>::Parse(*style_sheet_id_value, errors);
  } else {
    errors->AddError("required property missing: styleSheetId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StyleSheetRemovedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("styleSheetId", internal::ToValue(style_sheet_id_));
  return std::move(result);
}

std::unique_ptr<StyleSheetRemovedParams> StyleSheetRemovedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StyleSheetRemovedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace css
}  // namespace headless
