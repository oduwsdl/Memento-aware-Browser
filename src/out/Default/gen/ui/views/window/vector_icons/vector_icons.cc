// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.cc.template is used to generate vector_icons.cc. Edit the former
// rather than the latter.

#include "ui/views/window/vector_icons/vector_icons.h"

#include "base/logging.h"
#include "components/vector_icons/cc_macros.h"
#include "ui/gfx/vector_icon_types.h"

#define DECLARE_VECTOR_COMMAND(x) using gfx::x;
DECLARE_VECTOR_COMMANDS

namespace views {

VECTOR_ICON_REP_TEMPLATE(kWindowControlMaximizePath, CANVAS_DIMENSIONS, 24,
MOVE_TO, 23, 1,
R_V_LINE_TO, 22,
H_LINE_TO, 1,
V_LINE_TO, 1,
R_H_LINE_TO, 22,
CLOSE,
R_MOVE_TO, -3, 19,
H_LINE_TO, 4,
V_LINE_TO, 4,
R_H_LINE_TO, 16,
R_V_LINE_TO, 16,
CLOSE)
VECTOR_ICON_REP_TEMPLATE(kWindowControlMaximize12Path, CANVAS_DIMENSIONS, 12,
MOVE_TO, 11, 1,
R_V_LINE_TO, 10,
H_LINE_TO, 1,
V_LINE_TO, 1,
R_H_LINE_TO, 10,
CLOSE,
MOVE_TO, 9, 9,
H_LINE_TO, 3,
V_LINE_TO, 3,
R_H_LINE_TO, 6,
R_V_LINE_TO, 6,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kWindowControlMaximizeRepList, kWindowControlMaximizeIcon, {kWindowControlMaximizePath, base::size(kWindowControlMaximizePath)}, {kWindowControlMaximize12Path, base::size(kWindowControlMaximize12Path)})
VECTOR_ICON_REP_TEMPLATE(kWindowControlMinimizePath, CANVAS_DIMENSIONS, 24,
MOVE_TO, 1, 20,
R_H_LINE_TO, 22,
R_V_LINE_TO, 3,
H_LINE_TO, 1,
CLOSE)
VECTOR_ICON_REP_TEMPLATE(kWindowControlMinimize12Path, CANVAS_DIMENSIONS, 12,
MOVE_TO, 1, 9,
R_H_LINE_TO, 10,
R_V_LINE_TO, 2,
H_LINE_TO, 1,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kWindowControlMinimizeRepList, kWindowControlMinimizeIcon, {kWindowControlMinimizePath, base::size(kWindowControlMinimizePath)}, {kWindowControlMinimize12Path, base::size(kWindowControlMinimize12Path)})
VECTOR_ICON_REP_TEMPLATE(kWindowControlClosePath, CANVAS_DIMENSIONS, 24,
MOVE_TO, 23, 3.22f,
LINE_TO, 20.78f, 1,
LINE_TO, 12, 9.78f,
LINE_TO, 3.22f, 1,
LINE_TO, 1, 3.22f,
LINE_TO, 9.78f, 12,
LINE_TO, 1, 20.78f,
LINE_TO, 3.22f, 23,
LINE_TO, 12, 14.22f,
LINE_TO, 20.78f, 23,
LINE_TO, 23, 20.78f,
LINE_TO, 14.22f, 12,
LINE_TO, 23, 3.22f,
CLOSE)
VECTOR_ICON_REP_TEMPLATE(kWindowControlClose12Path, CANVAS_DIMENSIONS, 12,
MOVE_TO, 6, 4.59f,
LINE_TO, 2.46f, 1.05f,
LINE_TO, 1.05f, 2.46f,
LINE_TO, 4.59f, 6,
LINE_TO, 1.05f, 9.54f,
R_LINE_TO, 1.41f, 1.41f,
LINE_TO, 6, 7.41f,
R_LINE_TO, 3.54f, 3.54f,
R_LINE_TO, 1.41f, -1.41f,
LINE_TO, 7.41f, 6,
R_LINE_TO, 3.54f, -3.54f,
LINE_TO, 9.54f, 1.05f,
LINE_TO, 6, 4.59f,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kWindowControlCloseRepList, kWindowControlCloseIcon, {kWindowControlClosePath, base::size(kWindowControlClosePath)}, {kWindowControlClose12Path, base::size(kWindowControlClose12Path)})
VECTOR_ICON_REP_TEMPLATE(kWindowControlRestorePath, CANVAS_DIMENSIONS, 24,
MOVE_TO, 23, 16,
H_LINE_TO, 8,
V_LINE_TO, 1,
R_H_LINE_TO, 15,
R_V_LINE_TO, 15,
CLOSE,
R_MOVE_TO, -12, -3,
V_LINE_TO, 4,
R_H_LINE_TO, 9,
R_V_LINE_TO, 9,
R_H_LINE_TO, -9,
CLOSE,
MOVE_TO, 4, 8,
H_LINE_TO, 1,
R_V_LINE_TO, 15,
R_H_LINE_TO, 15,
R_V_LINE_TO, -3,
H_LINE_TO, 4,
V_LINE_TO, 8,
CLOSE)
VECTOR_ICON_REP_TEMPLATE(kWindowControlRestore12Path, CANVAS_DIMENSIONS, 12,
MOVE_TO, 11, 8,
H_LINE_TO, 4,
V_LINE_TO, 1,
R_H_LINE_TO, 7,
R_V_LINE_TO, 7,
CLOSE,
MOVE_TO, 6, 6,
V_LINE_TO, 3,
R_H_LINE_TO, 3,
R_V_LINE_TO, 3,
H_LINE_TO, 6,
CLOSE,
MOVE_TO, 3, 3,
H_LINE_TO, 1,
R_V_LINE_TO, 8,
R_H_LINE_TO, 8,
V_LINE_TO, 9,
H_LINE_TO, 3,
V_LINE_TO, 3,
CLOSE)
VECTOR_ICON_TEMPLATE_CC(kWindowControlRestoreRepList, kWindowControlRestoreIcon, {kWindowControlRestorePath, base::size(kWindowControlRestorePath)}, {kWindowControlRestore12Path, base::size(kWindowControlRestore12Path)})

}  // namespace views
