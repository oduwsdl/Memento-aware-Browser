// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_LAYER_TREE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_LAYER_TREE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_layer_tree.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace layer_tree {

// Rectangle where scrolling happens on the main thread.
class HEADLESS_EXPORT ScrollRect {
 public:
  static std::unique_ptr<ScrollRect> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScrollRect() { }

  // Rectangle itself.
  const ::headless::dom::Rect* GetRect() const { return rect_.get(); }
  void SetRect(std::unique_ptr<::headless::dom::Rect> value) { rect_ = std::move(value); }

  // Reason for rectangle to force scrolling on the main thread
  ::headless::layer_tree::ScrollRectType GetType() const { return type_; }
  void SetType(::headless::layer_tree::ScrollRectType value) { type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScrollRect> Clone() const;

  template<int STATE>
  class ScrollRectBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kRectSet = 1 << 1,
    kTypeSet = 1 << 2,
      kAllRequiredFieldsSet = (kRectSet | kTypeSet | 0)
    };

    ScrollRectBuilder<STATE | kRectSet>& SetRect(std::unique_ptr<::headless::dom::Rect> value) {
      static_assert(!(STATE & kRectSet), "property rect should not have already been set");
      result_->SetRect(std::move(value));
      return CastState<kRectSet>();
    }

    ScrollRectBuilder<STATE | kTypeSet>& SetType(::headless::layer_tree::ScrollRectType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    std::unique_ptr<ScrollRect> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScrollRect;
    ScrollRectBuilder() : result_(new ScrollRect()) { }

    template<int STEP> ScrollRectBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScrollRectBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScrollRect> result_;
  };

  static ScrollRectBuilder<0> Builder() {
    return ScrollRectBuilder<0>();
  }

 private:
  ScrollRect() { }

  std::unique_ptr<::headless::dom::Rect> rect_;
  ::headless::layer_tree::ScrollRectType type_;

  DISALLOW_COPY_AND_ASSIGN(ScrollRect);
};


// Sticky position constraints.
class HEADLESS_EXPORT StickyPositionConstraint {
 public:
  static std::unique_ptr<StickyPositionConstraint> Parse(const base::Value& value, ErrorReporter* errors);
  ~StickyPositionConstraint() { }

  // Layout rectangle of the sticky element before being shifted
  const ::headless::dom::Rect* GetStickyBoxRect() const { return sticky_box_rect_.get(); }
  void SetStickyBoxRect(std::unique_ptr<::headless::dom::Rect> value) { sticky_box_rect_ = std::move(value); }

  // Layout rectangle of the containing block of the sticky element
  const ::headless::dom::Rect* GetContainingBlockRect() const { return containing_block_rect_.get(); }
  void SetContainingBlockRect(std::unique_ptr<::headless::dom::Rect> value) { containing_block_rect_ = std::move(value); }

  // The nearest sticky layer that shifts the sticky box
  bool HasNearestLayerShiftingStickyBox() const { return !!nearest_layer_shifting_sticky_box_; }
  std::string GetNearestLayerShiftingStickyBox() const { DCHECK(HasNearestLayerShiftingStickyBox()); return nearest_layer_shifting_sticky_box_.value(); }
  void SetNearestLayerShiftingStickyBox(const std::string& value) { nearest_layer_shifting_sticky_box_ = value; }

  // The nearest sticky layer that shifts the containing block
  bool HasNearestLayerShiftingContainingBlock() const { return !!nearest_layer_shifting_containing_block_; }
  std::string GetNearestLayerShiftingContainingBlock() const { DCHECK(HasNearestLayerShiftingContainingBlock()); return nearest_layer_shifting_containing_block_.value(); }
  void SetNearestLayerShiftingContainingBlock(const std::string& value) { nearest_layer_shifting_containing_block_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StickyPositionConstraint> Clone() const;

  template<int STATE>
  class StickyPositionConstraintBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStickyBoxRectSet = 1 << 1,
    kContainingBlockRectSet = 1 << 2,
      kAllRequiredFieldsSet = (kStickyBoxRectSet | kContainingBlockRectSet | 0)
    };

    StickyPositionConstraintBuilder<STATE | kStickyBoxRectSet>& SetStickyBoxRect(std::unique_ptr<::headless::dom::Rect> value) {
      static_assert(!(STATE & kStickyBoxRectSet), "property stickyBoxRect should not have already been set");
      result_->SetStickyBoxRect(std::move(value));
      return CastState<kStickyBoxRectSet>();
    }

    StickyPositionConstraintBuilder<STATE | kContainingBlockRectSet>& SetContainingBlockRect(std::unique_ptr<::headless::dom::Rect> value) {
      static_assert(!(STATE & kContainingBlockRectSet), "property containingBlockRect should not have already been set");
      result_->SetContainingBlockRect(std::move(value));
      return CastState<kContainingBlockRectSet>();
    }

    StickyPositionConstraintBuilder<STATE>& SetNearestLayerShiftingStickyBox(const std::string& value) {
      result_->SetNearestLayerShiftingStickyBox(value);
      return *this;
    }

    StickyPositionConstraintBuilder<STATE>& SetNearestLayerShiftingContainingBlock(const std::string& value) {
      result_->SetNearestLayerShiftingContainingBlock(value);
      return *this;
    }

    std::unique_ptr<StickyPositionConstraint> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StickyPositionConstraint;
    StickyPositionConstraintBuilder() : result_(new StickyPositionConstraint()) { }

