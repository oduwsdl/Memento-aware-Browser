// Copyright 2019 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#ifndef CORE_FXGE_RENDER_DEFINES_H_
#define CORE_FXGE_RENDER_DEFINES_H_

#define FXDC_PIXEL_WIDTH 2
#define FXDC_PIXEL_HEIGHT 3
#define FXDC_BITS_PIXEL 4
#define FXDC_HORZ_SIZE 5
#define FXDC_VERT_SIZE 6
#define FXDC_RENDER_CAPS 7

#define FXRC_GET_BITS 0x01
#define FXRC_BIT_MASK 0x02
#define FXRC_ALPHA_PATH 0x10
#define FXRC_ALPHA_IMAGE 0x20
#define FXRC_ALPHA_OUTPUT 0x40
#define FXRC_BLEND_MODE 0x80
#define FXRC_SOFT_CLIP 0x100
#define FXRC_CMYK_OUTPUT 0x200
#define FXRC_BITMASK_OUTPUT 0x400
#define FXRC_BYTEMASK_OUTPUT 0x800
#define FXRENDER_IMAGE_LOSSY 0x1000
#define FXRC_FILLSTROKE_PATH 0x2000
#define FXRC_SHADING 0x4000

#define FXFILL_ALTERNATE 1
#define FXFILL_WINDING 2
#define FXFILL_FULLCOVER 4
#define FXFILL_RECT_AA 8
#define FX_FILL_STROKE 16
#define FX_STROKE_ADJUST 32
#define FX_STROKE_TEXT_MODE 64
#define FX_FILL_TEXT_MODE 128
#define FX_ZEROAREA_FILL 256
#define FXFILL_NOPATHSMOOTH 512

#endif  // CORE_FXGE_RENDER_DEFINES_H_
