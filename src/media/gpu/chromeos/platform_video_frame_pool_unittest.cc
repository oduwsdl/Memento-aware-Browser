// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/gpu/chromeos/platform_video_frame_pool.h"

#include <stddef.h>
#include <stdint.h>
#include <memory>
#include <vector>

#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/files/scoped_file.h"
#include "base/test/task_environment.h"
#include "base/threading/thread_task_runner_handle.h"
#include "media/gpu/chromeos/fourcc.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace media {

namespace {

base::ScopedFD CreateTmpHandle() {
  base::FilePath path;
  DCHECK(CreateTemporaryFile(&path));
  base::File file(path, base::File::FLAG_OPEN | base::File::FLAG_READ);
  DCHECK(file.IsValid());
  return base::ScopedFD(file.TakePlatformFile());
}

scoped_refptr<VideoFrame> CreateDmabufVideoFrame(
    gpu::GpuMemoryBufferFactory* factory,
    VideoPixelFormat format,
    const gfx::Size& coded_size,
    const gfx::Rect& visible_rect,
    const gfx::Size& natural_size,
    base::TimeDelta timestamp) {
  base::Optional<VideoFrameLayout> layout =
      VideoFrameLayout::Create(format, coded_size);
  DCHECK(layout);

  std::vector<base::ScopedFD> dmabuf_fds;
  for (size_t i = 0; i < VideoFrame::NumPlanes(format); ++i)
    dmabuf_fds.push_back(CreateTmpHandle());

  return VideoFrame::WrapExternalDmabufs(*layout, visible_rect, natural_size,
                                         std::move(dmabuf_fds), timestamp);
}

}  // namespace

class PlatformVideoFramePoolTest
    : public ::testing::TestWithParam<VideoPixelFormat> {
 public:
  using DmabufId = DmabufVideoFramePool::DmabufId;

  PlatformVideoFramePoolTest()
      : task_environment_(base::test::TaskEnvironment::TimeSource::MOCK_TIME),
        pool_(new PlatformVideoFramePool(nullptr)) {
    SetCreateFrameCB(base::BindRepeating(&CreateDmabufVideoFrame));
    pool_->set_parent_task_runner(base::ThreadTaskRunnerHandle::Get());
  }

  bool Initialize(const Fourcc& fourcc) {
    constexpr gfx::Size kCodedSize(320, 240);
    constexpr size_t kNumFrames = 10;

    visible_rect_.set_size(kCodedSize);
    natural_size_ = kCodedSize;

    layout_ = pool_->Initialize(fourcc, kCodedSize, visible_rect_,
                                natural_size_, kNumFrames);
    return !!layout_;
  }

  scoped_refptr<VideoFrame> GetFrame(int timestamp_ms) {
    scoped_refptr<VideoFrame> frame = pool_->GetFrame();
    frame->set_timestamp(base::TimeDelta::FromMilliseconds(timestamp_ms));

    EXPECT_EQ(layout_->fourcc(),
              *Fourcc::FromVideoPixelFormat(frame->format()));
    EXPECT_EQ(layout_->size(), frame->coded_size());
    EXPECT_EQ(visible_rect_, frame->visible_rect());
    EXPECT_EQ(natural_size_, frame->natural_size());

    return frame;
  }

  void SetCreateFrameCB(PlatformVideoFramePool::CreateFrameCB cb) {
    pool_->create_frame_cb_ = cb;
  }

 protected:
  base::test::TaskEnvironment task_environment_;
  std::unique_ptr<PlatformVideoFramePool> pool_;

  base::Optional<GpuBufferLayout> layout_;
  gfx::Rect visible_rect_;
  gfx::Size natural_size_;
};

INSTANTIATE_TEST_SUITE_P(All,
                         PlatformVideoFramePoolTest,
                         testing::Values(PIXEL_FORMAT_I420,
                                         PIXEL_FORMAT_YV12,
                                         PIXEL_FORMAT_NV12,
                                         PIXEL_FORMAT_ARGB,
                                         PIXEL_FORMAT_P016LE));

TEST_P(PlatformVideoFramePoolTest, SingleFrameReuse) {
  const auto fourcc = Fourcc::FromVideoPixelFormat(GetParam());
  ASSERT_TRUE(fourcc.has_value());
  ASSERT_TRUE(Initialize(fourcc.value()));
  scoped_refptr<VideoFrame> frame = GetFrame(10);
  DmabufId id = DmabufVideoFramePool::GetDmabufId(*frame);

  // Clear frame reference to return the frame to the pool.
  frame = nullptr;
  task_environment_.RunUntilIdle();

  // Verify that the next frame from the pool uses the same memory.
  scoped_refptr<VideoFrame> new_frame = GetFrame(20);
  EXPECT_EQ(id, DmabufVideoFramePool::GetDmabufId(*new_frame));
}