    template<int STEP> StickyPositionConstraintBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StickyPositionConstraintBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StickyPositionConstraint> result_;
  };

  static StickyPositionConstraintBuilder<0> Builder() {
    return StickyPositionConstraintBuilder<0>();
  }

 private:
  StickyPositionConstraint() { }

  std::unique_ptr<::headless::dom::Rect> sticky_box_rect_;
  std::unique_ptr<::headless::dom::Rect> containing_block_rect_;
  base::Optional<std::string> nearest_layer_shifting_sticky_box_;
  base::Optional<std::string> nearest_layer_shifting_containing_block_;

  DISALLOW_COPY_AND_ASSIGN(StickyPositionConstraint);
};


// Serialized fragment of layer picture along with its offset within the layer.
class HEADLESS_EXPORT PictureTile {
 public:
  static std::unique_ptr<PictureTile> Parse(const base::Value& value, ErrorReporter* errors);
  ~PictureTile() { }

  // Offset from owning layer left boundary
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Offset from owning layer top boundary
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // Base64-encoded snapshot data.
  protocol::Binary GetPicture() const { return picture_; }
  void SetPicture(const protocol::Binary& value) { picture_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PictureTile> Clone() const;

  template<int STATE>
  class PictureTileBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
    kPictureSet = 1 << 3,
      kAllRequiredFieldsSet = (kXSet | kYSet | kPictureSet | 0)
    };

    PictureTileBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    PictureTileBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    PictureTileBuilder<STATE | kPictureSet>& SetPicture(const protocol::Binary& value) {
      static_assert(!(STATE & kPictureSet), "property picture should not have already been set");
      result_->SetPicture(value);
      return CastState<kPictureSet>();
    }

    std::unique_ptr<PictureTile> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PictureTile;
    PictureTileBuilder() : result_(new PictureTile()) { }

    template<int STEP> PictureTileBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PictureTileBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PictureTile> result_;
  };

  static PictureTileBuilder<0> Builder() {
    return PictureTileBuilder<0>();
  }

 private:
  PictureTile() { }

  double x_;
  double y_;
  protocol::Binary picture_;

  DISALLOW_COPY_AND_ASSIGN(PictureTile);
};


// Information about a compositing layer.
class HEADLESS_EXPORT Layer {
 public:
  static std::unique_ptr<Layer> Parse(const base::Value& value, ErrorReporter* errors);
  ~Layer() { }

  // The unique id for this layer.
  std::string GetLayerId() const { return layer_id_; }
  void SetLayerId(const std::string& value) { layer_id_ = value; }

  // The id of parent (not present for root).
  bool HasParentLayerId() const { return !!parent_layer_id_; }
  std::string GetParentLayerId() const { DCHECK(HasParentLayerId()); return parent_layer_id_.value(); }
  void SetParentLayerId(const std::string& value) { parent_layer_id_ = value; }

  // The backend id for the node associated with this layer.
  bool HasBackendNodeId() const { return !!backend_node_id_; }
  int GetBackendNodeId() const { DCHECK(HasBackendNodeId()); return backend_node_id_.value(); }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // Offset from parent layer, X coordinate.
  double GetOffsetX() const { return offsetx_; }
  void SetOffsetX(double value) { offsetx_ = value; }

  // Offset from parent layer, Y coordinate.
  double GetOffsetY() const { return offsety_; }
  void SetOffsetY(double value) { offsety_ = value; }

  // Layer width.
  double GetWidth() const { return width_; }
  void SetWidth(double value) { width_ = value; }

  // Layer height.
  double GetHeight() const { return height_; }
  void SetHeight(double value) { height_ = value; }

  // Transformation matrix for layer, default is identity matrix
  bool HasTransform() const { return !!transform_; }
  const std::vector<double>* GetTransform() const { DCHECK(HasTransform()); return &transform_.value(); }
  void SetTransform(std::vector<double> value) { transform_ = std::move(value); }

  // Transform anchor point X, absent if no transform specified
  bool HasAnchorX() const { return !!anchorx_; }
  double GetAnchorX() const { DCHECK(HasAnchorX()); return anchorx_.value(); }
  void SetAnchorX(double value) { anchorx_ = value; }

  // Transform anchor point Y, absent if no transform specified
  bool HasAnchorY() const { return !!anchory_; }
  double GetAnchorY() const { DCHECK(HasAnchorY()); return anchory_.value(); }
  void SetAnchorY(double value) { anchory_ = value; }

  // Transform anchor point Z, absent if no transform specified
  bool HasAnchorZ() const { return !!anchorz_; }
  double GetAnchorZ() const { DCHECK(HasAnchorZ()); return anchorz_.value(); }
  void SetAnchorZ(double value) { anchorz_ = value; }

  // Indicates how many time this layer has painted.
  int GetPaintCount() const { return paint_count_; }
  void SetPaintCount(int value) { paint_count_ = value; }

  // Indicates whether this layer hosts any content, rather than being used for
  // transform/scrolling purposes only.
  bool GetDrawsContent() const { return draws_content_; }
  void SetDrawsContent(bool value) { draws_content_ = value; }

  // Set if layer is not visible.
  bool HasInvisible() const { return !!invisible_; }
  bool GetInvisible() const { DCHECK(HasInvisible()); return invisible_.value(); }
  void SetInvisible(bool value) { invisible_ = value; }

