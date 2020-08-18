// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/devtools/domains/types_debugger.h"
#include "headless/public/devtools/domains/types_emulation.h"
#include "headless/public/devtools/domains/types_io.h"
#include "headless/public/devtools/domains/types_layer_tree.h"
#include "headless/public/devtools/domains/types_network.h"
#include "headless/public/devtools/domains/types_page.h"
#include "headless/public/devtools/domains/types_runtime.h"
#include "headless/public/devtools/domains/types_security.h"

#include "base/memory/ptr_util.h"
#include "headless/public/devtools/internal/type_conversions_dom.h"
#include "headless/public/devtools/internal/type_conversions_debugger.h"
#include "headless/public/devtools/internal/type_conversions_emulation.h"
#include "headless/public/devtools/internal/type_conversions_io.h"
#include "headless/public/devtools/internal/type_conversions_layer_tree.h"
#include "headless/public/devtools/internal/type_conversions_network.h"
#include "headless/public/devtools/internal/type_conversions_page.h"
#include "headless/public/devtools/internal/type_conversions_runtime.h"
#include "headless/public/devtools/internal/type_conversions_security.h"

namespace headless {

namespace layer_tree {

std::unique_ptr<ScrollRect> ScrollRect::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ScrollRect");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ScrollRect> result(new ScrollRect());
  errors->Push();
  errors->SetName("ScrollRect");
  const base::Value* rect_value = value.FindKey("rect");
  if (rect_value) {
    errors->SetName("rect");
    result->rect_ = internal::FromValue<::headless::dom::Rect>::Parse(*rect_value, errors);
  } else {
    errors->AddError("required property missing: rect");
  }
  const base::Value* type_value = value.FindKey("type");
  if (type_value) {
    errors->SetName("type");
    result->type_ = internal::FromValue<::headless::layer_tree::ScrollRectType>::Parse(*type_value, errors);
  } else {
    errors->AddError("required property missing: type");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ScrollRect::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("rect", internal::ToValue(*rect_));
  result->Set("type", internal::ToValue(type_));
  return std::move(result);
}

std::unique_ptr<ScrollRect> ScrollRect::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ScrollRect> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<StickyPositionConstraint> StickyPositionConstraint::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("StickyPositionConstraint");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<StickyPositionConstraint> result(new StickyPositionConstraint());
  errors->Push();
  errors->SetName("StickyPositionConstraint");
  const base::Value* sticky_box_rect_value = value.FindKey("stickyBoxRect");
  if (sticky_box_rect_value) {
    errors->SetName("stickyBoxRect");
    result->sticky_box_rect_ = internal::FromValue<::headless::dom::Rect>::Parse(*sticky_box_rect_value, errors);
  } else {
    errors->AddError("required property missing: stickyBoxRect");
  }
  const base::Value* containing_block_rect_value = value.FindKey("containingBlockRect");
  if (containing_block_rect_value) {
    errors->SetName("containingBlockRect");
    result->containing_block_rect_ = internal::FromValue<::headless::dom::Rect>::Parse(*containing_block_rect_value, errors);
  } else {
    errors->AddError("required property missing: containingBlockRect");
  }
  const base::Value* nearest_layer_shifting_sticky_box_value = value.FindKey("nearestLayerShiftingStickyBox");
  if (nearest_layer_shifting_sticky_box_value) {
    errors->SetName("nearestLayerShiftingStickyBox");
    result->nearest_layer_shifting_sticky_box_ = internal::FromValue<std::string>::Parse(*nearest_layer_shifting_sticky_box_value, errors);
  }
  const base::Value* nearest_layer_shifting_containing_block_value = value.FindKey("nearestLayerShiftingContainingBlock");
  if (nearest_layer_shifting_containing_block_value) {
    errors->SetName("nearestLayerShiftingContainingBlock");
    result->nearest_layer_shifting_containing_block_ = internal::FromValue<std::string>::Parse(*nearest_layer_shifting_containing_block_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> StickyPositionConstraint::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("stickyBoxRect", internal::ToValue(*sticky_box_rect_));
  result->Set("containingBlockRect", internal::ToValue(*containing_block_rect_));
  if (nearest_layer_shifting_sticky_box_)
    result->Set("nearestLayerShiftingStickyBox", internal::ToValue(nearest_layer_shifting_sticky_box_.value()));
  if (nearest_layer_shifting_containing_block_)
    result->Set("nearestLayerShiftingContainingBlock", internal::ToValue(nearest_layer_shifting_containing_block_.value()));
  return std::move(result);
}

std::unique_ptr<StickyPositionConstraint> StickyPositionConstraint::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<StickyPositionConstraint> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<PictureTile> PictureTile::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("PictureTile");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<PictureTile> result(new PictureTile());
  errors->Push();
  errors->SetName("PictureTile");
  const base::Value* x_value = value.FindKey("x");
  if (x_value) {
    errors->SetName("x");
    result->x_ = internal::FromValue<double>::Parse(*x_value, errors);
  } else {
    errors->AddError("required property missing: x");
  }
  const base::Value* y_value = value.FindKey("y");
  if (y_value) {
    errors->SetName("y");
    result->y_ = internal::FromValue<double>::Parse(*y_value, errors);
  } else {
    errors->AddError("required property missing: y");
  }
  const base::Value* picture_value = value.FindKey("picture");
  if (picture_value) {
    errors->SetName("picture");
    result->picture_ = internal::FromValue<protocol::Binary>::Parse(*picture_value, errors);
  } else {
    errors->AddError("required property missing: picture");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> PictureTile::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("x", internal::ToValue(x_));
  result->Set("y", internal::ToValue(y_));
  result->Set("picture", internal::ToValue(picture_));
  return std::move(result);
}

std::unique_ptr<PictureTile> PictureTile::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<PictureTile> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<Layer> Layer::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("Layer");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<Layer> result(new Layer());
  errors->Push();
  errors->SetName("Layer");
  const base::Value* layer_id_value = value.FindKey("layerId");
  if (layer_id_value) {
    errors->SetName("layerId");
    result->layer_id_ = internal::FromValue<std::string>::Parse(*layer_id_value, errors);
  } else {
    errors->AddError("required property missing: layerId");
  }
  const base::Value* parent_layer_id_value = value.FindKey("parentLayerId");
  if (parent_layer_id_value) {
    errors->SetName("parentLayerId");
    result->parent_layer_id_ = internal::FromValue<std::string>::Parse(*parent_layer_id_value, errors);
  }
  const base::Value* backend_node_id_value = value.FindKey("backendNodeId");
  if (backend_node_id_value) {
    errors->SetName("backendNodeId");
    result->backend_node_id_ = internal::FromValue<int>::Parse(*backend_node_id_value, errors);
  }
  const base::Value* offsetx_value = value.FindKey("offsetX");
  if (offsetx_value) {
    errors->SetName("offsetX");
    result->offsetx_ = internal::FromValue<double>::Parse(*offsetx_value, errors);
  } else {
    errors->AddError("required property missing: offsetX");
  }
  const base::Value* offsety_value = value.FindKey("offsetY");
  if (offsety_value) {
    errors->SetName("offsetY");
    result->offsety_ = internal::FromValue<double>::Parse(*offsety_value, errors);
  } else {
    errors->AddError("required property missing: offsetY");
  }
  const base::Value* width_value = value.FindKey("width");
  if (width_value) {
    errors->SetName("width");
    result->width_ = internal::FromValue<double>::Parse(*width_value, errors);
  } else {
    errors->AddError("required property missing: width");
  }
  const base::Value* height_value = value.FindKey("height");
  if (height_value) {
    errors->SetName("height");
    result->height_ = internal::FromValue<double>::Parse(*height_value, errors);
  } else {
    errors->AddError("required property missing: height");
  }
  const base::Value* transform_value = value.FindKey("transform");
  if (transform_value) {
    errors->SetName("transform");
    result->transform_ = internal::FromValue<std::vector<double>>::Parse(*transform_value, errors);
  }
  const base::Value* anchorx_value = value.FindKey("anchorX");
  if (anchorx_value) {
    errors->SetName("anchorX");
    result->anchorx_ = internal::FromValue<double>::Parse(*anchorx_value, errors);
  }
  const base::Value* anchory_value = value.FindKey("anchorY");
  if (anchory_value) {
    errors->SetName("anchorY");
    result->anchory_ = internal::FromValue<double>::Parse(*anchory_value, errors);
  }
  const base::Value* anchorz_value = value.FindKey("anchorZ");
  if (anchorz_value) {
    errors->SetName("anchorZ");
    result->anchorz_ = internal::FromValue<double>::Parse(*anchorz_value, errors);
  }
  const base::Value* paint_count_value = value.FindKey("paintCount");
  if (paint_count_value) {
    errors->SetName("paintCount");
    result->paint_count_ = internal::FromValue<int>::Parse(*paint_count_value, errors);
  } else {
    errors->AddError("required property missing: paintCount");
  }
  const base::Value* draws_content_value = value.FindKey("drawsContent");
  if (draws_content_value) {
    errors->SetName("drawsContent");
    result->draws_content_ = internal::FromValue<bool>::Parse(*draws_content_value, errors);
  } else {
    errors->AddError("required property missing: drawsContent");
  }
  const base::Value* invisible_value = value.FindKey("invisible");
  if (invisible_value) {
    errors->SetName("invisible");
    result->invisible_ = internal::FromValue<bool>::Parse(*invisible_value, errors);
  }
  const base::Value* scroll_rects_value = value.FindKey("scrollRects");
  if (scroll_rects_value) {
    errors->SetName("scrollRects");
    result->scroll_rects_ = internal::FromValue<std::vector<std::unique_ptr<::headless::layer_tree::ScrollRect>>>::Parse(*scroll_rects_value, errors);
  }
  const base::Value* sticky_position_constraint_value = value.FindKey("stickyPositionConstraint");
  if (sticky_position_constraint_value) {
    errors->SetName("stickyPositionConstraint");
    result->sticky_position_constraint_ = internal::FromValue<::headless::layer_tree::StickyPositionConstraint>::Parse(*sticky_position_constraint_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> Layer::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("layerId", internal::ToValue(layer_id_));
  if (parent_layer_id_)
    result->Set("parentLayerId", internal::ToValue(parent_layer_id_.value()));
  if (backend_node_id_)
    result->Set("backendNodeId", internal::ToValue(backend_node_id_.value()));
  result->Set("offsetX", internal::ToValue(offsetx_));
  result->Set("offsetY", internal::ToValue(offsety_));
  result->Set("width", internal::ToValue(width_));
  result->Set("height", internal::ToValue(height_));
  if (transform_)
    result->Set("transform", internal::ToValue(transform_.value()));
  if (anchorx_)
    result->Set("anchorX", internal::ToValue(anchorx_.value()));
  if (anchory_)
    result->Set("anchorY", internal::ToValue(anchory_.value()));
  if (anchorz_)
    result->Set("anchorZ", internal::ToValue(anchorz_.value()));
  result->Set("paintCount", internal::ToValue(paint_count_));
  result->Set("drawsContent", internal::ToValue(draws_content_));
  if (invisible_)
    result->Set("invisible", internal::ToValue(invisible_.value()));
  if (scroll_rects_)
    result->Set("scrollRects", internal::ToValue(scroll_rects_.value()));
  if (sticky_position_constraint_)
    result->Set("stickyPositionConstraint", internal::ToValue(*sticky_position_constraint_.value()));
  return std::move(result);
}

std::unique_ptr<Layer> Layer::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<Layer> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CompositingReasonsParams> CompositingReasonsParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CompositingReasonsParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CompositingReasonsParams> result(new CompositingReasonsParams());
  errors->Push();
  errors->SetName("CompositingReasonsParams");
  const base::Value* layer_id_value = value.FindKey("layerId");
  if (layer_id_value) {
    errors->SetName("layerId");
    result->layer_id_ = internal::FromValue<std::string>::Parse(*layer_id_value, errors);
  } else {
    errors->AddError("required property missing: layerId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CompositingReasonsParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("layerId", internal::ToValue(layer_id_));
  return std::move(result);
}

std::unique_ptr<CompositingReasonsParams> CompositingReasonsParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CompositingReasonsParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<CompositingReasonsResult> CompositingReasonsResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("CompositingReasonsResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<CompositingReasonsResult> result(new CompositingReasonsResult());
  errors->Push();
  errors->SetName("CompositingReasonsResult");
  const base::Value* compositing_reasons_value = value.FindKey("compositingReasons");
  if (compositing_reasons_value) {
    errors->SetName("compositingReasons");
    result->compositing_reasons_ = internal::FromValue<std::vector<std::string>>::Parse(*compositing_reasons_value, errors);
  } else {
    errors->AddError("required property missing: compositingReasons");
  }
  const base::Value* compositing_reason_ids_value = value.FindKey("compositingReasonIds");
  if (compositing_reason_ids_value) {
    errors->SetName("compositingReasonIds");
    result->compositing_reason_ids_ = internal::FromValue<std::vector<std::string>>::Parse(*compositing_reason_ids_value, errors);
  } else {
    errors->AddError("required property missing: compositingReasonIds");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> CompositingReasonsResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("compositingReasons", internal::ToValue(compositing_reasons_));
  result->Set("compositingReasonIds", internal::ToValue(compositing_reason_ids_));
  return std::move(result);
}

std::unique_ptr<CompositingReasonsResult> CompositingReasonsResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<CompositingReasonsResult> result = Parse(*Serialize(), &errors);
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


std::unique_ptr<LoadSnapshotParams> LoadSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LoadSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LoadSnapshotParams> result(new LoadSnapshotParams());
  errors->Push();
  errors->SetName("LoadSnapshotParams");
  const base::Value* tiles_value = value.FindKey("tiles");
  if (tiles_value) {
    errors->SetName("tiles");
    result->tiles_ = internal::FromValue<std::vector<std::unique_ptr<::headless::layer_tree::PictureTile>>>::Parse(*tiles_value, errors);
  } else {
    errors->AddError("required property missing: tiles");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LoadSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("tiles", internal::ToValue(tiles_));
  return std::move(result);
}

std::unique_ptr<LoadSnapshotParams> LoadSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LoadSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LoadSnapshotResult> LoadSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LoadSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LoadSnapshotResult> result(new LoadSnapshotResult());
  errors->Push();
  errors->SetName("LoadSnapshotResult");
  const base::Value* snapshot_id_value = value.FindKey("snapshotId");
  if (snapshot_id_value) {
    errors->SetName("snapshotId");
    result->snapshot_id_ = internal::FromValue<std::string>::Parse(*snapshot_id_value, errors);
  } else {
    errors->AddError("required property missing: snapshotId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LoadSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("snapshotId", internal::ToValue(snapshot_id_));
  return std::move(result);
}

std::unique_ptr<LoadSnapshotResult> LoadSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LoadSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MakeSnapshotParams> MakeSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MakeSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MakeSnapshotParams> result(new MakeSnapshotParams());
  errors->Push();
  errors->SetName("MakeSnapshotParams");
  const base::Value* layer_id_value = value.FindKey("layerId");
  if (layer_id_value) {
    errors->SetName("layerId");
    result->layer_id_ = internal::FromValue<std::string>::Parse(*layer_id_value, errors);
  } else {
    errors->AddError("required property missing: layerId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MakeSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("layerId", internal::ToValue(layer_id_));
  return std::move(result);
}

std::unique_ptr<MakeSnapshotParams> MakeSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MakeSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<MakeSnapshotResult> MakeSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("MakeSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<MakeSnapshotResult> result(new MakeSnapshotResult());
  errors->Push();
  errors->SetName("MakeSnapshotResult");
  const base::Value* snapshot_id_value = value.FindKey("snapshotId");
  if (snapshot_id_value) {
    errors->SetName("snapshotId");
    result->snapshot_id_ = internal::FromValue<std::string>::Parse(*snapshot_id_value, errors);
  } else {
    errors->AddError("required property missing: snapshotId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> MakeSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("snapshotId", internal::ToValue(snapshot_id_));
  return std::move(result);
}

std::unique_ptr<MakeSnapshotResult> MakeSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<MakeSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ProfileSnapshotParams> ProfileSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ProfileSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ProfileSnapshotParams> result(new ProfileSnapshotParams());
  errors->Push();
  errors->SetName("ProfileSnapshotParams");
  const base::Value* snapshot_id_value = value.FindKey("snapshotId");
  if (snapshot_id_value) {
    errors->SetName("snapshotId");
    result->snapshot_id_ = internal::FromValue<std::string>::Parse(*snapshot_id_value, errors);
  } else {
    errors->AddError("required property missing: snapshotId");
  }
  const base::Value* min_repeat_count_value = value.FindKey("minRepeatCount");
  if (min_repeat_count_value) {
    errors->SetName("minRepeatCount");
    result->min_repeat_count_ = internal::FromValue<int>::Parse(*min_repeat_count_value, errors);
  }
  const base::Value* min_duration_value = value.FindKey("minDuration");
  if (min_duration_value) {
    errors->SetName("minDuration");
    result->min_duration_ = internal::FromValue<double>::Parse(*min_duration_value, errors);
  }
  const base::Value* clip_rect_value = value.FindKey("clipRect");
  if (clip_rect_value) {
    errors->SetName("clipRect");
    result->clip_rect_ = internal::FromValue<::headless::dom::Rect>::Parse(*clip_rect_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ProfileSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("snapshotId", internal::ToValue(snapshot_id_));
  if (min_repeat_count_)
    result->Set("minRepeatCount", internal::ToValue(min_repeat_count_.value()));
  if (min_duration_)
    result->Set("minDuration", internal::ToValue(min_duration_.value()));
  if (clip_rect_)
    result->Set("clipRect", internal::ToValue(*clip_rect_.value()));
  return std::move(result);
}

std::unique_ptr<ProfileSnapshotParams> ProfileSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ProfileSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ProfileSnapshotResult> ProfileSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ProfileSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ProfileSnapshotResult> result(new ProfileSnapshotResult());
  errors->Push();
  errors->SetName("ProfileSnapshotResult");
  const base::Value* timings_value = value.FindKey("timings");
  if (timings_value) {
    errors->SetName("timings");
    result->timings_ = internal::FromValue<std::vector<std::vector<double>>>::Parse(*timings_value, errors);
  } else {
    errors->AddError("required property missing: timings");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ProfileSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("timings", internal::ToValue(timings_));
  return std::move(result);
}

std::unique_ptr<ProfileSnapshotResult> ProfileSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ProfileSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseSnapshotParams> ReleaseSnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseSnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseSnapshotParams> result(new ReleaseSnapshotParams());
  errors->Push();
  errors->SetName("ReleaseSnapshotParams");
  const base::Value* snapshot_id_value = value.FindKey("snapshotId");
  if (snapshot_id_value) {
    errors->SetName("snapshotId");
    result->snapshot_id_ = internal::FromValue<std::string>::Parse(*snapshot_id_value, errors);
  } else {
    errors->AddError("required property missing: snapshotId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseSnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("snapshotId", internal::ToValue(snapshot_id_));
  return std::move(result);
}

std::unique_ptr<ReleaseSnapshotParams> ReleaseSnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseSnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReleaseSnapshotResult> ReleaseSnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReleaseSnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReleaseSnapshotResult> result(new ReleaseSnapshotResult());
  errors->Push();
  errors->SetName("ReleaseSnapshotResult");
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReleaseSnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  return std::move(result);
}

std::unique_ptr<ReleaseSnapshotResult> ReleaseSnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReleaseSnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReplaySnapshotParams> ReplaySnapshotParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReplaySnapshotParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReplaySnapshotParams> result(new ReplaySnapshotParams());
  errors->Push();
  errors->SetName("ReplaySnapshotParams");
  const base::Value* snapshot_id_value = value.FindKey("snapshotId");
  if (snapshot_id_value) {
    errors->SetName("snapshotId");
    result->snapshot_id_ = internal::FromValue<std::string>::Parse(*snapshot_id_value, errors);
  } else {
    errors->AddError("required property missing: snapshotId");
  }
  const base::Value* from_step_value = value.FindKey("fromStep");
  if (from_step_value) {
    errors->SetName("fromStep");
    result->from_step_ = internal::FromValue<int>::Parse(*from_step_value, errors);
  }
  const base::Value* to_step_value = value.FindKey("toStep");
  if (to_step_value) {
    errors->SetName("toStep");
    result->to_step_ = internal::FromValue<int>::Parse(*to_step_value, errors);
  }
  const base::Value* scale_value = value.FindKey("scale");
  if (scale_value) {
    errors->SetName("scale");
    result->scale_ = internal::FromValue<double>::Parse(*scale_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReplaySnapshotParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("snapshotId", internal::ToValue(snapshot_id_));
  if (from_step_)
    result->Set("fromStep", internal::ToValue(from_step_.value()));
  if (to_step_)
    result->Set("toStep", internal::ToValue(to_step_.value()));
  if (scale_)
    result->Set("scale", internal::ToValue(scale_.value()));
  return std::move(result);
}

std::unique_ptr<ReplaySnapshotParams> ReplaySnapshotParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReplaySnapshotParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<ReplaySnapshotResult> ReplaySnapshotResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("ReplaySnapshotResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<ReplaySnapshotResult> result(new ReplaySnapshotResult());
  errors->Push();
  errors->SetName("ReplaySnapshotResult");
  const base::Value* dataurl_value = value.FindKey("dataURL");
  if (dataurl_value) {
    errors->SetName("dataURL");
    result->dataurl_ = internal::FromValue<std::string>::Parse(*dataurl_value, errors);
  } else {
    errors->AddError("required property missing: dataURL");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> ReplaySnapshotResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("dataURL", internal::ToValue(dataurl_));
  return std::move(result);
}

std::unique_ptr<ReplaySnapshotResult> ReplaySnapshotResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<ReplaySnapshotResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SnapshotCommandLogParams> SnapshotCommandLogParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SnapshotCommandLogParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SnapshotCommandLogParams> result(new SnapshotCommandLogParams());
  errors->Push();
  errors->SetName("SnapshotCommandLogParams");
  const base::Value* snapshot_id_value = value.FindKey("snapshotId");
  if (snapshot_id_value) {
    errors->SetName("snapshotId");
    result->snapshot_id_ = internal::FromValue<std::string>::Parse(*snapshot_id_value, errors);
  } else {
    errors->AddError("required property missing: snapshotId");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SnapshotCommandLogParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("snapshotId", internal::ToValue(snapshot_id_));
  return std::move(result);
}

std::unique_ptr<SnapshotCommandLogParams> SnapshotCommandLogParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SnapshotCommandLogParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<SnapshotCommandLogResult> SnapshotCommandLogResult::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("SnapshotCommandLogResult");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<SnapshotCommandLogResult> result(new SnapshotCommandLogResult());
  errors->Push();
  errors->SetName("SnapshotCommandLogResult");
  const base::Value* command_log_value = value.FindKey("commandLog");
  if (command_log_value) {
    errors->SetName("commandLog");
    result->command_log_ = internal::FromValue<std::vector<std::unique_ptr<base::Value>>>::Parse(*command_log_value, errors);
  } else {
    errors->AddError("required property missing: commandLog");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> SnapshotCommandLogResult::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("commandLog", internal::ToValue(command_log_));
  return std::move(result);
}

std::unique_ptr<SnapshotCommandLogResult> SnapshotCommandLogResult::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<SnapshotCommandLogResult> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LayerPaintedParams> LayerPaintedParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LayerPaintedParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LayerPaintedParams> result(new LayerPaintedParams());
  errors->Push();
  errors->SetName("LayerPaintedParams");
  const base::Value* layer_id_value = value.FindKey("layerId");
  if (layer_id_value) {
    errors->SetName("layerId");
    result->layer_id_ = internal::FromValue<std::string>::Parse(*layer_id_value, errors);
  } else {
    errors->AddError("required property missing: layerId");
  }
  const base::Value* clip_value = value.FindKey("clip");
  if (clip_value) {
    errors->SetName("clip");
    result->clip_ = internal::FromValue<::headless::dom::Rect>::Parse(*clip_value, errors);
  } else {
    errors->AddError("required property missing: clip");
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LayerPaintedParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  result->Set("layerId", internal::ToValue(layer_id_));
  result->Set("clip", internal::ToValue(*clip_));
  return std::move(result);
}

std::unique_ptr<LayerPaintedParams> LayerPaintedParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LayerPaintedParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


std::unique_ptr<LayerTreeDidChangeParams> LayerTreeDidChangeParams::Parse(const base::Value& value, ErrorReporter* errors) {
  errors->Push();
  errors->SetName("LayerTreeDidChangeParams");
  if (!value.is_dict()) {
    errors->AddError("object expected");
    errors->Pop();
    return nullptr;
  }

  std::unique_ptr<LayerTreeDidChangeParams> result(new LayerTreeDidChangeParams());
  errors->Push();
  errors->SetName("LayerTreeDidChangeParams");
  const base::Value* layers_value = value.FindKey("layers");
  if (layers_value) {
    errors->SetName("layers");
    result->layers_ = internal::FromValue<std::vector<std::unique_ptr<::headless::layer_tree::Layer>>>::Parse(*layers_value, errors);
  }
  errors->Pop();
  errors->Pop();
  if (errors->HasErrors())
    return nullptr;
  return result;
}

std::unique_ptr<base::Value> LayerTreeDidChangeParams::Serialize() const {
  std::unique_ptr<base::DictionaryValue> result(new base::DictionaryValue());
  if (layers_)
    result->Set("layers", internal::ToValue(layers_.value()));
  return std::move(result);
}

std::unique_ptr<LayerTreeDidChangeParams> LayerTreeDidChangeParams::Clone() const {
  ErrorReporter errors;
  std::unique_ptr<LayerTreeDidChangeParams> result = Parse(*Serialize(), &errors);
  DCHECK(!errors.HasErrors());
  return result;
}


}  // namespace layer_tree
}  // namespace headless
