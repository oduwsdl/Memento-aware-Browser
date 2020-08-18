// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_type_helpers.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/svg/svg_tag_names.json5


#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_SVG_ELEMENT_TYPE_HELPERS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_SVG_ELEMENT_TYPE_HELPERS_H_

#include "third_party/blink/renderer/core/svg/svg_element.h"
#include "third_party/blink/renderer/core/svg_names.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

class Document;

// Type checking.
class SVGAElement;
template <>
inline bool IsElementOfType<const SVGAElement>(const Node& node) {
  return IsA<SVGAElement>(node);
}
template <>
inline bool IsElementOfType<const SVGAElement>(const SVGElement& element) {
  return IsA<SVGAElement>(element);
}
template <>
struct DowncastTraits<SVGAElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kATag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGAElement>(To<SVGElement>(node));
  }
};

class SVGAnimateMotionElement;
template <>
inline bool IsElementOfType<const SVGAnimateMotionElement>(const Node& node) {
  return IsA<SVGAnimateMotionElement>(node);
}
template <>
inline bool IsElementOfType<const SVGAnimateMotionElement>(const SVGElement& element) {
  return IsA<SVGAnimateMotionElement>(element);
}
template <>
struct DowncastTraits<SVGAnimateMotionElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kAnimateMotionTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGAnimateMotionElement>(To<SVGElement>(node));
  }
};

class SVGAnimateTransformElement;
template <>
inline bool IsElementOfType<const SVGAnimateTransformElement>(const Node& node) {
  return IsA<SVGAnimateTransformElement>(node);
}
template <>
inline bool IsElementOfType<const SVGAnimateTransformElement>(const SVGElement& element) {
  return IsA<SVGAnimateTransformElement>(element);
}
template <>
struct DowncastTraits<SVGAnimateTransformElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kAnimateTransformTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGAnimateTransformElement>(To<SVGElement>(node));
  }
};

class SVGCircleElement;
template <>
inline bool IsElementOfType<const SVGCircleElement>(const Node& node) {
  return IsA<SVGCircleElement>(node);
}
template <>
inline bool IsElementOfType<const SVGCircleElement>(const SVGElement& element) {
  return IsA<SVGCircleElement>(element);
}
template <>
struct DowncastTraits<SVGCircleElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kCircleTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGCircleElement>(To<SVGElement>(node));
  }
};

class SVGClipPathElement;
template <>
inline bool IsElementOfType<const SVGClipPathElement>(const Node& node) {
  return IsA<SVGClipPathElement>(node);
}
template <>
inline bool IsElementOfType<const SVGClipPathElement>(const SVGElement& element) {
  return IsA<SVGClipPathElement>(element);
}
template <>
struct DowncastTraits<SVGClipPathElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kClipPathTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGClipPathElement>(To<SVGElement>(node));
  }
};

class SVGDefsElement;
template <>
inline bool IsElementOfType<const SVGDefsElement>(const Node& node) {
  return IsA<SVGDefsElement>(node);
}
template <>
inline bool IsElementOfType<const SVGDefsElement>(const SVGElement& element) {
  return IsA<SVGDefsElement>(element);
}
template <>
struct DowncastTraits<SVGDefsElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kDefsTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGDefsElement>(To<SVGElement>(node));
  }
};

class SVGDescElement;
template <>
inline bool IsElementOfType<const SVGDescElement>(const Node& node) {
  return IsA<SVGDescElement>(node);
}
template <>
inline bool IsElementOfType<const SVGDescElement>(const SVGElement& element) {
  return IsA<SVGDescElement>(element);
}
template <>
struct DowncastTraits<SVGDescElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kDescTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGDescElement>(To<SVGElement>(node));
  }
};

class SVGEllipseElement;
template <>
inline bool IsElementOfType<const SVGEllipseElement>(const Node& node) {
  return IsA<SVGEllipseElement>(node);
}
template <>
inline bool IsElementOfType<const SVGEllipseElement>(const SVGElement& element) {
  return IsA<SVGEllipseElement>(element);
}
template <>
struct DowncastTraits<SVGEllipseElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kEllipseTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGEllipseElement>(To<SVGElement>(node));
  }
};

