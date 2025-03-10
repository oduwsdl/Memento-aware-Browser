// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_INLINE_NG_LOGICAL_LINE_ITEM_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_INLINE_NG_LOGICAL_LINE_ITEM_H_

#include "third_party/blink/renderer/core/layout/geometry/logical_rect.h"
#include "third_party/blink/renderer/core/layout/ng/inline/ng_inline_item.h"
#include "third_party/blink/renderer/core/layout/ng/inline/ng_physical_text_fragment.h"
#include "third_party/blink/renderer/core/layout/ng/ng_layout_result.h"
#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"

namespace blink {

class LayoutObject;

// This class represents an item in a line, after line break, but still mutable
// and in the logical coordinate system.
struct NGLogicalLineItem {
  DISALLOW_NEW();

  // Empty constructor needed for |resize()|.
  NGLogicalLineItem() = default;
  // Create a placeholder. A placeholder does not have a fragment nor a bidi
  // level.
  NGLogicalLineItem(LayoutUnit block_offset, LayoutUnit block_size)
      : rect(LayoutUnit(), block_offset, LayoutUnit(), block_size) {}
  // Crete a bidi control. A bidi control does not have a fragment, but has
  // bidi level and affects bidi reordering.
  explicit NGLogicalLineItem(UBiDiLevel bidi_level) : bidi_level(bidi_level) {}
  // Create an in-flow |NGLayoutResult|.
  NGLogicalLineItem(scoped_refptr<const NGLayoutResult> layout_result,
                    const LogicalRect& rect,
                    unsigned children_count,
                    UBiDiLevel bidi_level)
      : layout_result(std::move(layout_result)),
        rect(rect),
        children_count(children_count),
        bidi_level(bidi_level) {}
  NGLogicalLineItem(scoped_refptr<const NGLayoutResult> layout_result,
                    LogicalOffset offset,
                    LayoutUnit inline_size,
                    unsigned children_count,
                    UBiDiLevel bidi_level)
      : layout_result(std::move(layout_result)),
        rect(offset, LogicalSize()),
        inline_size(inline_size),
        children_count(children_count),
        bidi_level(bidi_level) {}
  // Create an in-flow text fragment.
  NGLogicalLineItem(const NGInlineItem& inline_item,
                    scoped_refptr<const ShapeResultView> shape_result,
                    const NGTextOffset& text_offset,
                    LayoutUnit block_offset,
                    LayoutUnit inline_size,
                    LayoutUnit text_height,
                    UBiDiLevel bidi_level)
      : inline_item(&inline_item),
        shape_result(std::move(shape_result)),
        text_offset(text_offset),
        rect(LayoutUnit(), block_offset, LayoutUnit(), text_height),
        inline_size(inline_size),
        bidi_level(bidi_level) {}
  NGLogicalLineItem(const NGInlineItem& inline_item,
                    scoped_refptr<const ShapeResultView> shape_result,
                    const String& text_content,
                    LayoutUnit block_offset,
                    LayoutUnit inline_size,
                    LayoutUnit text_height,
                    UBiDiLevel bidi_level)
      : inline_item(&inline_item),
        shape_result(std::move(shape_result)),
        text_offset(
            {this->shape_result->StartIndex(), this->shape_result->EndIndex()}),
        text_content(text_content),
        rect(LayoutUnit(), block_offset, LayoutUnit(), text_height),
        inline_size(inline_size),
        bidi_level(bidi_level) {}
  NGLogicalLineItem(const NGLogicalLineItem& source_item,
                    scoped_refptr<const ShapeResultView> shape_result,
                    const NGTextOffset& text_offset)
      : inline_item(source_item.inline_item),
        shape_result(std::move(shape_result)),
        text_offset(text_offset),
        text_content(source_item.text_content),
        rect(source_item.rect),
        inline_size(this->shape_result->SnappedWidth()),
        bidi_level(source_item.bidi_level) {}
  NGLogicalLineItem(scoped_refptr<const NGPhysicalTextFragment> fragment,
                    LogicalOffset offset,
                    LayoutUnit inline_size,
                    UBiDiLevel bidi_level)
      : fragment(std::move(fragment)),
        rect(offset, LogicalSize()),
        inline_size(inline_size),
        bidi_level(bidi_level) {}
  NGLogicalLineItem(scoped_refptr<const NGPhysicalTextFragment> fragment,
                    LayoutUnit block_offset,
                    LayoutUnit inline_size,
                    UBiDiLevel bidi_level)
      : fragment(std::move(fragment)),
        rect(LayoutUnit(), block_offset, LayoutUnit(), LayoutUnit()),
        inline_size(inline_size),
        bidi_level(bidi_level) {}
  // Create an out-of-flow positioned object.
  NGLogicalLineItem(LayoutObject* out_of_flow_positioned_box,
                    UBiDiLevel bidi_level,
                    TextDirection container_direction)
      : out_of_flow_positioned_box(out_of_flow_positioned_box),
        bidi_level(bidi_level),
        container_direction(container_direction) {}
  // Create an unpositioned float.
  NGLogicalLineItem(LayoutObject* unpositioned_float, UBiDiLevel bidi_level)
      : unpositioned_float(unpositioned_float), bidi_level(bidi_level) {}
  // Create a positioned float.
  NGLogicalLineItem(scoped_refptr<const NGLayoutResult> layout_result,
                    NGBfcOffset bfc_offset,
                    UBiDiLevel bidi_level)
      : layout_result(std::move(layout_result)),
        bfc_offset(bfc_offset),
        bidi_level(bidi_level) {}

