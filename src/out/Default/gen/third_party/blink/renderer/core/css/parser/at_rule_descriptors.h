// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_

#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/platform/wtf/text/string_view.h"
#include <string.h>

namespace blink {

enum class AtRuleDescriptorID {
  Invalid = 0,
  End = 1,
  FontDisplay = 2,
  FontFamily = 3,
  FontFeatureSettings = 4,
  FontStretch = 5,
  FontStyle = 6,
  FontVariant = 7,
  FontWeight = 8,
  Height = 9,
  Inherits = 10,
  InitialValue = 11,
  MaxHeight = 12,
  MaxWidth = 13,
  MaxZoom = 14,
  MinHeight = 15,
  MinWidth = 16,
  MinZoom = 17,
  Orientation = 18,
  Source = 19,
  Src = 20,
  Start = 21,
  Syntax = 22,
  TimeRange = 23,
  UnicodeRange = 24,
  UserZoom = 25,
  Width = 26,
  Zoom = 27,
};

const int numAtRuleDescriptors = 28;

const char* getValueName(AtRuleDescriptorID);

AtRuleDescriptorID AsAtRuleDescriptorID(StringView string);

CSSPropertyID AtRuleDescriptorIDAsCSSPropertyID(AtRuleDescriptorID);
AtRuleDescriptorID CSSPropertyIDAsAtRuleDescriptor(CSSPropertyID id);

}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