class SVGFEBlendElement;
template <>
inline bool IsElementOfType<const SVGFEBlendElement>(const Node& node) {
  return IsA<SVGFEBlendElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEBlendElement>(const SVGElement& element) {
  return IsA<SVGFEBlendElement>(element);
}
template <>
struct DowncastTraits<SVGFEBlendElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEBlendTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEBlendElement>(To<SVGElement>(node));
  }
};

class SVGFEColorMatrixElement;
template <>
inline bool IsElementOfType<const SVGFEColorMatrixElement>(const Node& node) {
  return IsA<SVGFEColorMatrixElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEColorMatrixElement>(const SVGElement& element) {
  return IsA<SVGFEColorMatrixElement>(element);
}
template <>
struct DowncastTraits<SVGFEColorMatrixElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEColorMatrixTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEColorMatrixElement>(To<SVGElement>(node));
  }
};

class SVGFEComponentTransferElement;
template <>
inline bool IsElementOfType<const SVGFEComponentTransferElement>(const Node& node) {
  return IsA<SVGFEComponentTransferElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEComponentTransferElement>(const SVGElement& element) {
  return IsA<SVGFEComponentTransferElement>(element);
}
template <>
struct DowncastTraits<SVGFEComponentTransferElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEComponentTransferTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEComponentTransferElement>(To<SVGElement>(node));
  }
};

class SVGFECompositeElement;
template <>
inline bool IsElementOfType<const SVGFECompositeElement>(const Node& node) {
  return IsA<SVGFECompositeElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFECompositeElement>(const SVGElement& element) {
  return IsA<SVGFECompositeElement>(element);
}
template <>
struct DowncastTraits<SVGFECompositeElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFECompositeTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFECompositeElement>(To<SVGElement>(node));
  }
};

class SVGFEConvolveMatrixElement;
template <>
inline bool IsElementOfType<const SVGFEConvolveMatrixElement>(const Node& node) {
  return IsA<SVGFEConvolveMatrixElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEConvolveMatrixElement>(const SVGElement& element) {
  return IsA<SVGFEConvolveMatrixElement>(element);
}
template <>
struct DowncastTraits<SVGFEConvolveMatrixElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEConvolveMatrixTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEConvolveMatrixElement>(To<SVGElement>(node));
  }
};

class SVGFEDiffuseLightingElement;
template <>
inline bool IsElementOfType<const SVGFEDiffuseLightingElement>(const Node& node) {
  return IsA<SVGFEDiffuseLightingElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEDiffuseLightingElement>(const SVGElement& element) {
  return IsA<SVGFEDiffuseLightingElement>(element);
}
template <>
struct DowncastTraits<SVGFEDiffuseLightingElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEDiffuseLightingTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEDiffuseLightingElement>(To<SVGElement>(node));
  }
};

class SVGFEDisplacementMapElement;
template <>
inline bool IsElementOfType<const SVGFEDisplacementMapElement>(const Node& node) {
  return IsA<SVGFEDisplacementMapElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEDisplacementMapElement>(const SVGElement& element) {
  return IsA<SVGFEDisplacementMapElement>(element);
}
template <>
struct DowncastTraits<SVGFEDisplacementMapElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEDisplacementMapTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEDisplacementMapElement>(To<SVGElement>(node));
  }
};

class SVGFEDistantLightElement;
template <>
inline bool IsElementOfType<const SVGFEDistantLightElement>(const Node& node) {
  return IsA<SVGFEDistantLightElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEDistantLightElement>(const SVGElement& element) {
  return IsA<SVGFEDistantLightElement>(element);
}
template <>
struct DowncastTraits<SVGFEDistantLightElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEDistantLightTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEDistantLightElement>(To<SVGElement>(node));
  }
};

class SVGFEDropShadowElement;
template <>
inline bool IsElementOfType<const SVGFEDropShadowElement>(const Node& node) {
  return IsA<SVGFEDropShadowElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEDropShadowElement>(const SVGElement& element) {
  return IsA<SVGFEDropShadowElement>(element);
}
template <>
struct DowncastTraits<SVGFEDropShadowElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEDropShadowTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEDropShadowElement>(To<SVGElement>(node));
  }
};

