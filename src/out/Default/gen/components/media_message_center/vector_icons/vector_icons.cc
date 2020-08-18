// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.cc.template is used to generate vector_icons.cc. Edit the former
// rather than the latter.

#include "components/media_message_center/vector_icons/vector_icons.h"

#include "base/logging.h"
#include "components/vector_icons/cc_macros.h"
#include "ui/gfx/vector_icon_types.h"

#define DECLARE_VECTOR_COMMAND(x) using gfx::x;
DECLARE_VECTOR_COMMANDS

namespace media_message_center {

VECTOR_ICON_REP_TEMPLATE(kMediaSeekForwardPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 2, 13,
LINE_TO, 8, 8,
LINE_TO, 2, 3,
LINE_TO, 2, 13,
CLOSE,
MOVE_TO, 8, 3,
LINE_TO, 8, 13,
LINE_TO, 14, 8,
LINE_TO, 8, 3,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaSeekForwardRepList, kMediaSeekForwardIcon, {kMediaSeekForwardPath, base::size(kMediaSeekForwardPath)})
VECTOR_ICON_REP_TEMPLATE(kMediaEnterPipPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 12, 7,
H_LINE_TO, 7,
R_V_LINE_TO, 4,
R_H_LINE_TO, 5,
V_LINE_TO, 7,
CLOSE,
R_MOVE_TO, 3, 5.67f,
V_LINE_TO, 3.32f,
CUBIC_TO, 15, 2.59f, 14.43f, 2, 13.73f, 2,
H_LINE_TO, 2.27f,
CUBIC_TO, 1.57f, 2, 1, 2.59f, 1, 3.32f,
R_V_LINE_TO, 9.35f,
CUBIC_TO, 1, 13.4f, 1.57f, 14, 2.27f, 14,
R_H_LINE_TO, 11.45f,
R_CUBIC_TO, 0.7f, 0, 1.27f, -0.6f, 1.27f, -1.33f,
CLOSE,
R_MOVE_TO, -1.5f, -0.17f,
R_H_LINE_TO, -11,
R_V_LINE_TO, -9,
R_H_LINE_TO, 11,
R_V_LINE_TO, 9,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaEnterPipRepList, kMediaEnterPipIcon, {kMediaEnterPipPath, base::size(kMediaEnterPipPath)})
VECTOR_ICON_REP_TEMPLATE(kMediaExitPipPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 13.73f, 2,
R_CUBIC_TO, 0.7f, 0, 1.27f, 0.59f, 1.27f, 1.32f,
V_LINE_TO, 9,
R_H_LINE_TO, -1.5f,
V_LINE_TO, 3.5f,
R_H_LINE_TO, -11,
R_V_LINE_TO, 9,
H_LINE_TO, 9,
V_LINE_TO, 14,
H_LINE_TO, 2.27f,
CUBIC_TO, 1.57f, 14, 1, 13.4f, 1, 12.67f,
V_LINE_TO, 3.32f,
CUBIC_TO, 1, 2.59f, 1.57f, 2, 2.27f, 2,
CLOSE,
MOVE_TO, 9, 5,
H_LINE_TO, 4,
R_V_LINE_TO, 4,
R_H_LINE_TO, 5,
CLOSE,
MOVE_TO, 12, 10,
R_V_LINE_TO, 4,
R_H_LINE_TO, -1,
R_V_LINE_TO, -4,
CLOSE,
MOVE_TO, 11.71f, 10,
R_LINE_TO, 4.24f, 4.24f,
R_LINE_TO, -0.71f, 0.71f,
LINE_TO, 11, 10.71f,
CLOSE,
MOVE_TO, 11, 10,
R_H_LINE_TO, 4,
R_V_LINE_TO, 1,
R_H_LINE_TO, -4,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaExitPipRepList, kMediaExitPipIcon, {kMediaExitPipPath, base::size(kMediaExitPipPath)})
VECTOR_ICON_REP_TEMPLATE(kMediaPreviousTrackPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 3, 3,
LINE_TO, 5, 3,
LINE_TO, 5, 13,
LINE_TO, 3, 13,
LINE_TO, 3, 3,
CLOSE,
MOVE_TO, 7, 8,
LINE_TO, 13, 13,
LINE_TO, 13, 3,
LINE_TO, 7, 8,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaPreviousTrackRepList, kMediaPreviousTrackIcon, {kMediaPreviousTrackPath, base::size(kMediaPreviousTrackPath)})
VECTOR_ICON_REP_TEMPLATE(kMediaNextTrackPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 3, 13,
LINE_TO, 9, 8,
LINE_TO, 3, 3,
LINE_TO, 3, 13,
CLOSE,
MOVE_TO, 11, 3,
LINE_TO, 11, 13,
LINE_TO, 13, 13,
LINE_TO, 13, 3,
LINE_TO, 11, 3,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaNextTrackRepList, kMediaNextTrackIcon, {kMediaNextTrackPath, base::size(kMediaNextTrackPath)})
VECTOR_ICON_REP_TEMPLATE(kMediaSeekBackwardPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 8, 13,
LINE_TO, 8, 3,
LINE_TO, 2, 8,
LINE_TO, 8, 13,
CLOSE,
MOVE_TO, 8, 8,
LINE_TO, 14, 13,
LINE_TO, 14, 3,
LINE_TO, 8, 8,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kMediaSeekBackwardRepList, kMediaSeekBackwardIcon, {kMediaSeekBackwardPath, base::size(kMediaSeekBackwardPath)})
VECTOR_ICON_REP_TEMPLATE(kPausePath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 7, 2,
LINE_TO, 7, 14,
LINE_TO, 4, 14,
LINE_TO, 4, 2,
LINE_TO, 7, 2,
CLOSE,
MOVE_TO, 12, 2,
LINE_TO, 12, 14,
LINE_TO, 9, 14,
LINE_TO, 9, 2,
LINE_TO, 12, 2,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPauseRepList, kPauseIcon, {kPausePath, base::size(kPausePath)})
VECTOR_ICON_REP_TEMPLATE(kPlayArrowPath, CANVAS_DIMENSIONS, 16,
MOVE_TO, 6, 13,
R_LINE_TO, 6, -5,
R_LINE_TO, -6, -5,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kPlayArrowRepList, kPlayArrowIcon, {kPlayArrowPath, base::size(kPlayArrowPath)})

}