  // Rectangles scrolling on main thread only.
  bool HasScrollRects() const { return !!scroll_rects_; }
  const std::vector<std::unique_ptr<::headless::layer_tree::ScrollRect>>* GetScrollRects() const { DCHECK(HasScrollRects()); return &scroll_rects_.value(); }
  void SetScrollRects(std::vector<std::unique_ptr<::headless::layer_tree::ScrollRect>> value) { scroll_rects_ = std::move(value); }

  // Sticky position constraint information
  bool HasStickyPositionConstraint() const { return !!sticky_position_constraint_; }
  const ::headless::layer_tree::StickyPositionConstraint* GetStickyPositionConstraint() const { DCHECK(HasStickyPositionConstraint()); return sticky_position_constraint_.value().get(); }
  void SetStickyPositionConstraint(std::unique_ptr<::headless::layer_tree::StickyPositionConstraint> value) { sticky_position_constraint_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Layer> Clone() const;

  template<int STATE>
  class LayerBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLayerIdSet = 1 << 1,
    kOffsetXSet = 1 << 2,
    kOffsetYSet = 1 << 3,
    kWidthSet = 1 << 4,
    kHeightSet = 1 << 5,
    kPaintCountSet = 1 << 6,
    kDrawsContentSet = 1 << 7,
      kAllRequiredFieldsSet = (kLayerIdSet | kOffsetXSet | kOffsetYSet | kWidthSet | kHeightSet | kPaintCountSet | kDrawsContentSet | 0)
    };

    LayerBuilder<STATE | kLayerIdSet>& SetLayerId(const std::string& value) {
      static_assert(!(STATE & kLayerIdSet), "property layerId should not have already been set");
      result_->SetLayerId(value);
      return CastState<kLayerIdSet>();
    }

    LayerBuilder<STATE>& SetParentLayerId(const std::string& value) {
      result_->SetParentLayerId(value);
      return *this;
    }

    LayerBuilder<STATE>& SetBackendNodeId(int value) {
      result_->SetBackendNodeId(value);
      return *this;
    }

    LayerBuilder<STATE | kOffsetXSet>& SetOffsetX(double value) {
      static_assert(!(STATE & kOffsetXSet), "property offsetX should not have already been set");
      result_->SetOffsetX(value);
      return CastState<kOffsetXSet>();
    }

    LayerBuilder<STATE | kOffsetYSet>& SetOffsetY(double value) {
      static_assert(!(STATE & kOffsetYSet), "property offsetY should not have already been set");
      result_->SetOffsetY(value);
      return CastState<kOffsetYSet>();
    }

    LayerBuilder<STATE | kWidthSet>& SetWidth(double value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    LayerBuilder<STATE | kHeightSet>& SetHeight(double value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    LayerBuilder<STATE>& SetTransform(std::vector<double> value) {
      result_->SetTransform(std::move(value));
      return *this;
    }

    LayerBuilder<STATE>& SetAnchorX(double value) {
      result_->SetAnchorX(value);
      return *this;
    }

    LayerBuilder<STATE>& SetAnchorY(double value) {
      result_->SetAnchorY(value);
      return *this;
    }

    LayerBuilder<STATE>& SetAnchorZ(double value) {
      result_->SetAnchorZ(value);
      return *this;
    }

    LayerBuilder<STATE | kPaintCountSet>& SetPaintCount(int value) {
      static_assert(!(STATE & kPaintCountSet), "property paintCount should not have already been set");
      result_->SetPaintCount(value);
      return CastState<kPaintCountSet>();
    }

    LayerBuilder<STATE | kDrawsContentSet>& SetDrawsContent(bool value) {
      static_assert(!(STATE & kDrawsContentSet), "property drawsContent should not have already been set");
      result_->SetDrawsContent(value);
      return CastState<kDrawsContentSet>();
    }

    LayerBuilder<STATE>& SetInvisible(bool value) {
      result_->SetInvisible(value);
      return *this;
    }

    LayerBuilder<STATE>& SetScrollRects(std::vector<std::unique_ptr<::headless::layer_tree::ScrollRect>> value) {
      result_->SetScrollRects(std::move(value));
      return *this;
    }

    LayerBuilder<STATE>& SetStickyPositionConstraint(std::unique_ptr<::headless::layer_tree::StickyPositionConstraint> value) {
      result_->SetStickyPositionConstraint(std::move(value));
      return *this;
    }

    std::unique_ptr<Layer> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Layer;
    LayerBuilder() : result_(new Layer()) { }

    template<int STEP> LayerBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LayerBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Layer> result_;
  };

  static LayerBuilder<0> Builder() {
    return LayerBuilder<0>();
  }

 private:
  Layer() { }

  std::string layer_id_;
  base::Optional<std::string> parent_layer_id_;
  base::Optional<int> backend_node_id_;
  double offsetx_;
  double offsety_;
  double width_;
  double height_;
  base::Optional<std::vector<double>> transform_;
  base::Optional<double> anchorx_;
  base::Optional<double> anchory_;
  base::Optional<double> anchorz_;
  int paint_count_;
  bool draws_content_;
  base::Optional<bool> invisible_;
  base::Optional<std::vector<std::unique_ptr<::headless::layer_tree::ScrollRect>>> scroll_rects_;
  base::Optional<std::unique_ptr<::headless::layer_tree::StickyPositionConstraint>> sticky_position_constraint_;

  DISALLOW_COPY_AND_ASSIGN(Layer);
};


// Parameters for the CompositingReasons command.
class HEADLESS_EXPORT CompositingReasonsParams {
 public:
  static std::unique_ptr<CompositingReasonsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CompositingReasonsParams() { }