class SVGFEFloodElement;
template <>
inline bool IsElementOfType<const SVGFEFloodElement>(const Node& node) {
  return IsA<SVGFEFloodElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEFloodElement>(const SVGElement& element) {
  return IsA<SVGFEFloodElement>(element);
}
template <>
struct DowncastTraits<SVGFEFloodElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEFloodTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEFloodElement>(To<SVGElement>(node));
  }
};

class SVGFEFuncAElement;
template <>
inline bool IsElementOfType<const SVGFEFuncAElement>(const Node& node) {
  return IsA<SVGFEFuncAElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEFuncAElement>(const SVGElement& element) {
  return IsA<SVGFEFuncAElement>(element);
}
template <>
struct DowncastTraits<SVGFEFuncAElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEFuncATag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEFuncAElement>(To<SVGElement>(node));
  }
};

class SVGFEFuncBElement;
template <>
inline bool IsElementOfType<const SVGFEFuncBElement>(const Node& node) {
  return IsA<SVGFEFuncBElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEFuncBElement>(const SVGElement& element) {
  return IsA<SVGFEFuncBElement>(element);
}
template <>
struct DowncastTraits<SVGFEFuncBElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEFuncBTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEFuncBElement>(To<SVGElement>(node));
  }
};

class SVGFEFuncGElement;
template <>
inline bool IsElementOfType<const SVGFEFuncGElement>(const Node& node) {
  return IsA<SVGFEFuncGElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEFuncGElement>(const SVGElement& element) {
  return IsA<SVGFEFuncGElement>(element);
}
template <>
struct DowncastTraits<SVGFEFuncGElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEFuncGTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEFuncGElement>(To<SVGElement>(node));
  }
};

class SVGFEFuncRElement;
template <>
inline bool IsElementOfType<const SVGFEFuncRElement>(const Node& node) {
  return IsA<SVGFEFuncRElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEFuncRElement>(const SVGElement& element) {
  return IsA<SVGFEFuncRElement>(element);
}
template <>
struct DowncastTraits<SVGFEFuncRElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEFuncRTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEFuncRElement>(To<SVGElement>(node));
  }
};

class SVGFEGaussianBlurElement;
template <>
inline bool IsElementOfType<const SVGFEGaussianBlurElement>(const Node& node) {
  return IsA<SVGFEGaussianBlurElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEGaussianBlurElement>(const SVGElement& element) {
  return IsA<SVGFEGaussianBlurElement>(element);
}
template <>
struct DowncastTraits<SVGFEGaussianBlurElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEGaussianBlurTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEGaussianBlurElement>(To<SVGElement>(node));
  }
};

class SVGFEImageElement;
template <>
inline bool IsElementOfType<const SVGFEImageElement>(const Node& node) {
  return IsA<SVGFEImageElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEImageElement>(const SVGElement& element) {
  return IsA<SVGFEImageElement>(element);
}
template <>
struct DowncastTraits<SVGFEImageElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEImageTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEImageElement>(To<SVGElement>(node));
  }
};

class SVGFEMergeElement;
template <>
inline bool IsElementOfType<const SVGFEMergeElement>(const Node& node) {
  return IsA<SVGFEMergeElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEMergeElement>(const SVGElement& element) {
  return IsA<SVGFEMergeElement>(element);
}
template <>
struct DowncastTraits<SVGFEMergeElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEMergeTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEMergeElement>(To<SVGElement>(node));
  }
};

class SVGFEMergeNodeElement;
template <>
inline bool IsElementOfType<const SVGFEMergeNodeElement>(const Node& node) {
  return IsA<SVGFEMergeNodeElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEMergeNodeElement>(const SVGElement& element) {
  return IsA<SVGFEMergeNodeElement>(element);
}
template <>
struct DowncastTraits<SVGFEMergeNodeElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEMergeNodeTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEMergeNodeElement>(To<SVGElement>(node));
  }
};

