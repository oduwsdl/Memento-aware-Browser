// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "gpu/command_buffer/service/image_reader_gl_owner.h"

#include <android/native_window_jni.h>
#include <jni.h>
#include <stdint.h>

#include "base/android/android_hardware_buffer_compat.h"
#include "base/android/jni_android.h"
#include "base/android/scoped_hardware_buffer_fence_sync.h"
#include "base/logging.h"
#include "base/memory/ptr_util.h"
#include "base/metrics/histogram_functions.h"
#include "base/metrics/histogram_macros.h"
#include "base/posix/eintr_wrapper.h"
#include "base/synchronization/waitable_event.h"
#include "base/threading/thread_task_runner_handle.h"
#include "gpu/command_buffer/service/abstract_texture.h"
#include "gpu/ipc/common/android/android_image_reader_utils.h"
#include "ui/gl/android/android_surface_control_compat.h"
#include "ui/gl/gl_fence_android_native_fence_sync.h"
#include "ui/gl/gl_utils.h"
#include "ui/gl/scoped_binders.h"
#include "ui/gl/scoped_make_current.h"

namespace gpu {

namespace {
bool IsSurfaceControl(TextureOwner::Mode mode) {
  switch (mode) {
    case TextureOwner::Mode::kAImageReaderInsecureSurfaceControl:
    case TextureOwner::Mode::kAImageReaderSecureSurfaceControl:
      return true;
    case TextureOwner::Mode::kAImageReaderInsecure:
      return false;
    case TextureOwner::Mode::kSurfaceTextureInsecure:
      NOTREACHED();
      return false;
  }
  NOTREACHED();
  return false;
}
}  // namespace

// This class is safe to be created/destroyed on different threads. This is made
// sure by destruction happening on correct thread. This class is not thread
// safe to be used concurrently on multiple thraeads.
class ImageReaderGLOwner::ScopedHardwareBufferImpl
    : public base::android::ScopedHardwareBufferFenceSync {
 public:
  ScopedHardwareBufferImpl(base::WeakPtr<ImageReaderGLOwner> texture_owner,
                           AImage* image,
                           base::android::ScopedHardwareBufferHandle handle,
                           base::ScopedFD fence_fd)
      : base::android::ScopedHardwareBufferFenceSync(std::move(handle),
                                                     std::move(fence_fd)),
        texture_owner_(std::move(texture_owner)),
        image_(image),
        task_runner_(base::ThreadTaskRunnerHandle::Get()) {
    DCHECK(image_);
    texture_owner_->RegisterRefOnImage(image_);
  }

  ~ScopedHardwareBufferImpl() override {
    if (task_runner_->RunsTasksInCurrentSequence()) {
      if (texture_owner_) {
        texture_owner_->ReleaseRefOnImage(image_, std::move(read_fence_));
      }
    } else {
      task_runner_->PostTask(
          FROM_HERE,
          base::BindOnce(&gpu::ImageReaderGLOwner::ReleaseRefOnImage,
                         texture_owner_, image_, std::move(read_fence_)));
    }
  }

  void SetReadFence(base::ScopedFD fence_fd, bool has_context) final {
    // Client can call this method multiple times for a hardware buffer. Hence
    // all the client provided sync_fd should be merged. Eg: BeginReadAccess()
    // can be called multiple times for a SharedImageVideo representation.
    read_fence_ = gl::MergeFDs(std::move(read_fence_), std::move(fence_fd));
  }

 private:
  base::ScopedFD read_fence_;
  base::WeakPtr<ImageReaderGLOwner> texture_owner_;
  AImage* image_;
  scoped_refptr<base::SingleThreadTaskRunner> task_runner_;
};

ImageReaderGLOwner::ImageReaderGLOwner(
    std::unique_ptr<gles2::AbstractTexture> texture,
    Mode mode)
    : TextureOwner(false /* binds_texture_on_image_update */,
                   std::move(texture)),
      loader_(base::android::AndroidImageReader::GetInstance()),
      context_(gl::GLContext::GetCurrent()),
      surface_(gl::GLSurface::GetCurrent()) {
  DCHECK(context_);
  DCHECK(surface_);

  // Set the width, height and format to some default value. This parameters
  // are/maybe overriden by the producer sending buffers to this imageReader's
  // Surface.
  int32_t width = 1, height = 1;

  // This should be as small as possible to limit the memory usage.
  // ImageReader needs 1 image to mimic the behavior of SurfaceTexture. Ideally
  // it should be 2 but that doesn't work on some devices
  // (see crbug.com/1051705).
  // For SurfaceControl we need 3 images instead of 2 since 1 frame (and hence
  // image associated with it) will be with system compositor and 2 frames will
  // be in flight.
  max_images_ = IsSurfaceControl(mode) ? 3 : 1;
  AIMAGE_FORMATS format = mode == Mode::kAImageReaderSecureSurfaceControl
                              ? AIMAGE_FORMAT_PRIVATE
                              : AIMAGE_FORMAT_YUV_420_888;
  AImageReader* reader = nullptr;

  // The usage flag below should be used when the buffer will be read from by
  // the GPU as a texture.
  uint64_t usage = mode == Mode::kAImageReaderSecureSurfaceControl
                       ? AHARDWAREBUFFER_USAGE_PROTECTED_CONTENT
                       : AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE;
  if (IsSurfaceControl(mode))
    usage |= AHARDWAREBUFFER_USAGE_COMPOSER_OVERLAY;

  // Create a new reader for images of the desired size and format.
  media_status_t return_code = loader_.AImageReader_newWithUsage(
      width, height, format, usage, max_images_, &reader);
  if (return_code != AMEDIA_OK) {
    LOG(ERROR) << " Image reader creation failed.";
    if (return_code == AMEDIA_ERROR_INVALID_PARAMETER)
      LOG(ERROR) << "Either reader is null, or one or more of width, height, "
                    "format, maxImages arguments is not supported";
    else
      LOG(ERROR) << "unknown error";
    return;
  }
  DCHECK(reader);
  image_reader_ = reader;

  // Create a new Image Listner.
  listener_ = std::make_unique<AImageReader_ImageListener>();

  // Passing |this| is safe here since we stop listening to new images in the
  // destructor and set the ImageListener to null.
  listener_->context = reinterpret_cast<void*>(this);
  listener_->onImageAvailable = &ImageReaderGLOwner::OnFrameAvailable;

  // Set the onImageAvailable listener of this image reader.
  if (loader_.AImageReader_setImageListener(image_reader_, listener_.get()) !=
      AMEDIA_OK) {
    LOG(ERROR) << " Failed to register AImageReader listener";
    return;
  }
}

ImageReaderGLOwner::~ImageReaderGLOwner() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  // Clear the texture before we return, so that it can OnTextureDestroyed() if
  // it hasn't already.  This will do nothing if it has already been destroyed.
  ClearAbstractTexture();

