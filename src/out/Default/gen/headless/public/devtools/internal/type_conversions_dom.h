// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_dom.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {




template <>
struct FromValue<dom::BackendNode> {
  static std::unique_ptr<dom::BackendNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::BackendNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::BackendNode& value) {
  return value.Serialize();
}

template <>
struct FromValue<dom::PseudoType> {
  static dom::PseudoType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return dom::PseudoType::FIRST_LINE;
    }
    if (value.GetString() == "first-line")
      return dom::PseudoType::FIRST_LINE;
    if (value.GetString() == "first-letter")
      return dom::PseudoType::FIRST_LETTER;
    if (value.GetString() == "before")
      return dom::PseudoType::BEFORE;
    if (value.GetString() == "after")
      return dom::PseudoType::AFTER;
    if (value.GetString() == "marker")
      return dom::PseudoType::MARKER;
    if (value.GetString() == "backdrop")
      return dom::PseudoType::BACKDROP;
    if (value.GetString() == "selection")
      return dom::PseudoType::SELECTION;
    if (value.GetString() == "first-line-inherited")
      return dom::PseudoType::FIRST_LINE_INHERITED;
    if (value.GetString() == "scrollbar")
      return dom::PseudoType::SCROLLBAR;
    if (value.GetString() == "scrollbar-thumb")
      return dom::PseudoType::SCROLLBAR_THUMB;
    if (value.GetString() == "scrollbar-button")
      return dom::PseudoType::SCROLLBAR_BUTTON;
    if (value.GetString() == "scrollbar-track")
      return dom::PseudoType::SCROLLBAR_TRACK;
    if (value.GetString() == "scrollbar-track-piece")
      return dom::PseudoType::SCROLLBAR_TRACK_PIECE;
    if (value.GetString() == "scrollbar-corner")
      return dom::PseudoType::SCROLLBAR_CORNER;
    if (value.GetString() == "resizer")
      return dom::PseudoType::RESIZER;
    if (value.GetString() == "input-list-button")
      return dom::PseudoType::INPUT_LIST_BUTTON;
    errors->AddError("invalid enum value");
    return dom::PseudoType::FIRST_LINE;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PseudoType& value) {
  switch (value) {
    case dom::PseudoType::FIRST_LINE:
      return std::make_unique<base::Value>("first-line");
    case dom::PseudoType::FIRST_LETTER:
      return std::make_unique<base::Value>("first-letter");
    case dom::PseudoType::BEFORE:
      return std::make_unique<base::Value>("before");
    case dom::PseudoType::AFTER:
      return std::make_unique<base::Value>("after");
    case dom::PseudoType::MARKER:
      return std::make_unique<base::Value>("marker");
    case dom::PseudoType::BACKDROP:
      return std::make_unique<base::Value>("backdrop");
    case dom::PseudoType::SELECTION:
      return std::make_unique<base::Value>("selection");
    case dom::PseudoType::FIRST_LINE_INHERITED:
      return std::make_unique<base::Value>("first-line-inherited");
    case dom::PseudoType::SCROLLBAR:
      return std::make_unique<base::Value>("scrollbar");
    case dom::PseudoType::SCROLLBAR_THUMB:
      return std::make_unique<base::Value>("scrollbar-thumb");
    case dom::PseudoType::SCROLLBAR_BUTTON:
      return std::make_unique<base::Value>("scrollbar-button");
    case dom::PseudoType::SCROLLBAR_TRACK:
      return std::make_unique<base::Value>("scrollbar-track");
    case dom::PseudoType::SCROLLBAR_TRACK_PIECE:
      return std::make_unique<base::Value>("scrollbar-track-piece");
    case dom::PseudoType::SCROLLBAR_CORNER:
      return std::make_unique<base::Value>("scrollbar-corner");
    case dom::PseudoType::RESIZER:
      return std::make_unique<base::Value>("resizer");
    case dom::PseudoType::INPUT_LIST_BUTTON:
      return std::make_unique<base::Value>("input-list-button");
  };
  NOTREACHED();
  return nullptr;
}
template <>
struct FromValue<dom::ShadowRootType> {
  static dom::ShadowRootType Parse(const base::Value& value, ErrorReporter* errors) {
    if (!value.is_string()) {
      errors->AddError("string enum value expected");
      return dom::ShadowRootType::USER_AGENT;
    }
    if (value.GetString() == "user-agent")
      return dom::ShadowRootType::USER_AGENT;
    if (value.GetString() == "open")
      return dom::ShadowRootType::OPEN;
    if (value.GetString() == "closed")
      return dom::ShadowRootType::CLOSED;
    errors->AddError("invalid enum value");
    return dom::ShadowRootType::USER_AGENT;
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ShadowRootType& value) {
  switch (value) {
    case dom::ShadowRootType::USER_AGENT:
      return std::make_unique<base::Value>("user-agent");
    case dom::ShadowRootType::OPEN:
      return std::make_unique<base::Value>("open");
    case dom::ShadowRootType::CLOSED:
      return std::make_unique<base::Value>("closed");
  };
  NOTREACHED();
  return nullptr;
}

template <>
struct FromValue<dom::Node> {
  static std::unique_ptr<dom::Node> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::Node::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::Node& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RGBA> {
  static std::unique_ptr<dom::RGBA> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RGBA::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RGBA& value) {
  return value.Serialize();
}



template <>
struct FromValue<dom::BoxModel> {
  static std::unique_ptr<dom::BoxModel> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::BoxModel::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::BoxModel& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ShapeOutsideInfo> {
  static std::unique_ptr<dom::ShapeOutsideInfo> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ShapeOutsideInfo::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ShapeOutsideInfo& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::Rect> {
  static std::unique_ptr<dom::Rect> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::Rect::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::Rect& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::CollectClassNamesFromSubtreeParams> {
  static std::unique_ptr<dom::CollectClassNamesFromSubtreeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::CollectClassNamesFromSubtreeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::CollectClassNamesFromSubtreeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::CollectClassNamesFromSubtreeResult> {
  static std::unique_ptr<dom::CollectClassNamesFromSubtreeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::CollectClassNamesFromSubtreeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::CollectClassNamesFromSubtreeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::CopyToParams> {
  static std::unique_ptr<dom::CopyToParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::CopyToParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::CopyToParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::CopyToResult> {
  static std::unique_ptr<dom::CopyToResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::CopyToResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::CopyToResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DescribeNodeParams> {
  static std::unique_ptr<dom::DescribeNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DescribeNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DescribeNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DescribeNodeResult> {
  static std::unique_ptr<dom::DescribeNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DescribeNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DescribeNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ScrollIntoViewIfNeededParams> {
  static std::unique_ptr<dom::ScrollIntoViewIfNeededParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ScrollIntoViewIfNeededParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ScrollIntoViewIfNeededParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ScrollIntoViewIfNeededResult> {
  static std::unique_ptr<dom::ScrollIntoViewIfNeededResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ScrollIntoViewIfNeededResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ScrollIntoViewIfNeededResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DisableParams> {
  static std::unique_ptr<dom::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DisableResult> {
  static std::unique_ptr<dom::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DiscardSearchResultsParams> {
  static std::unique_ptr<dom::DiscardSearchResultsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DiscardSearchResultsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DiscardSearchResultsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DiscardSearchResultsResult> {
  static std::unique_ptr<dom::DiscardSearchResultsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DiscardSearchResultsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DiscardSearchResultsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::EnableParams> {
  static std::unique_ptr<dom::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::EnableResult> {
  static std::unique_ptr<dom::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::FocusParams> {
  static std::unique_ptr<dom::FocusParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::FocusParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::FocusParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::FocusResult> {
  static std::unique_ptr<dom::FocusResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::FocusResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::FocusResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetAttributesParams> {
  static std::unique_ptr<dom::GetAttributesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetAttributesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetAttributesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetAttributesResult> {
  static std::unique_ptr<dom::GetAttributesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetAttributesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetAttributesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetBoxModelParams> {
  static std::unique_ptr<dom::GetBoxModelParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetBoxModelParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetBoxModelParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetBoxModelResult> {
  static std::unique_ptr<dom::GetBoxModelResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetBoxModelResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetBoxModelResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetContentQuadsParams> {
  static std::unique_ptr<dom::GetContentQuadsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetContentQuadsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetContentQuadsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetContentQuadsResult> {
  static std::unique_ptr<dom::GetContentQuadsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetContentQuadsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetContentQuadsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetDocumentParams> {
  static std::unique_ptr<dom::GetDocumentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetDocumentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetDocumentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetDocumentResult> {
  static std::unique_ptr<dom::GetDocumentResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetDocumentResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetDocumentResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetFlattenedDocumentParams> {
  static std::unique_ptr<dom::GetFlattenedDocumentParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetFlattenedDocumentParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetFlattenedDocumentParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetFlattenedDocumentResult> {
  static std::unique_ptr<dom::GetFlattenedDocumentResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetFlattenedDocumentResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetFlattenedDocumentResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetNodeForLocationParams> {
  static std::unique_ptr<dom::GetNodeForLocationParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetNodeForLocationParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetNodeForLocationParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetNodeForLocationResult> {
  static std::unique_ptr<dom::GetNodeForLocationResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetNodeForLocationResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetNodeForLocationResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetOuterHTMLParams> {
  static std::unique_ptr<dom::GetOuterHTMLParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetOuterHTMLParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetOuterHTMLParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetOuterHTMLResult> {
  static std::unique_ptr<dom::GetOuterHTMLResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetOuterHTMLResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetOuterHTMLResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetRelayoutBoundaryParams> {
  static std::unique_ptr<dom::GetRelayoutBoundaryParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetRelayoutBoundaryParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetRelayoutBoundaryParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetRelayoutBoundaryResult> {
  static std::unique_ptr<dom::GetRelayoutBoundaryResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetRelayoutBoundaryResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetRelayoutBoundaryResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetSearchResultsParams> {
  static std::unique_ptr<dom::GetSearchResultsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetSearchResultsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetSearchResultsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetSearchResultsResult> {
  static std::unique_ptr<dom::GetSearchResultsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetSearchResultsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetSearchResultsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::HideHighlightParams> {
  static std::unique_ptr<dom::HideHighlightParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::HideHighlightParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::HideHighlightParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::HideHighlightResult> {
  static std::unique_ptr<dom::HideHighlightResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::HideHighlightResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::HideHighlightResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::HighlightNodeParams> {
  static std::unique_ptr<dom::HighlightNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::HighlightNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::HighlightNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::HighlightNodeResult> {
  static std::unique_ptr<dom::HighlightNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::HighlightNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::HighlightNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::HighlightRectParams> {
  static std::unique_ptr<dom::HighlightRectParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::HighlightRectParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::HighlightRectParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::HighlightRectResult> {
  static std::unique_ptr<dom::HighlightRectResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::HighlightRectResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::HighlightRectResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::MarkUndoableStateParams> {
  static std::unique_ptr<dom::MarkUndoableStateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::MarkUndoableStateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::MarkUndoableStateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::MarkUndoableStateResult> {
  static std::unique_ptr<dom::MarkUndoableStateResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::MarkUndoableStateResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::MarkUndoableStateResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::MoveToParams> {
  static std::unique_ptr<dom::MoveToParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::MoveToParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::MoveToParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::MoveToResult> {
  static std::unique_ptr<dom::MoveToResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::MoveToResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::MoveToResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PerformSearchParams> {
  static std::unique_ptr<dom::PerformSearchParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PerformSearchParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PerformSearchParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PerformSearchResult> {
  static std::unique_ptr<dom::PerformSearchResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PerformSearchResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PerformSearchResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PushNodeByPathToFrontendParams> {
  static std::unique_ptr<dom::PushNodeByPathToFrontendParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PushNodeByPathToFrontendParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PushNodeByPathToFrontendParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PushNodeByPathToFrontendResult> {
  static std::unique_ptr<dom::PushNodeByPathToFrontendResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PushNodeByPathToFrontendResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PushNodeByPathToFrontendResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PushNodesByBackendIdsToFrontendParams> {
  static std::unique_ptr<dom::PushNodesByBackendIdsToFrontendParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PushNodesByBackendIdsToFrontendParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PushNodesByBackendIdsToFrontendParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PushNodesByBackendIdsToFrontendResult> {
  static std::unique_ptr<dom::PushNodesByBackendIdsToFrontendResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PushNodesByBackendIdsToFrontendResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PushNodesByBackendIdsToFrontendResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::QuerySelectorParams> {
  static std::unique_ptr<dom::QuerySelectorParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::QuerySelectorParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::QuerySelectorParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::QuerySelectorResult> {
  static std::unique_ptr<dom::QuerySelectorResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::QuerySelectorResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::QuerySelectorResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::QuerySelectorAllParams> {
  static std::unique_ptr<dom::QuerySelectorAllParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::QuerySelectorAllParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::QuerySelectorAllParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::QuerySelectorAllResult> {
  static std::unique_ptr<dom::QuerySelectorAllResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::QuerySelectorAllResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::QuerySelectorAllResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RedoParams> {
  static std::unique_ptr<dom::RedoParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RedoParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RedoParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RedoResult> {
  static std::unique_ptr<dom::RedoResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RedoResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RedoResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RemoveAttributeParams> {
  static std::unique_ptr<dom::RemoveAttributeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RemoveAttributeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RemoveAttributeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RemoveAttributeResult> {
  static std::unique_ptr<dom::RemoveAttributeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RemoveAttributeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RemoveAttributeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RemoveNodeParams> {
  static std::unique_ptr<dom::RemoveNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RemoveNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RemoveNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RemoveNodeResult> {
  static std::unique_ptr<dom::RemoveNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RemoveNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RemoveNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RequestChildNodesParams> {
  static std::unique_ptr<dom::RequestChildNodesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RequestChildNodesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RequestChildNodesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RequestChildNodesResult> {
  static std::unique_ptr<dom::RequestChildNodesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RequestChildNodesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RequestChildNodesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RequestNodeParams> {
  static std::unique_ptr<dom::RequestNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RequestNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RequestNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::RequestNodeResult> {
  static std::unique_ptr<dom::RequestNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::RequestNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::RequestNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ResolveNodeParams> {
  static std::unique_ptr<dom::ResolveNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ResolveNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ResolveNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ResolveNodeResult> {
  static std::unique_ptr<dom::ResolveNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ResolveNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ResolveNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetAttributeValueParams> {
  static std::unique_ptr<dom::SetAttributeValueParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetAttributeValueParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetAttributeValueParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetAttributeValueResult> {
  static std::unique_ptr<dom::SetAttributeValueResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetAttributeValueResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetAttributeValueResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetAttributesAsTextParams> {
  static std::unique_ptr<dom::SetAttributesAsTextParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetAttributesAsTextParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetAttributesAsTextParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetAttributesAsTextResult> {
  static std::unique_ptr<dom::SetAttributesAsTextResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetAttributesAsTextResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetAttributesAsTextResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetFileInputFilesParams> {
  static std::unique_ptr<dom::SetFileInputFilesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetFileInputFilesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetFileInputFilesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetFileInputFilesResult> {
  static std::unique_ptr<dom::SetFileInputFilesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetFileInputFilesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetFileInputFilesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetNodeStackTracesEnabledParams> {
  static std::unique_ptr<dom::SetNodeStackTracesEnabledParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetNodeStackTracesEnabledParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetNodeStackTracesEnabledParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetNodeStackTracesEnabledResult> {
  static std::unique_ptr<dom::SetNodeStackTracesEnabledResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetNodeStackTracesEnabledResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetNodeStackTracesEnabledResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetNodeStackTracesParams> {
  static std::unique_ptr<dom::GetNodeStackTracesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetNodeStackTracesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetNodeStackTracesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetNodeStackTracesResult> {
  static std::unique_ptr<dom::GetNodeStackTracesResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetNodeStackTracesResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetNodeStackTracesResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetFileInfoParams> {
  static std::unique_ptr<dom::GetFileInfoParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetFileInfoParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetFileInfoParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetFileInfoResult> {
  static std::unique_ptr<dom::GetFileInfoResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetFileInfoResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetFileInfoResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetInspectedNodeParams> {
  static std::unique_ptr<dom::SetInspectedNodeParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetInspectedNodeParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetInspectedNodeParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetInspectedNodeResult> {
  static std::unique_ptr<dom::SetInspectedNodeResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetInspectedNodeResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetInspectedNodeResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetNodeNameParams> {
  static std::unique_ptr<dom::SetNodeNameParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetNodeNameParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetNodeNameParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetNodeNameResult> {
  static std::unique_ptr<dom::SetNodeNameResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetNodeNameResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetNodeNameResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetNodeValueParams> {
  static std::unique_ptr<dom::SetNodeValueParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetNodeValueParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetNodeValueParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetNodeValueResult> {
  static std::unique_ptr<dom::SetNodeValueResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetNodeValueResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetNodeValueResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetOuterHTMLParams> {
  static std::unique_ptr<dom::SetOuterHTMLParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetOuterHTMLParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetOuterHTMLParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetOuterHTMLResult> {
  static std::unique_ptr<dom::SetOuterHTMLResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetOuterHTMLResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetOuterHTMLResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::UndoParams> {
  static std::unique_ptr<dom::UndoParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::UndoParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::UndoParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::UndoResult> {
  static std::unique_ptr<dom::UndoResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::UndoResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::UndoResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetFrameOwnerParams> {
  static std::unique_ptr<dom::GetFrameOwnerParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetFrameOwnerParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetFrameOwnerParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::GetFrameOwnerResult> {
  static std::unique_ptr<dom::GetFrameOwnerResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::GetFrameOwnerResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::GetFrameOwnerResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::AttributeModifiedParams> {
  static std::unique_ptr<dom::AttributeModifiedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::AttributeModifiedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::AttributeModifiedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::AttributeRemovedParams> {
  static std::unique_ptr<dom::AttributeRemovedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::AttributeRemovedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::AttributeRemovedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::CharacterDataModifiedParams> {
  static std::unique_ptr<dom::CharacterDataModifiedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::CharacterDataModifiedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::CharacterDataModifiedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ChildNodeCountUpdatedParams> {
  static std::unique_ptr<dom::ChildNodeCountUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ChildNodeCountUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ChildNodeCountUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ChildNodeInsertedParams> {
  static std::unique_ptr<dom::ChildNodeInsertedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ChildNodeInsertedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ChildNodeInsertedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ChildNodeRemovedParams> {
  static std::unique_ptr<dom::ChildNodeRemovedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ChildNodeRemovedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ChildNodeRemovedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DistributedNodesUpdatedParams> {
  static std::unique_ptr<dom::DistributedNodesUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DistributedNodesUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DistributedNodesUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::DocumentUpdatedParams> {
  static std::unique_ptr<dom::DocumentUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::DocumentUpdatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::DocumentUpdatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::InlineStyleInvalidatedParams> {
  static std::unique_ptr<dom::InlineStyleInvalidatedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::InlineStyleInvalidatedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::InlineStyleInvalidatedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PseudoElementAddedParams> {
  static std::unique_ptr<dom::PseudoElementAddedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PseudoElementAddedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PseudoElementAddedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::PseudoElementRemovedParams> {
  static std::unique_ptr<dom::PseudoElementRemovedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::PseudoElementRemovedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::PseudoElementRemovedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::SetChildNodesParams> {
  static std::unique_ptr<dom::SetChildNodesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::SetChildNodesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::SetChildNodesParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ShadowRootPoppedParams> {
  static std::unique_ptr<dom::ShadowRootPoppedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ShadowRootPoppedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ShadowRootPoppedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<dom::ShadowRootPushedParams> {
  static std::unique_ptr<dom::ShadowRootPushedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return dom::ShadowRootPushedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const dom::ShadowRootPushedParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_DOM_H_