  bool IsInlineBox() const {
    return layout_result && layout_result->PhysicalFragment().IsInlineBox();
  }
  bool HasInFlowFragment() const {
    return fragment || inline_item ||
           (layout_result && !layout_result->PhysicalFragment().IsFloating());
  }
  bool HasInFlowOrFloatingFragment() const {
    return fragment || inline_item || layout_result;
  }
  bool HasOutOfFlowFragment() const { return out_of_flow_positioned_box; }
  bool HasFragment() const {
    return HasInFlowOrFloatingFragment() || HasOutOfFlowFragment();
  }
  bool IsControl() const {
    return inline_item && inline_item->Type() == NGInlineItem::kControl;
  }
  bool CanCreateFragmentItem() const { return HasInFlowOrFloatingFragment(); }
  bool HasBidiLevel() const { return bidi_level != 0xff; }
  bool IsPlaceholder() const { return !HasFragment() && !HasBidiLevel(); }
  bool IsOpaqueToBidiReordering() const {
    if (IsPlaceholder())
      return true;
    // Skip all inline boxes. Fragments for inline boxes maybe created earlier
    // if they have no children.
    if (layout_result) {
      const LayoutObject* layout_object =
          layout_result->PhysicalFragment().GetLayoutObject();
      DCHECK(layout_object);
      if (layout_object->IsLayoutInline())
        return true;
    }
    return false;
  }

  const LogicalOffset& Offset() const { return rect.offset; }
  LayoutUnit InlineOffset() const { return rect.offset.inline_offset; }
  LayoutUnit BlockOffset() const { return rect.offset.block_offset; }
  LayoutUnit BlockEndOffset() const { return rect.BlockEndOffset(); }
  const LogicalSize& Size() const { return rect.size; }
  LogicalSize MarginSize() const { return {inline_size, Size().block_size}; }

  const NGPhysicalFragment* PhysicalFragment() const {
    if (layout_result)
      return &layout_result->PhysicalFragment();
    return fragment.get();
  }
  const LayoutObject* GetLayoutObject() const;
  LayoutObject* GetMutableLayoutObject() const;
  const Node* GetNode() const;
  const ComputedStyle* Style() const;

  unsigned StartOffset() const { return text_offset.start; }
  unsigned EndOffset() const { return text_offset.end; }

  TextDirection ResolvedDirection() const {
    // Inline boxes are not leaves that they don't have directions.
    DCHECK(HasBidiLevel() || IsInlineBox());
    return HasBidiLevel() ? DirectionFromLevel(bidi_level)
                          : TextDirection::kLtr;
  }

  scoped_refptr<const NGLayoutResult> layout_result;
  scoped_refptr<const NGPhysicalTextFragment> fragment;

  // Data to create a text fragment from.
  const NGInlineItem* inline_item = nullptr;
  scoped_refptr<const ShapeResultView> shape_result;
  NGTextOffset text_offset;

  // Data to create a generated text fragment.
  String text_content;