  // The id of the layer for which we want to get the reasons it was composited.
  std::string GetLayerId() const { return layer_id_; }
  void SetLayerId(const std::string& value) { layer_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CompositingReasonsParams> Clone() const;

  template<int STATE>
  class CompositingReasonsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLayerIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kLayerIdSet | 0)
    };

    CompositingReasonsParamsBuilder<STATE | kLayerIdSet>& SetLayerId(const std::string& value) {
      static_assert(!(STATE & kLayerIdSet), "property layerId should not have already been set");
      result_->SetLayerId(value);
      return CastState<kLayerIdSet>();
    }

    std::unique_ptr<CompositingReasonsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CompositingReasonsParams;
    CompositingReasonsParamsBuilder() : result_(new CompositingReasonsParams()) { }

    template<int STEP> CompositingReasonsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CompositingReasonsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CompositingReasonsParams> result_;
  };

  static CompositingReasonsParamsBuilder<0> Builder() {
    return CompositingReasonsParamsBuilder<0>();
  }

 private:
  CompositingReasonsParams() { }

  std::string layer_id_;

  DISALLOW_COPY_AND_ASSIGN(CompositingReasonsParams);
};


// Result for the CompositingReasons command.
class HEADLESS_EXPORT CompositingReasonsResult {
 public:
  static std::unique_ptr<CompositingReasonsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CompositingReasonsResult() { }

  // A list of strings specifying reasons for the given layer to become composited.
  const std::vector<std::string>* GetCompositingReasons() const { return &compositing_reasons_; }
  void SetCompositingReasons(std::vector<std::string> value) { compositing_reasons_ = std::move(value); }

  // A list of strings specifying reason IDs for the given layer to become composited.
  const std::vector<std::string>* GetCompositingReasonIds() const { return &compositing_reason_ids_; }
  void SetCompositingReasonIds(std::vector<std::string> value) { compositing_reason_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CompositingReasonsResult> Clone() const;

  template<int STATE>
  class CompositingReasonsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCompositingReasonsSet = 1 << 1,
    kCompositingReasonIdsSet = 1 << 2,
      kAllRequiredFieldsSet = (kCompositingReasonsSet | kCompositingReasonIdsSet | 0)
    };

    CompositingReasonsResultBuilder<STATE | kCompositingReasonsSet>& SetCompositingReasons(std::vector<std::string> value) {
      static_assert(!(STATE & kCompositingReasonsSet), "property compositingReasons should not have already been set");
      result_->SetCompositingReasons(std::move(value));
      return CastState<kCompositingReasonsSet>();
    }

    CompositingReasonsResultBuilder<STATE | kCompositingReasonIdsSet>& SetCompositingReasonIds(std::vector<std::string> value) {
      static_assert(!(STATE & kCompositingReasonIdsSet), "property compositingReasonIds should not have already been set");
      result_->SetCompositingReasonIds(std::move(value));
      return CastState<kCompositingReasonIdsSet>();
    }

    std::unique_ptr<CompositingReasonsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CompositingReasonsResult;
    CompositingReasonsResultBuilder() : result_(new CompositingReasonsResult()) { }

    template<int STEP> CompositingReasonsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CompositingReasonsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CompositingReasonsResult> result_;
  };

  static CompositingReasonsResultBuilder<0> Builder() {
    return CompositingReasonsResultBuilder<0>();
  }

 private:
  CompositingReasonsResult() { }

  std::vector<std::string> compositing_reasons_;
  std::vector<std::string> compositing_reason_ids_;

  DISALLOW_COPY_AND_ASSIGN(CompositingReasonsResult);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the LoadSnapshot command.
class HEADLESS_EXPORT LoadSnapshotParams {
 public:
  static std::unique_ptr<LoadSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LoadSnapshotParams() { }

  // An array of tiles composing the snapshot.
  const std::vector<std::unique_ptr<::headless::layer_tree::PictureTile>>* GetTiles() const { return &tiles_; }
  void SetTiles(std::vector<std::unique_ptr<::headless::layer_tree::PictureTile>> value) { tiles_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LoadSnapshotParams> Clone() const;

  template<int STATE>
  class LoadSnapshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTilesSet = 1 << 1,
      kAllRequiredFieldsSet = (kTilesSet | 0)
    };

    LoadSnapshotParamsBuilder<STATE | kTilesSet>& SetTiles(std::vector<std::unique_ptr<::headless::layer_tree::PictureTile>> value) {
      static_assert(!(STATE & kTilesSet), "property tiles should not have already been set");
      result_->SetTiles(std::move(value));
      return CastState<kTilesSet>();
    }

    std::unique_ptr<LoadSnapshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LoadSnapshotParams;
    LoadSnapshotParamsBuilder() : result_(new LoadSnapshotParams()) { }

    template<int STEP> LoadSnapshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LoadSnapshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LoadSnapshotParams> result_;
  };

  static LoadSnapshotParamsBuilder<0> Builder() {
    return LoadSnapshotParamsBuilder<0>();
  }

 private:
  LoadSnapshotParams() { }

  std::vector<std::unique_ptr<::headless::layer_tree::PictureTile>> tiles_;

  DISALLOW_COPY_AND_ASSIGN(LoadSnapshotParams);
};


// Result for the LoadSnapshot command.
class HEADLESS_EXPORT LoadSnapshotResult {
 public:
  static std::unique_ptr<LoadSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~LoadSnapshotResult() { }