class SVGFEMorphologyElement;
template <>
inline bool IsElementOfType<const SVGFEMorphologyElement>(const Node& node) {
  return IsA<SVGFEMorphologyElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEMorphologyElement>(const SVGElement& element) {
  return IsA<SVGFEMorphologyElement>(element);
}
template <>
struct DowncastTraits<SVGFEMorphologyElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEMorphologyTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEMorphologyElement>(To<SVGElement>(node));
  }
};

class SVGFEOffsetElement;
template <>
inline bool IsElementOfType<const SVGFEOffsetElement>(const Node& node) {
  return IsA<SVGFEOffsetElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEOffsetElement>(const SVGElement& element) {
  return IsA<SVGFEOffsetElement>(element);
}
template <>
struct DowncastTraits<SVGFEOffsetElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEOffsetTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEOffsetElement>(To<SVGElement>(node));
  }
};

class SVGFEPointLightElement;
template <>
inline bool IsElementOfType<const SVGFEPointLightElement>(const Node& node) {
  return IsA<SVGFEPointLightElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFEPointLightElement>(const SVGElement& element) {
  return IsA<SVGFEPointLightElement>(element);
}
template <>
struct DowncastTraits<SVGFEPointLightElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFEPointLightTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFEPointLightElement>(To<SVGElement>(node));
  }
};

class SVGFESpecularLightingElement;
template <>
inline bool IsElementOfType<const SVGFESpecularLightingElement>(const Node& node) {
  return IsA<SVGFESpecularLightingElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFESpecularLightingElement>(const SVGElement& element) {
  return IsA<SVGFESpecularLightingElement>(element);
}
template <>
struct DowncastTraits<SVGFESpecularLightingElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFESpecularLightingTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFESpecularLightingElement>(To<SVGElement>(node));
  }
};

class SVGFESpotLightElement;
template <>
inline bool IsElementOfType<const SVGFESpotLightElement>(const Node& node) {
  return IsA<SVGFESpotLightElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFESpotLightElement>(const SVGElement& element) {
  return IsA<SVGFESpotLightElement>(element);
}
template <>
struct DowncastTraits<SVGFESpotLightElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFESpotLightTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFESpotLightElement>(To<SVGElement>(node));
  }
};

class SVGFETileElement;
template <>
inline bool IsElementOfType<const SVGFETileElement>(const Node& node) {
  return IsA<SVGFETileElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFETileElement>(const SVGElement& element) {
  return IsA<SVGFETileElement>(element);
}
template <>
struct DowncastTraits<SVGFETileElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFETileTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFETileElement>(To<SVGElement>(node));
  }
};

class SVGFETurbulenceElement;
template <>
inline bool IsElementOfType<const SVGFETurbulenceElement>(const Node& node) {
  return IsA<SVGFETurbulenceElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFETurbulenceElement>(const SVGElement& element) {
  return IsA<SVGFETurbulenceElement>(element);
}
template <>
struct DowncastTraits<SVGFETurbulenceElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFETurbulenceTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFETurbulenceElement>(To<SVGElement>(node));
  }
};

class SVGFilterElement;
template <>
inline bool IsElementOfType<const SVGFilterElement>(const Node& node) {
  return IsA<SVGFilterElement>(node);
}
template <>
inline bool IsElementOfType<const SVGFilterElement>(const SVGElement& element) {
  return IsA<SVGFilterElement>(element);
}
template <>
struct DowncastTraits<SVGFilterElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kFilterTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGFilterElement>(To<SVGElement>(node));
  }
};

class SVGForeignObjectElement;
template <>
inline bool IsElementOfType<const SVGForeignObjectElement>(const Node& node) {
  return IsA<SVGForeignObjectElement>(node);
}
template <>
inline bool IsElementOfType<const SVGForeignObjectElement>(const SVGElement& element) {
  return IsA<SVGForeignObjectElement>(element);
}
template <>
struct DowncastTraits<SVGForeignObjectElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kForeignObjectTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGForeignObjectElement>(To<SVGElement>(node));
  }
};

