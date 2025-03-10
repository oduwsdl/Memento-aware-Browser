// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/layout/ng/ng_page_layout_algorithm.h"

#include <algorithm>
#include "third_party/blink/renderer/core/layout/ng/ng_block_layout_algorithm.h"
#include "third_party/blink/renderer/core/layout/ng/ng_box_fragment.h"
#include "third_party/blink/renderer/core/layout/ng/ng_constraint_space_builder.h"
#include "third_party/blink/renderer/core/layout/ng/ng_length_utils.h"
#include "third_party/blink/renderer/core/layout/ng/ng_out_of_flow_layout_part.h"
#include "third_party/blink/renderer/core/layout/ng/ng_physical_box_fragment.h"
#include "third_party/blink/renderer/core/style/computed_style.h"

namespace blink {

NGPageLayoutAlgorithm::NGPageLayoutAlgorithm(
    const NGLayoutAlgorithmParams& params)
    : NGLayoutAlgorithm(params) {
  container_builder_.SetIsNewFormattingContext(
      params.space.IsNewFormattingContext());
  container_builder_.SetInitialFragmentGeometry(params.fragment_geometry);
}

scoped_refptr<const NGLayoutResult> NGPageLayoutAlgorithm::Layout() {
  LogicalSize page_size = ChildAvailableSize();

  NGConstraintSpace child_space = CreateConstraintSpaceForPages(page_size);

  WritingMode writing_mode = ConstraintSpace().GetWritingMode();
  scoped_refptr<const NGBlockBreakToken> break_token = BreakToken();
  LayoutUnit intrinsic_block_size;
  LogicalOffset page_offset = BorderScrollbarPadding().StartOffset();
  // TODO(mstensho): Handle auto block size.
  LogicalOffset page_progression(LayoutUnit(), page_size.block_size);

  container_builder_.SetIsBlockFragmentationContextRoot();

  do {
    // Lay out one page. Each page will become a fragment.
    NGFragmentGeometry fragment_geometry =
        CalculateInitialFragmentGeometry(child_space, Node());
    NGBlockLayoutAlgorithm child_algorithm(
        {Node(), fragment_geometry, child_space, break_token.get()});
    scoped_refptr<const NGLayoutResult> result = child_algorithm.Layout();
    const auto& page = result->PhysicalFragment();

    container_builder_.AddChild(page, page_offset);

    LayoutUnit page_block_size = NGFragment(writing_mode, page).BlockSize();
    intrinsic_block_size = std::max(intrinsic_block_size,
                                    page_offset.block_offset + page_block_size);
    page_offset += page_progression;
    break_token = To<NGBlockBreakToken>(page.BreakToken());
  } while (break_token);

  container_builder_.SetIntrinsicBlockSize(intrinsic_block_size);

  // Compute the block-axis size now that we know our content size.
  LayoutUnit block_size = ComputeBlockSizeForFragment(
      ConstraintSpace(), Style(), BorderPadding(), intrinsic_block_size,
      container_builder_.InitialBorderBoxSize().inline_size);
  container_builder_.SetBlockSize(block_size);

  NGOutOfFlowLayoutPart(
      Node(), ConstraintSpace(),
      container_builder_.Borders() + container_builder_.Scrollbar(),
      &container_builder_)
      .Run();

  // TODO(mstensho): Propagate baselines.

  return container_builder_.ToBoxFragment();
}

MinMaxSizesResult NGPageLayoutAlgorithm::ComputeMinMaxSizes(
    const MinMaxSizesInput& input) const {
  NGFragmentGeometry fragment_geometry =
      CalculateInitialMinMaxFragmentGeometry(ConstraintSpace(), Node());
  NGBlockLayoutAlgorithm algorithm(
      {Node(), fragment_geometry, ConstraintSpace()});
  return algorithm.ComputeMinMaxSizes(input);
}

NGConstraintSpace NGPageLayoutAlgorithm::CreateConstraintSpaceForPages(
    const LogicalSize& page_size) const {
  NGConstraintSpaceBuilder space_builder(
      ConstraintSpace(), Style().GetWritingMode(), /* is_new_fc */ true);
  space_builder.SetAvailableSize(page_size);
  space_builder.SetPercentageResolutionSize(page_size);

  // TODO(mstensho): Handle auto block size.
  space_builder.SetFragmentationType(kFragmentPage);
  space_builder.SetFragmentainerBlockSize(page_size.block_size);
  space_builder.SetIsAnonymous(true);

  return space_builder.ToConstraintSpace();
}

}  // namespace blink