TEST_P(PlatformVideoFramePoolTest, MultipleFrameReuse) {
  const auto fourcc = Fourcc::FromVideoPixelFormat(GetParam());
  ASSERT_TRUE(fourcc.has_value());
  ASSERT_TRUE(Initialize(fourcc.value()));
  scoped_refptr<VideoFrame> frame1 = GetFrame(10);
  scoped_refptr<VideoFrame> frame2 = GetFrame(20);
  DmabufId id1 = DmabufVideoFramePool::GetDmabufId(*frame1);
  DmabufId id2 = DmabufVideoFramePool::GetDmabufId(*frame2);

  frame1 = nullptr;
  task_environment_.RunUntilIdle();
  frame1 = GetFrame(30);
  EXPECT_EQ(id1, DmabufVideoFramePool::GetDmabufId(*frame1));

  frame2 = nullptr;
  task_environment_.RunUntilIdle();
  frame2 = GetFrame(40);
  EXPECT_EQ(id2, DmabufVideoFramePool::GetDmabufId(*frame2));

  frame1 = nullptr;
  frame2 = nullptr;
  task_environment_.RunUntilIdle();
  EXPECT_EQ(2u, pool_->GetPoolSizeForTesting());
}

TEST_P(PlatformVideoFramePoolTest, InitializeWithDifferentFourcc) {
  const auto fourcc = Fourcc::FromVideoPixelFormat(GetParam());
  ASSERT_TRUE(fourcc.has_value());
  ASSERT_TRUE(Initialize(fourcc.value()));
  scoped_refptr<VideoFrame> frame_a = GetFrame(10);
  scoped_refptr<VideoFrame> frame_b = GetFrame(10);

  // Clear frame references to return the frames to the pool.
  frame_a = nullptr;
  frame_b = nullptr;
  task_environment_.RunUntilIdle();

  // Verify that both frames are in the pool.
  EXPECT_EQ(2u, pool_->GetPoolSizeForTesting());

  // Verify that requesting a frame with a different format causes the pool
  // to get drained.
  const Fourcc different_fourcc(Fourcc::NV21);
  ASSERT_NE(fourcc, different_fourcc);
  ASSERT_TRUE(Initialize(different_fourcc));
  scoped_refptr<VideoFrame> new_frame = GetFrame(10);
  EXPECT_EQ(0u, pool_->GetPoolSizeForTesting());
}

TEST_P(PlatformVideoFramePoolTest, UnwrapVideoFrame) {
  const auto fourcc = Fourcc::FromVideoPixelFormat(GetParam());
  ASSERT_TRUE(fourcc.has_value());
  ASSERT_TRUE(Initialize(fourcc.value()));
  scoped_refptr<VideoFrame> frame_1 = GetFrame(10);
  scoped_refptr<VideoFrame> frame_2 = VideoFrame::WrapVideoFrame(
      frame_1, frame_1->format(), frame_1->visible_rect(),
      frame_1->natural_size());
  EXPECT_EQ(pool_->UnwrapFrame(*frame_1), pool_->UnwrapFrame(*frame_2));
  EXPECT_TRUE(frame_1->IsSameDmaBufsAs(*frame_2));

  scoped_refptr<VideoFrame> frame_3 = GetFrame(20);
  EXPECT_NE(pool_->UnwrapFrame(*frame_1), pool_->UnwrapFrame(*frame_3));
  EXPECT_FALSE(frame_1->IsSameDmaBufsAs(*frame_3));
}

TEST_P(PlatformVideoFramePoolTest, InitializeWithSameFourcc) {
  const auto fourcc = Fourcc::FromVideoPixelFormat(GetParam());
  ASSERT_TRUE(fourcc.has_value());
  ASSERT_TRUE(Initialize(fourcc.value()));
  scoped_refptr<VideoFrame> frame1 = GetFrame(10);
  DmabufId id1 = DmabufVideoFramePool::GetDmabufId(*frame1);

  // Clear frame references to return the frames to the pool.
  frame1 = nullptr;
  task_environment_.RunUntilIdle();

  // Request frame with the same format. The pool should not request new frames.
  ASSERT_TRUE(Initialize(fourcc.value()));

  scoped_refptr<VideoFrame> frame2 = GetFrame(20);
  DmabufId id2 = DmabufVideoFramePool::GetDmabufId(*frame2);
  EXPECT_EQ(id1, id2);
}

TEST_P(PlatformVideoFramePoolTest, InitializeFail) {
  const auto fourcc = Fourcc::FromVideoPixelFormat(GetParam());
  ASSERT_TRUE(fourcc.has_value());
  SetCreateFrameCB(base::BindRepeating(
      [](gpu::GpuMemoryBufferFactory* factory, VideoPixelFormat format,
         const gfx::Size& coded_size, const gfx::Rect& visible_rect,
         const gfx::Size& natural_size, base::TimeDelta timestamp) {
        auto frame = scoped_refptr<VideoFrame>(nullptr);
        return frame;
      }));

  EXPECT_FALSE(Initialize(fourcc.value()));
}

// TODO(akahuang): Add a testcase to verify calling Initialize() only with
// different |max_num_frames|.

}  // namespace media
