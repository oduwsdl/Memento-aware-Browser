// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/ozone/platform/scenic/sysmem_buffer_manager.h"

#include <zircon/rights.h>

#include "base/bind.h"
#include "base/hash/hash.h"
#include "ui/ozone/platform/scenic/sysmem_buffer_collection.h"

namespace ui {

SysmemBufferManager::SysmemBufferManager() = default;

SysmemBufferManager::~SysmemBufferManager() {
  Shutdown();
}

void SysmemBufferManager::Initialize(
    fuchsia::sysmem::AllocatorHandle allocator) {
  base::AutoLock auto_lock(collections_lock_);
  DCHECK(collections_.empty());
  DCHECK(!allocator_);
  allocator_.Bind(std::move(allocator));
}

void SysmemBufferManager::Shutdown() {
  base::AutoLock auto_lock(collections_lock_);
  DCHECK(collections_.empty());
  allocator_ = nullptr;
}

scoped_refptr<SysmemBufferCollection> SysmemBufferManager::CreateCollection(
    VkDevice vk_device,
    gfx::Size size,
    gfx::BufferFormat format,
    gfx::BufferUsage usage,
    size_t num_buffers) {
  auto result = base::MakeRefCounted<SysmemBufferCollection>();
  if (!result->Initialize(allocator_.get(), size, format, usage, vk_device,
                          num_buffers)) {
    return nullptr;
  }
  RegisterCollection(result.get());
  return result;
}

scoped_refptr<SysmemBufferCollection>
SysmemBufferManager::ImportSysmemBufferCollection(
    VkDevice vk_device,
    gfx::SysmemBufferCollectionId id,
    zx::channel token,
    gfx::BufferFormat format,
    gfx::BufferUsage usage) {
  auto result = base::MakeRefCounted<SysmemBufferCollection>(id);
  if (!result->Initialize(allocator_.get(), vk_device, std::move(token), format,
                          usage)) {
    return nullptr;
  }
  RegisterCollection(result.get());
  return result;
}

void SysmemBufferManager::RegisterCollection(
    SysmemBufferCollection* collection) {
  {
    base::AutoLock auto_lock(collections_lock_);
    collections_[collection->id()] = collection;
  }

  collection->SetOnDeletedCallback(
      base::BindOnce(&SysmemBufferManager::OnCollectionDestroyed,
                     base::Unretained(this), collection->id()));
}

scoped_refptr<SysmemBufferCollection> SysmemBufferManager::GetCollectionById(
    gfx::SysmemBufferCollectionId id) {
  base::AutoLock auto_lock(collections_lock_);
  auto it = collections_.find(id);
  return it == collections_.end() ? nullptr : it->second;
}

void SysmemBufferManager::OnCollectionDestroyed(
    gfx::SysmemBufferCollectionId id) {
  base::AutoLock auto_lock(collections_lock_);
  int erased = collections_.erase(id);
  DCHECK_EQ(erased, 1);
}

}  // namespace ui
