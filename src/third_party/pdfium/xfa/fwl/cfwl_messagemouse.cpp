// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "xfa/fwl/cfwl_messagemouse.h"

#include <memory>

CFWL_MessageMouse::CFWL_MessageMouse(CFWL_Widget* pDstTarget,
                                     FWL_MouseCommand cmd)
    : CFWL_Message(CFWL_Message::Type::Mouse, nullptr, pDstTarget),
      m_dwCmd(cmd) {}

CFWL_MessageMouse::CFWL_MessageMouse(CFWL_Widget* pDstTarget,
                                     FWL_MouseCommand cmd,
                                     uint32_t flags,
                                     CFX_PointF pos)
    : CFWL_Message(CFWL_Message::Type::Mouse, nullptr, pDstTarget),
      m_dwCmd(cmd),
      m_dwFlags(flags),
      m_pos(pos) {}

CFWL_MessageMouse::~CFWL_MessageMouse() = default;
