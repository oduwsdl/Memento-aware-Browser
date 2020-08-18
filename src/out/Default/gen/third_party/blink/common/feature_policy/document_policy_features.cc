// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/document_policy_features.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/feature_policy/document_policy_features.json5


#include "base/no_destructor.h"
#include "third_party/blink/public/common/feature_policy/document_policy_features.h"
#include "third_party/blink/public/common/feature_policy/policy_value.h"
#include "third_party/blink/public/mojom/feature_policy/policy_value.mojom.h"
#include "third_party/blink/public/mojom/feature_policy/document_policy_feature.mojom.h"


namespace blink {

const DocumentPolicyFeatureInfoMap& GetDocumentPolicyFeatureInfoMap() {
  static const base::NoDestructor<DocumentPolicyFeatureInfoMap> feature_info_map({      {
        mojom::DocumentPolicyFeature::kFontDisplay,
        {
          "font-display-late-swap",
          "",
          PolicyValue(true)
        }
      },      {
        mojom::DocumentPolicyFeature::kUnoptimizedLosslessImages,
        {
          "unoptimized-lossless-images",
          "bpp",
          PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble)
        }
      },      {
        mojom::DocumentPolicyFeature::kForceLoadAtTop,
        {
          "force-load-at-top",
          "",
          PolicyValue(false)
        }
      },      {
        mojom::DocumentPolicyFeature::kUnoptimizedLosslessImagesStrict,
        {
          "unoptimized-lossless-images-strict",
          "bpp",
          PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble)
        }
      },      {
        mojom::DocumentPolicyFeature::kUnoptimizedLossyImages,
        {
          "unoptimized-lossy-images",
          "bpp",
          PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble)
        }
      },      {
        mojom::DocumentPolicyFeature::kOversizedImages,
        {
          "oversized-images",
          "scale",
          PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble)
        }
      },      {
        mojom::DocumentPolicyFeature::kUnsizedMedia,
        {
          "unsized-media",
          "",
          PolicyValue(true)
        }
      },      {
        mojom::DocumentPolicyFeature::kLayoutAnimations,
        {
          "layout-animations",
          "",
          PolicyValue(true)
        }
      },  });
  return *feature_info_map;
}

const DocumentPolicyNameFeatureMap& GetDocumentPolicyNameFeatureMap() {
  static const base::NoDestructor<DocumentPolicyNameFeatureMap> name_feature_map([] {
    DocumentPolicyNameFeatureMap map;
    for (const auto& entry : GetDocumentPolicyFeatureInfoMap())
      map.emplace(entry.second.feature_name, entry.first);
    return map;
  }());
  return *name_feature_map;
}

} // namespace blink


