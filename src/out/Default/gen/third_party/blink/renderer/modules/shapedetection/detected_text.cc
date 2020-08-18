// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated from the Jinja2 template
// third_party/blink/renderer/bindings/templates/dictionary_impl.cc.tmpl
// by the script code_generator_v8.py.
// DO NOT MODIFY!

// clang-format off
#include "third_party/blink/renderer/modules/shapedetection/detected_text.h"

#include "third_party/blink/renderer/core/geometry/dom_rect_read_only.h"
#include "third_party/blink/renderer/modules/imagecapture/point_2d.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"

namespace blink {

DetectedText::DetectedText() {
}

DetectedText::~DetectedText() = default;

void DetectedText::setCornerPoints(const HeapVector<Member<Point2D>>& value) {
  corner_points_ = value;
  has_corner_points_ = true;
}

void DetectedText::Trace(Visitor* visitor) const {
  visitor->Trace(bounding_box_);
  visitor->Trace(corner_points_);
  IDLDictionaryBase::Trace(visitor);
}

}  // namespace blink
