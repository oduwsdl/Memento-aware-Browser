// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_qualified_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/mathml/mathml_attribute_names.json5
//   ../../third_party/blink/renderer/core/mathml/mathml_tag_names.json5


#include "third_party/blink/renderer/core/mathml_names.h"

#include <memory>

#include "base/stl_util.h"  // for base::size()
#include "third_party/blink/renderer/platform/wtf/static_constructors.h"
#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"

namespace blink {
namespace mathml_names {

DEFINE_GLOBAL(AtomicString, kNamespaceURI);

// Tags

void* tag_storage[kTagsCount * ((sizeof(MathMLQualifiedName) + sizeof(void *) - 1) / sizeof(void *))];
const MathMLQualifiedName& kAnnotationTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[0];
const MathMLQualifiedName& kAnnotationXmlTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[1];
const MathMLQualifiedName& kMactionTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[2];
const MathMLQualifiedName& kMalignmarkTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[3];
const MathMLQualifiedName& kMathTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[4];
const MathMLQualifiedName& kMerrorTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[5];
const MathMLQualifiedName& kMfracTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[6];
const MathMLQualifiedName& kMglyphTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[7];
const MathMLQualifiedName& kMiTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[8];
const MathMLQualifiedName& kMnTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[9];
const MathMLQualifiedName& kMoTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[10];
const MathMLQualifiedName& kMoverTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[11];
const MathMLQualifiedName& kMphantomTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[12];
const MathMLQualifiedName& kMrowTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[13];
const MathMLQualifiedName& kMsTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[14];
const MathMLQualifiedName& kMspaceTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[15];
const MathMLQualifiedName& kMstyleTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[16];
const MathMLQualifiedName& kMsubTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[17];
const MathMLQualifiedName& kMsubsupTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[18];
const MathMLQualifiedName& kMsupTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[19];
const MathMLQualifiedName& kMtextTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[20];
const MathMLQualifiedName& kMunderTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[21];
const MathMLQualifiedName& kMunderoverTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[22];
const MathMLQualifiedName& kSemanticsTag = reinterpret_cast<MathMLQualifiedName*>(&tag_storage)[23];


std::unique_ptr<const MathMLQualifiedName*[]> GetTags() {
  auto tags = std::make_unique<const MathMLQualifiedName*[]>(kTagsCount);
  for (size_t i = 0; i < kTagsCount; ++i)
    tags[i] = reinterpret_cast<MathMLQualifiedName*>(&tag_storage) + i;
  return tags;
}

// Attributes

void* attr_storage[kAttrsCount * ((sizeof(QualifiedName) + sizeof(void *) - 1) / sizeof(void *))];

const QualifiedName& kDefinitionURLAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[0];
const QualifiedName& kDepthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[1];
const QualifiedName& kDisplayAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[2];
const QualifiedName& kDisplaystyleAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[3];
const QualifiedName& kEncodingAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[4];
const QualifiedName& kHeightAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[5];
const QualifiedName& kLinethicknessAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[6];
const QualifiedName& kMathbackgroundAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[7];
const QualifiedName& kMathcolorAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[8];
const QualifiedName& kMathsizeAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[9];
const QualifiedName& kMathvariantAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[10];
const QualifiedName& kScriptlevelAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[11];
const QualifiedName& kWidthAttr = reinterpret_cast<QualifiedName*>(&attr_storage)[12];

std::unique_ptr<const QualifiedName*[]> GetAttrs() {
  auto attrs = std::make_unique<const QualifiedName*[]>(kAttrsCount);
  for (size_t i = 0; i < kAttrsCount; ++i)
    attrs[i] = reinterpret_cast<QualifiedName*>(&attr_storage) + i;
  return attrs;
}


void Init() {
  struct NameEntry {
    const char* name;
    unsigned hash;
    unsigned char length;
    unsigned char is_tag;
    unsigned char is_attr;
  };

  // Namespace
  // Use placement new to initialize the globals.
  AtomicString ns_uri("http://www.w3.org/1998/Math/MathML");
  new ((void*)&kNamespaceURI) AtomicString(ns_uri);

  static const NameEntry kNames[] = {
    { "annotation", 10691270, 10, 1, 0 },
    { "annotation-xml", 3437210, 14, 1, 0 },
    { "definitionURL", 5781331, 13, 0, 1 },
    { "depth", 1069503, 5, 0, 1 },
    { "display", 16245385, 7, 0, 1 },
    { "displaystyle", 92854, 12, 0, 1 },
    { "encoding", 641915, 8, 0, 1 },
    { "height", 6697833, 6, 0, 1 },
    { "linethickness", 7924943, 13, 0, 1 },
    { "maction", 6240554, 7, 1, 0 },
    { "malignmark", 8634190, 10, 1, 0 },
    { "math", 8182406, 4, 1, 0 },
    { "mathbackground", 2374557, 14, 0, 1 },
    { "mathcolor", 7904383, 9, 0, 1 },
    { "mathsize", 6623078, 8, 0, 1 },
    { "mathvariant", 9126505, 11, 0, 1 },
    { "merror", 7632997, 6, 1, 0 },
    { "mfrac", 13987551, 5, 1, 0 },
    { "mglyph", 3316076, 6, 1, 0 },
    { "mi", 16514040, 2, 1, 0 },
    { "mn", 3612898, 2, 1, 0 },
    { "mo", 16096753, 2, 1, 0 },
    { "mover", 14480316, 5, 1, 0 },
    { "mphantom", 6126615, 8, 1, 0 },
    { "mrow", 8502371, 4, 1, 0 },
    { "ms", 5264856, 2, 1, 0 },
    { "mspace", 10653811, 6, 1, 0 },
    { "mstyle", 6243427, 6, 1, 0 },
    { "msub", 10093770, 4, 1, 0 },
    { "msubsup", 5166195, 7, 1, 0 },
    { "msup", 1894901, 4, 1, 0 },
    { "mtext", 16756693, 5, 1, 0 },
    { "munder", 9958019, 6, 1, 0 },
    { "munderover", 5849942, 10, 1, 0 },
    { "scriptlevel", 5324426, 11, 0, 1 },
    { "semantics", 942856, 9, 1, 0 },
    { "width", 12902275, 5, 0, 1 },
  };

  size_t tag_i = 0;
  size_t attr_i = 0;
  for (size_t i = 0; i < base::size(kNames); ++i) {
    StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
    if (kNames[i].is_tag) {
      void* address = reinterpret_cast<MathMLQualifiedName*>(&tag_storage) + tag_i;
      QualifiedName::CreateStatic(address, impl, ns_uri);
      ++tag_i;
    }

    if (!kNames[i].is_attr)
      continue;
    void* address = reinterpret_cast<QualifiedName*>(&attr_storage) + attr_i;
    QualifiedName::CreateStatic(address, impl);
    ++attr_i;
  }
  DCHECK_EQ(tag_i, kTagsCount);
  DCHECK_EQ(attr_i, kAttrsCount);
}

}  // namespace mathml_names
}  // namespace blink