class SVGGElement;
template <>
inline bool IsElementOfType<const SVGGElement>(const Node& node) {
  return IsA<SVGGElement>(node);
}
template <>
inline bool IsElementOfType<const SVGGElement>(const SVGElement& element) {
  return IsA<SVGGElement>(element);
}
template <>
struct DowncastTraits<SVGGElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kGTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGGElement>(To<SVGElement>(node));
  }
};

class SVGImageElement;
template <>
inline bool IsElementOfType<const SVGImageElement>(const Node& node) {
  return IsA<SVGImageElement>(node);
}
template <>
inline bool IsElementOfType<const SVGImageElement>(const SVGElement& element) {
  return IsA<SVGImageElement>(element);
}
template <>
struct DowncastTraits<SVGImageElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kImageTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGImageElement>(To<SVGElement>(node));
  }
};

class SVGLineElement;
template <>
inline bool IsElementOfType<const SVGLineElement>(const Node& node) {
  return IsA<SVGLineElement>(node);
}
template <>
inline bool IsElementOfType<const SVGLineElement>(const SVGElement& element) {
  return IsA<SVGLineElement>(element);
}
template <>
struct DowncastTraits<SVGLineElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kLineTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGLineElement>(To<SVGElement>(node));
  }
};

class SVGLinearGradientElement;
template <>
inline bool IsElementOfType<const SVGLinearGradientElement>(const Node& node) {
  return IsA<SVGLinearGradientElement>(node);
}
template <>
inline bool IsElementOfType<const SVGLinearGradientElement>(const SVGElement& element) {
  return IsA<SVGLinearGradientElement>(element);
}
template <>
struct DowncastTraits<SVGLinearGradientElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kLinearGradientTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGLinearGradientElement>(To<SVGElement>(node));
  }
};

class SVGMPathElement;
template <>
inline bool IsElementOfType<const SVGMPathElement>(const Node& node) {
  return IsA<SVGMPathElement>(node);
}
template <>
inline bool IsElementOfType<const SVGMPathElement>(const SVGElement& element) {
  return IsA<SVGMPathElement>(element);
}
template <>
struct DowncastTraits<SVGMPathElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kMPathTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGMPathElement>(To<SVGElement>(node));
  }
};

class SVGMarkerElement;
template <>
inline bool IsElementOfType<const SVGMarkerElement>(const Node& node) {
  return IsA<SVGMarkerElement>(node);
}
template <>
inline bool IsElementOfType<const SVGMarkerElement>(const SVGElement& element) {
  return IsA<SVGMarkerElement>(element);
}
template <>
struct DowncastTraits<SVGMarkerElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kMarkerTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGMarkerElement>(To<SVGElement>(node));
  }
};

class SVGMaskElement;
template <>
inline bool IsElementOfType<const SVGMaskElement>(const Node& node) {
  return IsA<SVGMaskElement>(node);
}
template <>
inline bool IsElementOfType<const SVGMaskElement>(const SVGElement& element) {
  return IsA<SVGMaskElement>(element);
}
template <>
struct DowncastTraits<SVGMaskElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kMaskTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGMaskElement>(To<SVGElement>(node));
  }
};

class SVGMetadataElement;
template <>
inline bool IsElementOfType<const SVGMetadataElement>(const Node& node) {
  return IsA<SVGMetadataElement>(node);
}
template <>
inline bool IsElementOfType<const SVGMetadataElement>(const SVGElement& element) {
  return IsA<SVGMetadataElement>(element);
}
template <>
struct DowncastTraits<SVGMetadataElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kMetadataTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGMetadataElement>(To<SVGElement>(node));
  }
};

class SVGPathElement;
template <>
inline bool IsElementOfType<const SVGPathElement>(const Node& node) {
  return IsA<SVGPathElement>(node);
}
template <>
inline bool IsElementOfType<const SVGPathElement>(const SVGElement& element) {
  return IsA<SVGPathElement>(element);
}
template <>
struct DowncastTraits<SVGPathElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kPathTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGPathElement>(To<SVGElement>(node));
  }
};

