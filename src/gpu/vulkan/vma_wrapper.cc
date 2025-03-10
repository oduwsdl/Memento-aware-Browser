// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gpu/vulkan/vma_wrapper.h"

#include <vk_mem_alloc.h>

#include "build/build_config.h"
#include "gpu/vulkan/vulkan_function_pointers.h"

namespace gpu {
namespace vma {

VkResult CreateAllocator(VkPhysicalDevice physical_device,
                         VkDevice device,
                         VkInstance instance,
                         VmaAllocator* pAllocator) {
  auto* function_pointers = gpu::GetVulkanFunctionPointers();
  VmaVulkanFunctions functions = {
      function_pointers->vkGetPhysicalDeviceProperties.get(),
      function_pointers->vkGetPhysicalDeviceMemoryProperties.get(),
      function_pointers->vkAllocateMemory.get(),
      function_pointers->vkFreeMemory.get(),
      function_pointers->vkMapMemory.get(),
      function_pointers->vkUnmapMemory.get(),
      function_pointers->vkFlushMappedMemoryRanges.get(),
      function_pointers->vkInvalidateMappedMemoryRanges.get(),
      function_pointers->vkBindBufferMemory.get(),
      function_pointers->vkBindImageMemory.get(),
      function_pointers->vkGetBufferMemoryRequirements.get(),
      function_pointers->vkGetImageMemoryRequirements.get(),
      function_pointers->vkCreateBuffer.get(),
      function_pointers->vkDestroyBuffer.get(),
      function_pointers->vkCreateImage.get(),
      function_pointers->vkDestroyImage.get(),
      function_pointers->vkCmdCopyBuffer.get(),
      function_pointers->vkGetBufferMemoryRequirements2.get(),
      function_pointers->vkGetImageMemoryRequirements2.get(),
      function_pointers->vkBindBufferMemory2.get(),
      function_pointers->vkBindImageMemory2.get(),
      function_pointers->vkGetPhysicalDeviceMemoryProperties2.get(),
  };

  static_assert(kVulkanRequiredApiVersion >= VK_API_VERSION_1_1, "");
  VmaAllocatorCreateInfo allocator_info = {
      .flags = VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT,
      .physicalDevice = physical_device,
      .device = device,
      // 4MB was picked for the size here by looking at memory usage of Android
      // apps and runs of DM. It seems to be a good compromise of not wasting
      // unused allocated space and not making too many small allocations. The
      // AMD allocator will start making blocks at 1/8 the max size and builds
      // up block size as needed before capping at the max set here.
      .preferredLargeHeapBlockSize = 4 * 1024 * 1024,
      .pVulkanFunctions = &functions,
      .instance = instance,
      .vulkanApiVersion = kVulkanRequiredApiVersion,
  };

  return vmaCreateAllocator(&allocator_info, pAllocator);
}

void DestroyAllocator(VmaAllocator allocator) {
  vmaDestroyAllocator(allocator);
}

VkResult AllocateMemoryForImage(VmaAllocator allocator,
                                VkImage image,
                                const VmaAllocationCreateInfo* create_info,
                                VmaAllocation* allocation,
                                VmaAllocationInfo* allocation_info) {
  return vmaAllocateMemoryForImage(allocator, image, create_info, allocation,
                                   allocation_info);
}

VkResult AllocateMemoryForBuffer(VmaAllocator allocator,
                                 VkBuffer buffer,
                                 const VmaAllocationCreateInfo* create_info,
                                 VmaAllocation* allocation,
                                 VmaAllocationInfo* allocation_info) {
  return vmaAllocateMemoryForBuffer(allocator, buffer, create_info, allocation,
                                    allocation_info);
}

VkResult CreateBuffer(VmaAllocator allocator,
                      const VkBufferCreateInfo* buffer_create_info,
                      VkMemoryPropertyFlags required_flags,
                      VkMemoryPropertyFlags preferred_flags,
                      VkBuffer* buffer,
                      VmaAllocation* allocation) {
  VmaAllocationCreateInfo allocation_create_info = {
      .requiredFlags = required_flags,
      .preferredFlags = preferred_flags,
  };

  return vmaCreateBuffer(allocator, buffer_create_info, &allocation_create_info,
                         buffer, allocation, nullptr);
}

void DestroyBuffer(VmaAllocator allocator,
                   VkBuffer buffer,
                   VmaAllocation allocation) {
  vmaDestroyBuffer(allocator, buffer, allocation);
}

VkResult MapMemory(VmaAllocator allocator,
                   VmaAllocation allocation,
                   void** data) {
  return vmaMapMemory(allocator, allocation, data);
}

void UnmapMemory(VmaAllocator allocator, VmaAllocation allocation) {
  return vmaUnmapMemory(allocator, allocation);
}

void FreeMemory(VmaAllocator allocator, VmaAllocation allocation) {
  vmaFreeMemory(allocator, allocation);
}

void FlushAllocation(VmaAllocator allocator,
                     VmaAllocation allocation,
                     VkDeviceSize offset,
                     VkDeviceSize size) {
  vmaFlushAllocation(allocator, allocation, offset, size);
}

void InvalidateAllocation(VmaAllocator allocator,
                          VmaAllocation allocation,
                          VkDeviceSize offset,
                          VkDeviceSize size) {
  vmaInvalidateAllocation(allocator, allocation, offset, size);
}

void GetAllocationInfo(VmaAllocator allocator,
                       VmaAllocation allocation,
                       VmaAllocationInfo* allocation_info) {
  vmaGetAllocationInfo(allocator, allocation, allocation_info);
}

void GetMemoryTypeProperties(VmaAllocator allocator,
                             uint32_t memory_type_index,
                             VkMemoryPropertyFlags* flags) {
  vmaGetMemoryTypeProperties(allocator, memory_type_index, flags);
}

void GetPhysicalDeviceProperties(
    VmaAllocator allocator,
    const VkPhysicalDeviceProperties** physical_device_properties) {
  vmaGetPhysicalDeviceProperties(allocator, physical_device_properties);
}

void CalculateStats(VmaAllocator allocator, VmaStats* stats) {
  vmaCalculateStats(allocator, stats);
}

}  // namespace vma
}  // namespace gpu