  // The id of the snapshot.
  std::string GetSnapshotId() const { return snapshot_id_; }
  void SetSnapshotId(const std::string& value) { snapshot_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LoadSnapshotResult> Clone() const;

  template<int STATE>
  class LoadSnapshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSnapshotIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSnapshotIdSet | 0)
    };

    LoadSnapshotResultBuilder<STATE | kSnapshotIdSet>& SetSnapshotId(const std::string& value) {
      static_assert(!(STATE & kSnapshotIdSet), "property snapshotId should not have already been set");
      result_->SetSnapshotId(value);
      return CastState<kSnapshotIdSet>();
    }

    std::unique_ptr<LoadSnapshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LoadSnapshotResult;
    LoadSnapshotResultBuilder() : result_(new LoadSnapshotResult()) { }

    template<int STEP> LoadSnapshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LoadSnapshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LoadSnapshotResult> result_;
  };

  static LoadSnapshotResultBuilder<0> Builder() {
    return LoadSnapshotResultBuilder<0>();
  }

 private:
  LoadSnapshotResult() { }

  std::string snapshot_id_;

  DISALLOW_COPY_AND_ASSIGN(LoadSnapshotResult);
};


// Parameters for the MakeSnapshot command.
class HEADLESS_EXPORT MakeSnapshotParams {
 public:
  static std::unique_ptr<MakeSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~MakeSnapshotParams() { }

  // The id of the layer.
  std::string GetLayerId() const { return layer_id_; }
  void SetLayerId(const std::string& value) { layer_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MakeSnapshotParams> Clone() const;

  template<int STATE>
  class MakeSnapshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLayerIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kLayerIdSet | 0)
    };

    MakeSnapshotParamsBuilder<STATE | kLayerIdSet>& SetLayerId(const std::string& value) {
      static_assert(!(STATE & kLayerIdSet), "property layerId should not have already been set");
      result_->SetLayerId(value);
      return CastState<kLayerIdSet>();
    }

    std::unique_ptr<MakeSnapshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MakeSnapshotParams;
    MakeSnapshotParamsBuilder() : result_(new MakeSnapshotParams()) { }

    template<int STEP> MakeSnapshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MakeSnapshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MakeSnapshotParams> result_;
  };

  static MakeSnapshotParamsBuilder<0> Builder() {
    return MakeSnapshotParamsBuilder<0>();
  }

 private:
  MakeSnapshotParams() { }

  std::string layer_id_;

  DISALLOW_COPY_AND_ASSIGN(MakeSnapshotParams);
};


// Result for the MakeSnapshot command.
class HEADLESS_EXPORT MakeSnapshotResult {
 public:
  static std::unique_ptr<MakeSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~MakeSnapshotResult() { }

  // The id of the layer snapshot.
  std::string GetSnapshotId() const { return snapshot_id_; }
  void SetSnapshotId(const std::string& value) { snapshot_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<MakeSnapshotResult> Clone() const;

  template<int STATE>
  class MakeSnapshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSnapshotIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSnapshotIdSet | 0)
    };

    MakeSnapshotResultBuilder<STATE | kSnapshotIdSet>& SetSnapshotId(const std::string& value) {
      static_assert(!(STATE & kSnapshotIdSet), "property snapshotId should not have already been set");
      result_->SetSnapshotId(value);
      return CastState<kSnapshotIdSet>();
    }

    std::unique_ptr<MakeSnapshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class MakeSnapshotResult;
    MakeSnapshotResultBuilder() : result_(new MakeSnapshotResult()) { }

    template<int STEP> MakeSnapshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<MakeSnapshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<MakeSnapshotResult> result_;
  };

  static MakeSnapshotResultBuilder<0> Builder() {
    return MakeSnapshotResultBuilder<0>();
  }

 private:
  MakeSnapshotResult() { }

  std::string snapshot_id_;

  DISALLOW_COPY_AND_ASSIGN(MakeSnapshotResult);
};


// Parameters for the ProfileSnapshot command.
class HEADLESS_EXPORT ProfileSnapshotParams {
 public:
  static std::unique_ptr<ProfileSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ProfileSnapshotParams() { }

  // The id of the layer snapshot.
  std::string GetSnapshotId() const { return snapshot_id_; }
  void SetSnapshotId(const std::string& value) { snapshot_id_ = value; }

  // The maximum number of times to replay the snapshot (1, if not specified).
  bool HasMinRepeatCount() const { return !!min_repeat_count_; }
  int GetMinRepeatCount() const { DCHECK(HasMinRepeatCount()); return min_repeat_count_.value(); }
  void SetMinRepeatCount(int value) { min_repeat_count_ = value; }

  // The minimum duration (in seconds) to replay the snapshot.
  bool HasMinDuration() const { return !!min_duration_; }
  double GetMinDuration() const { DCHECK(HasMinDuration()); return min_duration_.value(); }
  void SetMinDuration(double value) { min_duration_ = value; }