class SVGPatternElement;
template <>
inline bool IsElementOfType<const SVGPatternElement>(const Node& node) {
  return IsA<SVGPatternElement>(node);
}
template <>
inline bool IsElementOfType<const SVGPatternElement>(const SVGElement& element) {
  return IsA<SVGPatternElement>(element);
}
template <>
struct DowncastTraits<SVGPatternElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kPatternTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGPatternElement>(To<SVGElement>(node));
  }
};

class SVGPolygonElement;
template <>
inline bool IsElementOfType<const SVGPolygonElement>(const Node& node) {
  return IsA<SVGPolygonElement>(node);
}
template <>
inline bool IsElementOfType<const SVGPolygonElement>(const SVGElement& element) {
  return IsA<SVGPolygonElement>(element);
}
template <>
struct DowncastTraits<SVGPolygonElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kPolygonTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGPolygonElement>(To<SVGElement>(node));
  }
};

class SVGPolylineElement;
template <>
inline bool IsElementOfType<const SVGPolylineElement>(const Node& node) {
  return IsA<SVGPolylineElement>(node);
}
template <>
inline bool IsElementOfType<const SVGPolylineElement>(const SVGElement& element) {
  return IsA<SVGPolylineElement>(element);
}
template <>
struct DowncastTraits<SVGPolylineElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kPolylineTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGPolylineElement>(To<SVGElement>(node));
  }
};

class SVGRadialGradientElement;
template <>
inline bool IsElementOfType<const SVGRadialGradientElement>(const Node& node) {
  return IsA<SVGRadialGradientElement>(node);
}
template <>
inline bool IsElementOfType<const SVGRadialGradientElement>(const SVGElement& element) {
  return IsA<SVGRadialGradientElement>(element);
}
template <>
struct DowncastTraits<SVGRadialGradientElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kRadialGradientTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGRadialGradientElement>(To<SVGElement>(node));
  }
};

class SVGRectElement;
template <>
inline bool IsElementOfType<const SVGRectElement>(const Node& node) {
  return IsA<SVGRectElement>(node);
}
template <>
inline bool IsElementOfType<const SVGRectElement>(const SVGElement& element) {
  return IsA<SVGRectElement>(element);
}
template <>
struct DowncastTraits<SVGRectElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kRectTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGRectElement>(To<SVGElement>(node));
  }
};

class SVGSVGElement;
template <>
inline bool IsElementOfType<const SVGSVGElement>(const Node& node) {
  return IsA<SVGSVGElement>(node);
}
template <>
inline bool IsElementOfType<const SVGSVGElement>(const SVGElement& element) {
  return IsA<SVGSVGElement>(element);
}
template <>
struct DowncastTraits<SVGSVGElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kSVGTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGSVGElement>(To<SVGElement>(node));
  }
};

class SVGSetElement;
template <>
inline bool IsElementOfType<const SVGSetElement>(const Node& node) {
  return IsA<SVGSetElement>(node);
}
template <>
inline bool IsElementOfType<const SVGSetElement>(const SVGElement& element) {
  return IsA<SVGSetElement>(element);
}
template <>
struct DowncastTraits<SVGSetElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kSetTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGSetElement>(To<SVGElement>(node));
  }
};

class SVGStopElement;
template <>
inline bool IsElementOfType<const SVGStopElement>(const Node& node) {
  return IsA<SVGStopElement>(node);
}
template <>
inline bool IsElementOfType<const SVGStopElement>(const SVGElement& element) {
  return IsA<SVGStopElement>(element);
}
template <>
struct DowncastTraits<SVGStopElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kStopTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGStopElement>(To<SVGElement>(node));
  }
};

class SVGSwitchElement;
template <>
inline bool IsElementOfType<const SVGSwitchElement>(const Node& node) {
  return IsA<SVGSwitchElement>(node);
}
template <>
inline bool IsElementOfType<const SVGSwitchElement>(const SVGElement& element) {
  return IsA<SVGSwitchElement>(element);
}
template <>
struct DowncastTraits<SVGSwitchElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kSwitchTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGSwitchElement>(To<SVGElement>(node));
  }
};

