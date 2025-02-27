// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/cursor/cursor_loader_ozone.h"

#include <vector>

#include "ui/base/cursor/cursor_factory.h"
#include "ui/base/cursor/cursor_util.h"
#include "ui/base/cursor/mojom/cursor_type.mojom-shared.h"

namespace ui {

CursorLoaderOzone::CursorLoaderOzone() {
  factory_ = CursorFactory::GetInstance();
}

CursorLoaderOzone::~CursorLoaderOzone() {
  UnloadAll();
}

void CursorLoaderOzone::LoadImageCursor(mojom::CursorType id,
                                        int resource_id,
                                        const gfx::Point& hot) {
  SkBitmap bitmap;
  gfx::Point hotspot = hot;

  GetImageCursorBitmap(resource_id, scale(), rotation(), &hotspot, &bitmap);

  image_cursors_[id] = factory_->CreateImageCursor(bitmap, hotspot, scale());
}

void CursorLoaderOzone::LoadAnimatedCursor(mojom::CursorType id,
                                           int resource_id,
                                           const gfx::Point& hot,
                                           int frame_delay_ms) {
  std::vector<SkBitmap> bitmaps;
  gfx::Point hotspot = hot;

  GetAnimatedCursorBitmaps(
      resource_id, scale(), rotation(), &hotspot, &bitmaps);

  image_cursors_[id] =
      factory_->CreateAnimatedCursor(bitmaps, hotspot, frame_delay_ms, scale());
}

void CursorLoaderOzone::UnloadAll() {
  for (const auto& image_cursor : image_cursors_)
    factory_->UnrefImageCursor(image_cursor.second);
  image_cursors_.clear();
}

void CursorLoaderOzone::SetPlatformCursor(gfx::NativeCursor* cursor) {
  mojom::CursorType native_type = cursor->type();
  PlatformCursor platform;

  if (image_cursors_.count(native_type)) {
    // An image cursor is loaded for this type.
    platform = image_cursors_[native_type];
  } else if (native_type == mojom::CursorType::kCustom) {
    // The platform cursor was already set via WebCursor::GetPlatformCursor.
    platform = cursor->platform();
  } else {
    // Use default cursor of this type.
    platform = factory_->GetDefaultCursor(native_type);
  }

  cursor->set_image_scale_factor(scale());
  cursor->SetPlatformCursor(platform);
}

CursorLoader* CursorLoader::Create() {
  return new CursorLoaderOzone();
}

}  // namespace ui