  // The clip rectangle to apply when replaying the snapshot.
  bool HasClipRect() const { return !!clip_rect_; }
  const ::headless::dom::Rect* GetClipRect() const { DCHECK(HasClipRect()); return clip_rect_.value().get(); }
  void SetClipRect(std::unique_ptr<::headless::dom::Rect> value) { clip_rect_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ProfileSnapshotParams> Clone() const;

  template<int STATE>
  class ProfileSnapshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSnapshotIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSnapshotIdSet | 0)
    };

    ProfileSnapshotParamsBuilder<STATE | kSnapshotIdSet>& SetSnapshotId(const std::string& value) {
      static_assert(!(STATE & kSnapshotIdSet), "property snapshotId should not have already been set");
      result_->SetSnapshotId(value);
      return CastState<kSnapshotIdSet>();
    }

    ProfileSnapshotParamsBuilder<STATE>& SetMinRepeatCount(int value) {
      result_->SetMinRepeatCount(value);
      return *this;
    }

    ProfileSnapshotParamsBuilder<STATE>& SetMinDuration(double value) {
      result_->SetMinDuration(value);
      return *this;
    }

    ProfileSnapshotParamsBuilder<STATE>& SetClipRect(std::unique_ptr<::headless::dom::Rect> value) {
      result_->SetClipRect(std::move(value));
      return *this;
    }

    std::unique_ptr<ProfileSnapshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ProfileSnapshotParams;
    ProfileSnapshotParamsBuilder() : result_(new ProfileSnapshotParams()) { }

    template<int STEP> ProfileSnapshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ProfileSnapshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ProfileSnapshotParams> result_;
  };

  static ProfileSnapshotParamsBuilder<0> Builder() {
    return ProfileSnapshotParamsBuilder<0>();
  }

 private:
  ProfileSnapshotParams() { }

  std::string snapshot_id_;
  base::Optional<int> min_repeat_count_;
  base::Optional<double> min_duration_;
  base::Optional<std::unique_ptr<::headless::dom::Rect>> clip_rect_;

  DISALLOW_COPY_AND_ASSIGN(ProfileSnapshotParams);
};


// Result for the ProfileSnapshot command.
class HEADLESS_EXPORT ProfileSnapshotResult {
 public:
  static std::unique_ptr<ProfileSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ProfileSnapshotResult() { }

  // The array of paint profiles, one per run.
  const std::vector<std::vector<double>>* GetTimings() const { return &timings_; }
  void SetTimings(std::vector<std::vector<double>> value) { timings_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ProfileSnapshotResult> Clone() const;

  template<int STATE>
  class ProfileSnapshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimingsSet = 1 << 1,
      kAllRequiredFieldsSet = (kTimingsSet | 0)
    };

    ProfileSnapshotResultBuilder<STATE | kTimingsSet>& SetTimings(std::vector<std::vector<double>> value) {
      static_assert(!(STATE & kTimingsSet), "property timings should not have already been set");
      result_->SetTimings(std::move(value));
      return CastState<kTimingsSet>();
    }

    std::unique_ptr<ProfileSnapshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ProfileSnapshotResult;
    ProfileSnapshotResultBuilder() : result_(new ProfileSnapshotResult()) { }

    template<int STEP> ProfileSnapshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ProfileSnapshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ProfileSnapshotResult> result_;
  };

  static ProfileSnapshotResultBuilder<0> Builder() {
    return ProfileSnapshotResultBuilder<0>();
  }

 private:
  ProfileSnapshotResult() { }

  std::vector<std::vector<double>> timings_;

  DISALLOW_COPY_AND_ASSIGN(ProfileSnapshotResult);
};


// Parameters for the ReleaseSnapshot command.
class HEADLESS_EXPORT ReleaseSnapshotParams {
 public:
  static std::unique_ptr<ReleaseSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseSnapshotParams() { }

  // The id of the layer snapshot.
  std::string GetSnapshotId() const { return snapshot_id_; }
  void SetSnapshotId(const std::string& value) { snapshot_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseSnapshotParams> Clone() const;

  template<int STATE>
  class ReleaseSnapshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSnapshotIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSnapshotIdSet | 0)
    };

    ReleaseSnapshotParamsBuilder<STATE | kSnapshotIdSet>& SetSnapshotId(const std::string& value) {
      static_assert(!(STATE & kSnapshotIdSet), "property snapshotId should not have already been set");
      result_->SetSnapshotId(value);
      return CastState<kSnapshotIdSet>();
    }

    std::unique_ptr<ReleaseSnapshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseSnapshotParams;
    ReleaseSnapshotParamsBuilder() : result_(new ReleaseSnapshotParams()) { }

    template<int STEP> ReleaseSnapshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseSnapshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseSnapshotParams> result_;
  };

  static ReleaseSnapshotParamsBuilder<0> Builder() {
    return ReleaseSnapshotParamsBuilder<0>();
  }

 private:
  ReleaseSnapshotParams() { }

  std::string snapshot_id_;

  DISALLOW_COPY_AND_ASSIGN(ReleaseSnapshotParams);
};


// Result for the ReleaseSnapshot command.
class HEADLESS_EXPORT ReleaseSnapshotResult {
 public:
  static std::unique_ptr<ReleaseSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReleaseSnapshotResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReleaseSnapshotResult> Clone() const;

  template<int STATE>
  class ReleaseSnapshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ReleaseSnapshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReleaseSnapshotResult;
    ReleaseSnapshotResultBuilder() : result_(new ReleaseSnapshotResult()) { }

    template<int STEP> ReleaseSnapshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReleaseSnapshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReleaseSnapshotResult> result_;
  };

  static ReleaseSnapshotResultBuilder<0> Builder() {
    return ReleaseSnapshotResultBuilder<0>();
  }

 private:
  ReleaseSnapshotResult() { }


  DISALLOW_COPY_AND_ASSIGN(ReleaseSnapshotResult);
};


// Parameters for the ReplaySnapshot command.
class HEADLESS_EXPORT ReplaySnapshotParams {
 public:
  static std::unique_ptr<ReplaySnapshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReplaySnapshotParams() { }