class SVGSymbolElement;
template <>
inline bool IsElementOfType<const SVGSymbolElement>(const Node& node) {
  return IsA<SVGSymbolElement>(node);
}
template <>
inline bool IsElementOfType<const SVGSymbolElement>(const SVGElement& element) {
  return IsA<SVGSymbolElement>(element);
}
template <>
struct DowncastTraits<SVGSymbolElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kSymbolTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGSymbolElement>(To<SVGElement>(node));
  }
};

class SVGTSpanElement;
template <>
inline bool IsElementOfType<const SVGTSpanElement>(const Node& node) {
  return IsA<SVGTSpanElement>(node);
}
template <>
inline bool IsElementOfType<const SVGTSpanElement>(const SVGElement& element) {
  return IsA<SVGTSpanElement>(element);
}
template <>
struct DowncastTraits<SVGTSpanElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kTSpanTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGTSpanElement>(To<SVGElement>(node));
  }
};

class SVGTextElement;
template <>
inline bool IsElementOfType<const SVGTextElement>(const Node& node) {
  return IsA<SVGTextElement>(node);
}
template <>
inline bool IsElementOfType<const SVGTextElement>(const SVGElement& element) {
  return IsA<SVGTextElement>(element);
}
template <>
struct DowncastTraits<SVGTextElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kTextTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGTextElement>(To<SVGElement>(node));
  }
};

class SVGTextPathElement;
template <>
inline bool IsElementOfType<const SVGTextPathElement>(const Node& node) {
  return IsA<SVGTextPathElement>(node);
}
template <>
inline bool IsElementOfType<const SVGTextPathElement>(const SVGElement& element) {
  return IsA<SVGTextPathElement>(element);
}
template <>
struct DowncastTraits<SVGTextPathElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kTextPathTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGTextPathElement>(To<SVGElement>(node));
  }
};

class SVGTitleElement;
template <>
inline bool IsElementOfType<const SVGTitleElement>(const Node& node) {
  return IsA<SVGTitleElement>(node);
}
template <>
inline bool IsElementOfType<const SVGTitleElement>(const SVGElement& element) {
  return IsA<SVGTitleElement>(element);
}
template <>
struct DowncastTraits<SVGTitleElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kTitleTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGTitleElement>(To<SVGElement>(node));
  }
};

class SVGUseElement;
template <>
inline bool IsElementOfType<const SVGUseElement>(const Node& node) {
  return IsA<SVGUseElement>(node);
}
template <>
inline bool IsElementOfType<const SVGUseElement>(const SVGElement& element) {
  return IsA<SVGUseElement>(element);
}
template <>
struct DowncastTraits<SVGUseElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kUseTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGUseElement>(To<SVGElement>(node));
  }
};

class SVGViewElement;
template <>
inline bool IsElementOfType<const SVGViewElement>(const Node& node) {
  return IsA<SVGViewElement>(node);
}
template <>
inline bool IsElementOfType<const SVGViewElement>(const SVGElement& element) {
  return IsA<SVGViewElement>(element);
}
template <>
struct DowncastTraits<SVGViewElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kViewTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGViewElement>(To<SVGElement>(node));
  }
};

class SVGScriptElement;
template <>
inline bool IsElementOfType<const SVGScriptElement>(const Node& node) {
  return IsA<SVGScriptElement>(node);
}
template <>
inline bool IsElementOfType<const SVGScriptElement>(const SVGElement& element) {
  return IsA<SVGScriptElement>(element);
}
template <>
struct DowncastTraits<SVGScriptElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kScriptTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGScriptElement>(To<SVGElement>(node));
  }
};

class SVGStyleElement;
template <>
inline bool IsElementOfType<const SVGStyleElement>(const Node& node) {
  return IsA<SVGStyleElement>(node);
}
template <>
inline bool IsElementOfType<const SVGStyleElement>(const SVGElement& element) {
  return IsA<SVGStyleElement>(element);
}
template <>
struct DowncastTraits<SVGStyleElement> {
  static bool AllowFrom(const Element& element) {
    return element.HasTagName(svg_names::kStyleTag);
  }
  static bool AllowFrom(const Node& node) {
    return node.IsSVGElement() && IsA<SVGStyleElement>(To<SVGElement>(node));
  }
};


}  // namespace blink

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_SVG_ELEMENT_TYPE_HELPERS_H_