  DCHECK_EQ(image_refs_.size(), 0u);
}

void ImageReaderGLOwner::OnTextureDestroyed(gles2::AbstractTexture*) {
  // The AbstractTexture is being destroyed.  This can happen if, for example,
  // the video decoder's gl context is lost.  Remember that the platform texture
  // might not be gone; it's possible for the gl decoder (and AbstractTexture)
  // to be destroyed via, e.g., renderer crash, but the platform texture is
  // still shared with some other gl context.

  // This should only be called once.  Note that even during construction,
  // there's a check that |image_reader_| is constructed.  Otherwise, errors
  // during init might cause us to get here without an image reader.
  DCHECK(image_reader_);

  // Now we can stop listening to new images.
  loader_.AImageReader_setImageListener(image_reader_, nullptr);

  // Delete all images before closing the associated image reader.
  for (auto& image_ref : image_refs_)
    loader_.AImage_delete(image_ref.first);

  // Delete the image reader.
  loader_.AImageReader_delete(image_reader_);
  image_reader_ = nullptr;

  // Clean up the ImageRefs which should now be a no-op since there is no valid
  // |image_reader_|.
  image_refs_.clear();
  current_image_ref_.reset();
}

void ImageReaderGLOwner::SetFrameAvailableCallback(
    const base::RepeatingClosure& frame_available_cb) {
  DCHECK(!frame_available_cb_);
  frame_available_cb_ = std::move(frame_available_cb);
}

gl::ScopedJavaSurface ImageReaderGLOwner::CreateJavaSurface() const {
  // If we've already lost the texture, then do nothing.
  if (!image_reader_) {
    DLOG(ERROR) << "Already lost texture / image reader";
    return gl::ScopedJavaSurface::AcquireExternalSurface(nullptr);
  }

  // Get the android native window from the image reader.
  ANativeWindow* window = nullptr;
  if (loader_.AImageReader_getWindow(image_reader_, &window) != AMEDIA_OK) {
    DLOG(ERROR) << "unable to get a window from image reader.";
    return gl::ScopedJavaSurface::AcquireExternalSurface(nullptr);
  }

  // Get the java surface object from the Android native window.
  JNIEnv* env = base::android::AttachCurrentThread();
  jobject j_surface = loader_.ANativeWindow_toSurface(env, window);
  DCHECK(j_surface);

  // Get the scoped java surface that is owned externally.
  return gl::ScopedJavaSurface::AcquireExternalSurface(j_surface);
}