  // The id of the layer snapshot.
  std::string GetSnapshotId() const { return snapshot_id_; }
  void SetSnapshotId(const std::string& value) { snapshot_id_ = value; }

  // The first step to replay from (replay from the very start if not specified).
  bool HasFromStep() const { return !!from_step_; }
  int GetFromStep() const { DCHECK(HasFromStep()); return from_step_.value(); }
  void SetFromStep(int value) { from_step_ = value; }

  // The last step to replay to (replay till the end if not specified).
  bool HasToStep() const { return !!to_step_; }
  int GetToStep() const { DCHECK(HasToStep()); return to_step_.value(); }
  void SetToStep(int value) { to_step_ = value; }

  // The scale to apply while replaying (defaults to 1).
  bool HasScale() const { return !!scale_; }
  double GetScale() const { DCHECK(HasScale()); return scale_.value(); }
  void SetScale(double value) { scale_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReplaySnapshotParams> Clone() const;

  template<int STATE>
  class ReplaySnapshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSnapshotIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSnapshotIdSet | 0)
    };

    ReplaySnapshotParamsBuilder<STATE | kSnapshotIdSet>& SetSnapshotId(const std::string& value) {
      static_assert(!(STATE & kSnapshotIdSet), "property snapshotId should not have already been set");
      result_->SetSnapshotId(value);
      return CastState<kSnapshotIdSet>();
    }

    ReplaySnapshotParamsBuilder<STATE>& SetFromStep(int value) {
      result_->SetFromStep(value);
      return *this;
    }

    ReplaySnapshotParamsBuilder<STATE>& SetToStep(int value) {
      result_->SetToStep(value);
      return *this;
    }

    ReplaySnapshotParamsBuilder<STATE>& SetScale(double value) {
      result_->SetScale(value);
      return *this;
    }

    std::unique_ptr<ReplaySnapshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReplaySnapshotParams;
    ReplaySnapshotParamsBuilder() : result_(new ReplaySnapshotParams()) { }

    template<int STEP> ReplaySnapshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReplaySnapshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReplaySnapshotParams> result_;
  };

  static ReplaySnapshotParamsBuilder<0> Builder() {
    return ReplaySnapshotParamsBuilder<0>();
  }

 private:
  ReplaySnapshotParams() { }

  std::string snapshot_id_;
  base::Optional<int> from_step_;
  base::Optional<int> to_step_;
  base::Optional<double> scale_;

  DISALLOW_COPY_AND_ASSIGN(ReplaySnapshotParams);
};


// Result for the ReplaySnapshot command.
class HEADLESS_EXPORT ReplaySnapshotResult {
 public:
  static std::unique_ptr<ReplaySnapshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReplaySnapshotResult() { }

  // A data: URL for resulting image.
  std::string GetDataURL() const { return dataurl_; }
  void SetDataURL(const std::string& value) { dataurl_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReplaySnapshotResult> Clone() const;

  template<int STATE>
  class ReplaySnapshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataURLSet = 1 << 1,
      kAllRequiredFieldsSet = (kDataURLSet | 0)
    };

    ReplaySnapshotResultBuilder<STATE | kDataURLSet>& SetDataURL(const std::string& value) {
      static_assert(!(STATE & kDataURLSet), "property dataURL should not have already been set");
      result_->SetDataURL(value);
      return CastState<kDataURLSet>();
    }

    std::unique_ptr<ReplaySnapshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReplaySnapshotResult;
    ReplaySnapshotResultBuilder() : result_(new ReplaySnapshotResult()) { }

    template<int STEP> ReplaySnapshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReplaySnapshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReplaySnapshotResult> result_;
  };

  static ReplaySnapshotResultBuilder<0> Builder() {
    return ReplaySnapshotResultBuilder<0>();
  }

 private:
  ReplaySnapshotResult() { }

  std::string dataurl_;

  DISALLOW_COPY_AND_ASSIGN(ReplaySnapshotResult);
};


// Parameters for the SnapshotCommandLog command.
class HEADLESS_EXPORT SnapshotCommandLogParams {
 public:
  static std::unique_ptr<SnapshotCommandLogParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SnapshotCommandLogParams() { }

  // The id of the layer snapshot.
  std::string GetSnapshotId() const { return snapshot_id_; }
  void SetSnapshotId(const std::string& value) { snapshot_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SnapshotCommandLogParams> Clone() const;

  template<int STATE>
  class SnapshotCommandLogParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSnapshotIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSnapshotIdSet | 0)
    };

    SnapshotCommandLogParamsBuilder<STATE | kSnapshotIdSet>& SetSnapshotId(const std::string& value) {
      static_assert(!(STATE & kSnapshotIdSet), "property snapshotId should not have already been set");
      result_->SetSnapshotId(value);
      return CastState<kSnapshotIdSet>();
    }

    std::unique_ptr<SnapshotCommandLogParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SnapshotCommandLogParams;
    SnapshotCommandLogParamsBuilder() : result_(new SnapshotCommandLogParams()) { }

    template<int STEP> SnapshotCommandLogParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SnapshotCommandLogParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SnapshotCommandLogParams> result_;
  };

  static SnapshotCommandLogParamsBuilder<0> Builder() {
    return SnapshotCommandLogParamsBuilder<0>();
  }

 private:
  SnapshotCommandLogParams() { }

  std::string snapshot_id_;

  DISALLOW_COPY_AND_ASSIGN(SnapshotCommandLogParams);
};