  LayoutObject* out_of_flow_positioned_box = nullptr;
  LayoutObject* unpositioned_float = nullptr;
  // The offset of the border box, initially in this child coordinate system.
  // |ComputeInlinePositions()| converts it to the offset within the line box.
  LogicalRect rect;
  // The offset of a positioned float wrt. the root BFC. This should only be
  // set for positioned floats.
  NGBfcOffset bfc_offset;
  // The inline size of the margin box.
  LayoutUnit inline_size;
  LayoutUnit margin_line_left;
  // The index of |box_data_list_|, used in |PrepareForReorder()| and
  // |UpdateAfterReorder()| to track children of boxes across BiDi reorder.
  unsigned box_data_index = 0;
  // For an inline box, shows the number of descendant |Child|ren, including
  // empty ones. Includes itself, so 1 means no descendants. 0 if not an
  // inline box. Available only after |CreateBoxFragments()|.
  unsigned children_count = 0;
  UBiDiLevel bidi_level = 0xff;
  // The current text direction for OOF positioned items.
  TextDirection container_direction = TextDirection::kLtr;

  bool is_hidden_for_paint = false;
};

// A vector of Child.
// Unlike the fragment builder, chlidren are mutable.
// Callers can add to the fragment builder in a batch once finalized.
class NGLogicalLineItems {
  STACK_ALLOCATED();

 public:
  NGLogicalLineItems() = default;
  void operator=(NGLogicalLineItems&& other) {
    children_ = std::move(other.children_);
  }

  NGLogicalLineItem& operator[](wtf_size_t i) { return children_[i]; }
  const NGLogicalLineItem& operator[](wtf_size_t i) const {
    return children_[i];
  }

  wtf_size_t size() const { return children_.size(); }
  bool IsEmpty() const { return children_.IsEmpty(); }
  void ReserveInitialCapacity(unsigned capacity) {
    children_.ReserveInitialCapacity(capacity);
  }
  void clear() { children_.resize(0); }
  void resize(wtf_size_t size) { children_.resize(size); }

  using iterator = Vector<NGLogicalLineItem, 16>::iterator;
  iterator begin() { return children_.begin(); }
  iterator end() { return children_.end(); }
  using const_iterator = Vector<NGLogicalLineItem, 16>::const_iterator;
  const_iterator begin() const { return children_.begin(); }
  const_iterator end() const { return children_.end(); }
  using reverse_iterator = Vector<NGLogicalLineItem, 16>::reverse_iterator;
  reverse_iterator rbegin() { return children_.rbegin(); }
  reverse_iterator rend() { return children_.rend(); }
  using const_reverse_iterator =
      Vector<NGLogicalLineItem, 16>::const_reverse_iterator;
  const_reverse_iterator rbegin() const { return children_.rbegin(); }
  const_reverse_iterator rend() const { return children_.rend(); }

  NGLogicalLineItem* FirstInFlowChild();
  NGLogicalLineItem* LastInFlowChild();

  // Add a child. Accepts all constructor arguments for |NGLogicalLineItem|.
  template <class... Args>
  void AddChild(Args&&... args) {
    children_.emplace_back(std::forward<Args>(args)...);
  }
  void InsertChild(unsigned index, NGLogicalLineItem&& item) {
    WillInsertChild(index);
    children_.insert(index, item);
  }
  void InsertChild(unsigned index,
                   scoped_refptr<const NGLayoutResult> layout_result,
                   const LogicalRect& rect,
                   unsigned children_count) {
    WillInsertChild(index);
    children_.insert(
        index, NGLogicalLineItem(std::move(layout_result), rect, children_count,
                                 /* bidi_level */ 0));
  }

  void MoveInInlineDirection(LayoutUnit);
  void MoveInInlineDirection(LayoutUnit, unsigned start, unsigned end);
  void MoveInBlockDirection(LayoutUnit);
  void MoveInBlockDirection(LayoutUnit, unsigned start, unsigned end);

  // Create |NGPhysicalTextFragment| for all text children.
  void CreateTextFragments(WritingMode writing_mode,
                           const String& text_content);

 private:
  void WillInsertChild(unsigned index);

  Vector<NGLogicalLineItem, 16> children_;
};

}  // namespace blink

WTF_ALLOW_MOVE_INIT_AND_COMPARE_WITH_MEM_FUNCTIONS(blink::NGLogicalLineItem)

#endif  // THIRD_PARTY_BLINK_RENDERER_CORE_LAYOUT_NG_INLINE_NG_LOGICAL_LINE_ITEM_H_