void ImageReaderGLOwner::UpdateTexImage() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);

  // If we've lost the texture, then do nothing.
  if (!texture())
    return;

  DCHECK(image_reader_);

  // Acquire the latest image asynchronously. We must release the current image
  // before acquiring a new one if the ImageReader was initialized with one
  // outstanding image at max.
  if (max_images_ == 1)
    current_image_ref_.reset();

  AImage* image = nullptr;
  int acquire_fence_fd = -1;
  media_status_t return_code = AMEDIA_OK;
  DCHECK_GT(max_images_, static_cast<int32_t>(image_refs_.size()));
  if (max_images_ - image_refs_.size() < 2) {
    // acquireNextImageAsync is required here since as per the spec calling
    // AImageReader_acquireLatestImage with less than two images of margin, that
    // is (maxImages - currentAcquiredImages < 2) will not discard as expected.
    // We always have currentAcquiredImages as 1 since we delete a previous
    // image only after acquiring a new image.
    return_code = loader_.AImageReader_acquireNextImageAsync(
        image_reader_, &image, &acquire_fence_fd);
  } else {
    return_code = loader_.AImageReader_acquireLatestImageAsync(
        image_reader_, &image, &acquire_fence_fd);
  }

  // TODO(http://crbug.com/846050).
  // Need to add some better error handling if below error occurs. Currently we
  // just return if error occurs.
  switch (return_code) {
    case AMEDIA_ERROR_INVALID_PARAMETER:
      LOG(ERROR) << " Image is null";
      base::UmaHistogramSparse("Media.AImageReaderGLOwner.AcquireImageResult",
                               return_code);
      return;
    case AMEDIA_IMGREADER_MAX_IMAGES_ACQUIRED:
      LOG(ERROR)
          << "number of concurrently acquired images has reached the limit";
      base::UmaHistogramSparse("Media.AImageReaderGLOwner.AcquireImageResult",
                               return_code);
      return;
    case AMEDIA_IMGREADER_NO_BUFFER_AVAILABLE:
      LOG(ERROR) << "no buffers currently available in the reader queue";
      base::UmaHistogramSparse("Media.AImageReaderGLOwner.AcquireImageResult",
                               return_code);
      return;
    case AMEDIA_ERROR_UNKNOWN:
      LOG(ERROR) << "method fails for some other reasons";
      base::UmaHistogramSparse("Media.AImageReaderGLOwner.AcquireImageResult",
                               return_code);
      return;
    case AMEDIA_OK:
      // Method call succeeded.
      break;
    default:
      // No other error code should be returned.
      NOTREACHED();
      return;
  }
  base::ScopedFD scoped_acquire_fence_fd(acquire_fence_fd);

  // If there is no new image simply return. At this point previous image will
  // still be bound to the texture.
  if (!image) {
    return;
  }

  // Make the newly acquired image as current image.
  current_image_ref_.emplace(this, image, std::move(scoped_acquire_fence_fd));
}

void ImageReaderGLOwner::EnsureTexImageBound() {
  if (current_image_ref_)
    current_image_ref_->EnsureBound();
}

std::unique_ptr<base::android::ScopedHardwareBufferFenceSync>
ImageReaderGLOwner::GetAHardwareBuffer() {
  if (!current_image_ref_)
    return nullptr;

  AHardwareBuffer* buffer = nullptr;
  loader_.AImage_getHardwareBuffer(current_image_ref_->image(), &buffer);
  if (!buffer)
    return nullptr;

  return std::make_unique<ScopedHardwareBufferImpl>(
      weak_factory_.GetWeakPtr(), current_image_ref_->image(),
      base::android::ScopedHardwareBufferHandle::Create(buffer),
      current_image_ref_->GetReadyFence());
}

gfx::Rect ImageReaderGLOwner::GetCropRect() {
  if (!current_image_ref_)
    return gfx::Rect();

  // Note that to query the crop rectangle, we don't need to wait for the
  // AImage to be ready by checking the associated image ready fence.
  AImageCropRect crop_rect;
  media_status_t return_code =
      loader_.AImage_getCropRect(current_image_ref_->image(), &crop_rect);
  if (return_code != AMEDIA_OK) {
    DLOG(ERROR) << "Error querying crop rectangle from the image : "
                << return_code;
    return gfx::Rect();
  }
  DCHECK_GE(crop_rect.right, crop_rect.left);
  DCHECK_GE(crop_rect.bottom, crop_rect.top);
  return gfx::Rect(crop_rect.left, crop_rect.top,
                   crop_rect.right - crop_rect.left,
                   crop_rect.bottom - crop_rect.top);
}

void ImageReaderGLOwner::RegisterRefOnImage(AImage* image) {
  DCHECK(image_reader_);

  // Add a ref that the caller will release.
  image_refs_[image].count++;
}