// Result for the SnapshotCommandLog command.
class HEADLESS_EXPORT SnapshotCommandLogResult {
 public:
  static std::unique_ptr<SnapshotCommandLogResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SnapshotCommandLogResult() { }

  // The array of canvas function calls.
  const std::vector<std::unique_ptr<base::Value>>* GetCommandLog() const { return &command_log_; }
  void SetCommandLog(std::vector<std::unique_ptr<base::Value>> value) { command_log_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SnapshotCommandLogResult> Clone() const;

  template<int STATE>
  class SnapshotCommandLogResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCommandLogSet = 1 << 1,
      kAllRequiredFieldsSet = (kCommandLogSet | 0)
    };

    SnapshotCommandLogResultBuilder<STATE | kCommandLogSet>& SetCommandLog(std::vector<std::unique_ptr<base::Value>> value) {
      static_assert(!(STATE & kCommandLogSet), "property commandLog should not have already been set");
      result_->SetCommandLog(std::move(value));
      return CastState<kCommandLogSet>();
    }

    std::unique_ptr<SnapshotCommandLogResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SnapshotCommandLogResult;
    SnapshotCommandLogResultBuilder() : result_(new SnapshotCommandLogResult()) { }

    template<int STEP> SnapshotCommandLogResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SnapshotCommandLogResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SnapshotCommandLogResult> result_;
  };

  static SnapshotCommandLogResultBuilder<0> Builder() {
    return SnapshotCommandLogResultBuilder<0>();
  }

 private:
  SnapshotCommandLogResult() { }

  std::vector<std::unique_ptr<base::Value>> command_log_;

  DISALLOW_COPY_AND_ASSIGN(SnapshotCommandLogResult);
};


// Parameters for the LayerPainted event.
class HEADLESS_EXPORT LayerPaintedParams {
 public:
  static std::unique_ptr<LayerPaintedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LayerPaintedParams() { }

  // The id of the painted layer.
  std::string GetLayerId() const { return layer_id_; }
  void SetLayerId(const std::string& value) { layer_id_ = value; }

  // Clip rectangle.
  const ::headless::dom::Rect* GetClip() const { return clip_.get(); }
  void SetClip(std::unique_ptr<::headless::dom::Rect> value) { clip_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LayerPaintedParams> Clone() const;

  template<int STATE>
  class LayerPaintedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLayerIdSet = 1 << 1,
    kClipSet = 1 << 2,
      kAllRequiredFieldsSet = (kLayerIdSet | kClipSet | 0)
    };

    LayerPaintedParamsBuilder<STATE | kLayerIdSet>& SetLayerId(const std::string& value) {
      static_assert(!(STATE & kLayerIdSet), "property layerId should not have already been set");
      result_->SetLayerId(value);
      return CastState<kLayerIdSet>();
    }

    LayerPaintedParamsBuilder<STATE | kClipSet>& SetClip(std::unique_ptr<::headless::dom::Rect> value) {
      static_assert(!(STATE & kClipSet), "property clip should not have already been set");
      result_->SetClip(std::move(value));
      return CastState<kClipSet>();
    }

    std::unique_ptr<LayerPaintedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LayerPaintedParams;
    LayerPaintedParamsBuilder() : result_(new LayerPaintedParams()) { }

    template<int STEP> LayerPaintedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LayerPaintedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LayerPaintedParams> result_;
  };

  static LayerPaintedParamsBuilder<0> Builder() {
    return LayerPaintedParamsBuilder<0>();
  }

 private:
  LayerPaintedParams() { }

  std::string layer_id_;
  std::unique_ptr<::headless::dom::Rect> clip_;

  DISALLOW_COPY_AND_ASSIGN(LayerPaintedParams);
};


// Parameters for the LayerTreeDidChange event.
class HEADLESS_EXPORT LayerTreeDidChangeParams {
 public:
  static std::unique_ptr<LayerTreeDidChangeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LayerTreeDidChangeParams() { }

  // Layer tree, absent if not in the comspositing mode.
  bool HasLayers() const { return !!layers_; }
  const std::vector<std::unique_ptr<::headless::layer_tree::Layer>>* GetLayers() const { DCHECK(HasLayers()); return &layers_.value(); }
  void SetLayers(std::vector<std::unique_ptr<::headless::layer_tree::Layer>> value) { layers_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LayerTreeDidChangeParams> Clone() const;

  template<int STATE>
  class LayerTreeDidChangeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    LayerTreeDidChangeParamsBuilder<STATE>& SetLayers(std::vector<std::unique_ptr<::headless::layer_tree::Layer>> value) {
      result_->SetLayers(std::move(value));
      return *this;
    }

    std::unique_ptr<LayerTreeDidChangeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LayerTreeDidChangeParams;
    LayerTreeDidChangeParamsBuilder() : result_(new LayerTreeDidChangeParams()) { }

    template<int STEP> LayerTreeDidChangeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LayerTreeDidChangeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LayerTreeDidChangeParams> result_;
  };

  static LayerTreeDidChangeParamsBuilder<0> Builder() {
    return LayerTreeDidChangeParamsBuilder<0>();
  }

 private:
  LayerTreeDidChangeParams() { }

  base::Optional<std::vector<std::unique_ptr<::headless::layer_tree::Layer>>> layers_;

  DISALLOW_COPY_AND_ASSIGN(LayerTreeDidChangeParams);
};


}  // namespace layer_tree

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_LAYER_TREE_H_
