// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_factory.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/mathml/mathml_attribute_names.json5
//   ../../third_party/blink/renderer/core/mathml/mathml_tag_names.json5


#include "third_party/blink/renderer/core/mathml_element_factory.h"

#include "base/stl_util.h"  // for base::size()
#include "third_party/blink/renderer/core/mathml_names.h"
#include "third_party/blink/renderer/core/mathml/mathml_element.h"
#include "third_party/blink/renderer/core/mathml/mathml_fraction_element.h"
#include "third_party/blink/renderer/core/mathml/mathml_row_element.h"
#include "third_party/blink/renderer/core/mathml/mathml_scripts_element.h"
#include "third_party/blink/renderer/core/mathml/mathml_space_element.h"
#include "third_party/blink/renderer/core/mathml/mathml_under_over_element.h"
#include "third_party/blink/renderer/core/mathml/mathml_row_element.h"
#include "third_party/blink/renderer/platform/heap/heap.h"
#include "third_party/blink/renderer/platform/runtime_enabled_features.h"
#include "third_party/blink/renderer/platform/wtf/hash_map.h"

namespace blink {

using MathMLConstructorFunction = MathMLElement* (*)(
    Document&, const CreateElementFlags);

using MathMLFunctionMap = HashMap<AtomicString, MathMLConstructorFunction>;

static MathMLFunctionMap* g_mathml_constructors = nullptr;

static MathMLElement* MathMLAnnotationConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kAnnotationTag, document);
}
static MathMLElement* MathMLAnnotationXmlConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kAnnotationXmlTag, document);
}
static MathMLElement* MathMLMalignmarkConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMalignmarkTag, document);
}
static MathMLElement* MathMLMglyphConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMglyphTag, document);
}
static MathMLElement* MathMLMiConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMiTag, document);
}
static MathMLElement* MathMLMnConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMnTag, document);
}
static MathMLElement* MathMLMoConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMoTag, document);
}
static MathMLElement* MathMLMsConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMsTag, document);
}
static MathMLElement* MathMLMtextConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLElement>(mathml_names::kMtextTag, document);
}
static MathMLElement* MathMLMfracConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLFractionElement>(document);
}
static MathMLElement* MathMLMactionConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kMactionTag, document);
}
static MathMLElement* MathMLMathConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kMathTag, document);
}
static MathMLElement* MathMLMerrorConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kMerrorTag, document);
}
static MathMLElement* MathMLMphantomConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kMphantomTag, document);
}
static MathMLElement* MathMLMrowConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kMrowTag, document);
}
static MathMLElement* MathMLMstyleConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kMstyleTag, document);
}
static MathMLElement* MathMLSemanticsConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLRowElement>(mathml_names::kSemanticsTag, document);
}
static MathMLElement* MathMLMsubConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLScriptsElement>(mathml_names::kMsubTag, document);
}
static MathMLElement* MathMLMsubsupConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLScriptsElement>(mathml_names::kMsubsupTag, document);
}
static MathMLElement* MathMLMsupConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLScriptsElement>(mathml_names::kMsupTag, document);
}
static MathMLElement* MathMLMspaceConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLSpaceElement>(document);
}
static MathMLElement* MathMLMoverConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLUnderOverElement>(mathml_names::kMoverTag, document);
}
static MathMLElement* MathMLMunderConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLUnderOverElement>(mathml_names::kMunderTag, document);
}
static MathMLElement* MathMLMunderoverConstructor(
    Document& document, const CreateElementFlags flags) {
  return MakeGarbageCollected<MathMLUnderOverElement>(mathml_names::kMunderoverTag, document);
}

struct CreateMathMLFunctionMapData {
  const QualifiedName& tag;
  MathMLConstructorFunction func;
};

static void CreateMathMLFunctionMap() {
  DCHECK(!g_mathml_constructors);
  g_mathml_constructors = new MathMLFunctionMap;
  // Empty array initializer lists are illegal [dcl.init.aggr] and will not
  // compile in MSVC. If tags list is empty, add check to skip this.
  static const CreateMathMLFunctionMapData data[] = {
    { mathml_names::kAnnotationTag, MathMLAnnotationConstructor },
    { mathml_names::kAnnotationXmlTag, MathMLAnnotationXmlConstructor },
    { mathml_names::kMalignmarkTag, MathMLMalignmarkConstructor },
    { mathml_names::kMglyphTag, MathMLMglyphConstructor },
    { mathml_names::kMiTag, MathMLMiConstructor },
    { mathml_names::kMnTag, MathMLMnConstructor },
    { mathml_names::kMoTag, MathMLMoConstructor },
    { mathml_names::kMsTag, MathMLMsConstructor },
    { mathml_names::kMtextTag, MathMLMtextConstructor },
    { mathml_names::kMfracTag, MathMLMfracConstructor },
    { mathml_names::kMactionTag, MathMLMactionConstructor },
    { mathml_names::kMathTag, MathMLMathConstructor },
    { mathml_names::kMerrorTag, MathMLMerrorConstructor },
    { mathml_names::kMphantomTag, MathMLMphantomConstructor },
    { mathml_names::kMrowTag, MathMLMrowConstructor },
    { mathml_names::kMstyleTag, MathMLMstyleConstructor },
    { mathml_names::kSemanticsTag, MathMLSemanticsConstructor },
    { mathml_names::kMsubTag, MathMLMsubConstructor },
    { mathml_names::kMsubsupTag, MathMLMsubsupConstructor },
    { mathml_names::kMsupTag, MathMLMsupConstructor },
    { mathml_names::kMspaceTag, MathMLMspaceConstructor },
    { mathml_names::kMoverTag, MathMLMoverConstructor },
    { mathml_names::kMunderTag, MathMLMunderConstructor },
    { mathml_names::kMunderoverTag, MathMLMunderoverConstructor },
  };
  for (size_t i = 0; i < base::size(data); i++)
    g_mathml_constructors->Set(data[i].tag.LocalName(), data[i].func);
}

MathMLElement* MathMLElementFactory::Create(
    const AtomicString& local_name,
    Document& document,
    const CreateElementFlags flags) {
  if (!g_mathml_constructors)
    CreateMathMLFunctionMap();
  if (MathMLConstructorFunction function = g_mathml_constructors->at(local_name))
    return function(document, flags);
  return nullptr;
}

}  // namespace blink