void ImageReaderGLOwner::ReleaseRefOnImage(AImage* image,
                                           base::ScopedFD fence_fd) {
  // During cleanup on losing the texture, all images are synchronously released
  // and the |image_reader_| is destroyed.
  if (!image_reader_)
    return;

  auto it = image_refs_.find(image);
  DCHECK(it != image_refs_.end());

  auto& image_ref = it->second;
  DCHECK_GT(image_ref.count, 0u);
  image_ref.count--;
  image_ref.release_fence_fd =
      gl::MergeFDs(std::move(image_ref.release_fence_fd), std::move(fence_fd));

  if (image_ref.count > 0)
    return;

  if (image_ref.release_fence_fd.is_valid()) {
    loader_.AImage_deleteAsync(image,
                               std::move(image_ref.release_fence_fd.release()));
  } else {
    loader_.AImage_delete(image);
  }

  image_refs_.erase(it);
}

void ImageReaderGLOwner::ReleaseBackBuffers() {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  // ReleaseBackBuffers() call is not required with image reader.
}

gl::GLContext* ImageReaderGLOwner::GetContext() const {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  return context_.get();
}

gl::GLSurface* ImageReaderGLOwner::GetSurface() const {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  return surface_.get();
}

// This callback function will be called when there is a new image available
// for in the image reader's queue.
void ImageReaderGLOwner::OnFrameAvailable(void* context, AImageReader* reader) {
  ImageReaderGLOwner* image_reader_ptr =
      reinterpret_cast<ImageReaderGLOwner*>(context);

  // It is safe to run this callback on any thread.
  image_reader_ptr->frame_available_cb_.Run();
}

void ImageReaderGLOwner::GetCodedSizeAndVisibleRect(
    gfx::Size rotated_visible_size,
    gfx::Size* coded_size,
    gfx::Rect* visible_rect) {
  DCHECK(visible_rect);
  DCHECK(coded_size);

  AHardwareBuffer* buffer = nullptr;
  if (current_image_ref_) {
    loader_.AImage_getHardwareBuffer(current_image_ref_->image(), &buffer);
    if (!buffer) {
      DLOG(ERROR) << "Unable to get an AHardwareBuffer from the image";
    }
  }
  if (!buffer) {
    *coded_size = gfx::Size();
    *visible_rect = gfx::Rect();
    return;
  }
  // Get the buffer descriptor. Note that for querying the buffer descriptor, we
  // do not need to wait on the AHB to be ready.
  AHardwareBuffer_Desc desc;
  base::AndroidHardwareBufferCompat::GetInstance().Describe(buffer, &desc);

  *visible_rect = GetCropRect();
  *coded_size = gfx::Size(desc.width, desc.height);
}

ImageReaderGLOwner::ImageRef::ImageRef() = default;
ImageReaderGLOwner::ImageRef::~ImageRef() = default;
ImageReaderGLOwner::ImageRef::ImageRef(ImageRef&& other) = default;
ImageReaderGLOwner::ImageRef& ImageReaderGLOwner::ImageRef::operator=(
    ImageRef&& other) = default;

ImageReaderGLOwner::ScopedCurrentImageRef::ScopedCurrentImageRef(
    ImageReaderGLOwner* texture_owner,
    AImage* image,
    base::ScopedFD ready_fence)
    : texture_owner_(texture_owner),
      image_(image),
      ready_fence_(std::move(ready_fence)) {
  DCHECK(image_);
  texture_owner_->RegisterRefOnImage(image_);
}

ImageReaderGLOwner::ScopedCurrentImageRef::~ScopedCurrentImageRef() {
  base::ScopedFD release_fence;
  // If there is no |image_reader_|, we are in tear down so no fence is
  // required.
  if (image_bound_ && texture_owner_->image_reader_)
    release_fence = CreateEglFenceAndExportFd();
  else
    release_fence = std::move(ready_fence_);
  texture_owner_->ReleaseRefOnImage(image_, std::move(release_fence));
}

base::ScopedFD ImageReaderGLOwner::ScopedCurrentImageRef::GetReadyFence()
    const {
  return base::ScopedFD(HANDLE_EINTR(dup(ready_fence_.get())));
}

void ImageReaderGLOwner::ScopedCurrentImageRef::EnsureBound() {
  if (image_bound_)
    return;

  // Insert an EGL fence and make server wait for image to be available.
  if (!InsertEglFenceAndWait(GetReadyFence()))
    return;

  // Create EGL image from the AImage and bind it to the texture.
  if (!CreateAndBindEglImage(image_, texture_owner_->GetTextureId(),
                             &texture_owner_->loader_))
    return;

  image_bound_ = true;
}

}  // namespace gpu
