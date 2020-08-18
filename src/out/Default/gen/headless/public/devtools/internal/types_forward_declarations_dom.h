// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_DOM_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_DOM_H_

#include "base/values.h"

namespace headless {

namespace dom {
class BackendNode;
class Node;
class RGBA;
class BoxModel;
class ShapeOutsideInfo;
class Rect;
class CollectClassNamesFromSubtreeParams;
class CollectClassNamesFromSubtreeResult;
class CopyToParams;
class CopyToResult;
class DescribeNodeParams;
class DescribeNodeResult;
class ScrollIntoViewIfNeededParams;
class ScrollIntoViewIfNeededResult;
class DisableParams;
class DisableResult;
class DiscardSearchResultsParams;
class DiscardSearchResultsResult;
class EnableParams;
class EnableResult;
class FocusParams;
class FocusResult;
class GetAttributesParams;
class GetAttributesResult;
class GetBoxModelParams;
class GetBoxModelResult;
class GetContentQuadsParams;
class GetContentQuadsResult;
class GetDocumentParams;
class GetDocumentResult;
class GetFlattenedDocumentParams;
class GetFlattenedDocumentResult;
class GetNodeForLocationParams;
class GetNodeForLocationResult;
class GetOuterHTMLParams;
class GetOuterHTMLResult;
class GetRelayoutBoundaryParams;
class GetRelayoutBoundaryResult;
class GetSearchResultsParams;
class GetSearchResultsResult;
class HideHighlightParams;
class HideHighlightResult;
class HighlightNodeParams;
class HighlightNodeResult;
class HighlightRectParams;
class HighlightRectResult;
class MarkUndoableStateParams;
class MarkUndoableStateResult;
class MoveToParams;
class MoveToResult;
class PerformSearchParams;
class PerformSearchResult;
class PushNodeByPathToFrontendParams;
class PushNodeByPathToFrontendResult;
class PushNodesByBackendIdsToFrontendParams;
class PushNodesByBackendIdsToFrontendResult;
class QuerySelectorParams;
class QuerySelectorResult;
class QuerySelectorAllParams;
class QuerySelectorAllResult;
class RedoParams;
class RedoResult;
class RemoveAttributeParams;
class RemoveAttributeResult;
class RemoveNodeParams;
class RemoveNodeResult;
class RequestChildNodesParams;
class RequestChildNodesResult;
class RequestNodeParams;
class RequestNodeResult;
class ResolveNodeParams;
class ResolveNodeResult;
class SetAttributeValueParams;
class SetAttributeValueResult;
class SetAttributesAsTextParams;
class SetAttributesAsTextResult;
class SetFileInputFilesParams;
class SetFileInputFilesResult;
class SetNodeStackTracesEnabledParams;
class SetNodeStackTracesEnabledResult;
class GetNodeStackTracesParams;
class GetNodeStackTracesResult;
class GetFileInfoParams;
class GetFileInfoResult;
class SetInspectedNodeParams;
class SetInspectedNodeResult;
class SetNodeNameParams;
class SetNodeNameResult;
class SetNodeValueParams;
class SetNodeValueResult;
class SetOuterHTMLParams;
class SetOuterHTMLResult;
class UndoParams;
class UndoResult;
class GetFrameOwnerParams;
class GetFrameOwnerResult;
class AttributeModifiedParams;
class AttributeRemovedParams;
class CharacterDataModifiedParams;
class ChildNodeCountUpdatedParams;
class ChildNodeInsertedParams;
class ChildNodeRemovedParams;
class DistributedNodesUpdatedParams;
class DocumentUpdatedParams;
class InlineStyleInvalidatedParams;
class PseudoElementAddedParams;
class PseudoElementRemovedParams;
class SetChildNodesParams;
class ShadowRootPoppedParams;
class ShadowRootPushedParams;

enum class PseudoType {
  FIRST_LINE,
  FIRST_LETTER,
  BEFORE,
  AFTER,
  MARKER,
  BACKDROP,
  SELECTION,
  FIRST_LINE_INHERITED,
  SCROLLBAR,
  SCROLLBAR_THUMB,
  SCROLLBAR_BUTTON,
  SCROLLBAR_TRACK,
  SCROLLBAR_TRACK_PIECE,
  SCROLLBAR_CORNER,
  RESIZER,
  INPUT_LIST_BUTTON
};

enum class ShadowRootType {
  USER_AGENT,
  OPEN,
  CLOSED
};

}  // namespace dom

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPES_FORWARD_DECLARATIONS_DOM_H_
