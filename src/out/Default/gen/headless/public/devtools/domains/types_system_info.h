// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_SYSTEM_INFO_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_SYSTEM_INFO_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_system_info.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace system_info {

// Describes a single graphics processor (GPU).
class HEADLESS_EXPORT GPUDevice {
 public:
  static std::unique_ptr<GPUDevice> Parse(const base::Value& value, ErrorReporter* errors);
  ~GPUDevice() { }

  // PCI ID of the GPU vendor, if available; 0 otherwise.
  double GetVendorId() const { return vendor_id_; }
  void SetVendorId(double value) { vendor_id_ = value; }

  // PCI ID of the GPU device, if available; 0 otherwise.
  double GetDeviceId() const { return device_id_; }
  void SetDeviceId(double value) { device_id_ = value; }

  // Sub sys ID of the GPU, only available on Windows.
  bool HasSubSysId() const { return !!sub_sys_id_; }
  double GetSubSysId() const { DCHECK(HasSubSysId()); return sub_sys_id_.value(); }
  void SetSubSysId(double value) { sub_sys_id_ = value; }

  // Revision of the GPU, only available on Windows.
  bool HasRevision() const { return !!revision_; }
  double GetRevision() const { DCHECK(HasRevision()); return revision_.value(); }
  void SetRevision(double value) { revision_ = value; }

  // String description of the GPU vendor, if the PCI ID is not available.
  std::string GetVendorString() const { return vendor_string_; }
  void SetVendorString(const std::string& value) { vendor_string_ = value; }

  // String description of the GPU device, if the PCI ID is not available.
  std::string GetDeviceString() const { return device_string_; }
  void SetDeviceString(const std::string& value) { device_string_ = value; }

  // String description of the GPU driver vendor.
  std::string GetDriverVendor() const { return driver_vendor_; }
  void SetDriverVendor(const std::string& value) { driver_vendor_ = value; }

  // String description of the GPU driver version.
  std::string GetDriverVersion() const { return driver_version_; }
  void SetDriverVersion(const std::string& value) { driver_version_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GPUDevice> Clone() const;

  template<int STATE>
  class GPUDeviceBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kVendorIdSet = 1 << 1,
    kDeviceIdSet = 1 << 2,
    kVendorStringSet = 1 << 3,
    kDeviceStringSet = 1 << 4,
    kDriverVendorSet = 1 << 5,
    kDriverVersionSet = 1 << 6,
      kAllRequiredFieldsSet = (kVendorIdSet | kDeviceIdSet | kVendorStringSet | kDeviceStringSet | kDriverVendorSet | kDriverVersionSet | 0)
    };

    GPUDeviceBuilder<STATE | kVendorIdSet>& SetVendorId(double value) {
      static_assert(!(STATE & kVendorIdSet), "property vendorId should not have already been set");
      result_->SetVendorId(value);
      return CastState<kVendorIdSet>();
    }

    GPUDeviceBuilder<STATE | kDeviceIdSet>& SetDeviceId(double value) {
      static_assert(!(STATE & kDeviceIdSet), "property deviceId should not have already been set");
      result_->SetDeviceId(value);
      return CastState<kDeviceIdSet>();
    }

    GPUDeviceBuilder<STATE>& SetSubSysId(double value) {
      result_->SetSubSysId(value);
      return *this;
    }

    GPUDeviceBuilder<STATE>& SetRevision(double value) {
      result_->SetRevision(value);
      return *this;
    }

    GPUDeviceBuilder<STATE | kVendorStringSet>& SetVendorString(const std::string& value) {
      static_assert(!(STATE & kVendorStringSet), "property vendorString should not have already been set");
      result_->SetVendorString(value);
      return CastState<kVendorStringSet>();
    }

    GPUDeviceBuilder<STATE | kDeviceStringSet>& SetDeviceString(const std::string& value) {
      static_assert(!(STATE & kDeviceStringSet), "property deviceString should not have already been set");
      result_->SetDeviceString(value);
      return CastState<kDeviceStringSet>();
    }

    GPUDeviceBuilder<STATE | kDriverVendorSet>& SetDriverVendor(const std::string& value) {
      static_assert(!(STATE & kDriverVendorSet), "property driverVendor should not have already been set");
      result_->SetDriverVendor(value);
      return CastState<kDriverVendorSet>();
    }

    GPUDeviceBuilder<STATE | kDriverVersionSet>& SetDriverVersion(const std::string& value) {
      static_assert(!(STATE & kDriverVersionSet), "property driverVersion should not have already been set");
      result_->SetDriverVersion(value);
      return CastState<kDriverVersionSet>();
    }

    std::unique_ptr<GPUDevice> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GPUDevice;
    GPUDeviceBuilder() : result_(new GPUDevice()) { }

    template<int STEP> GPUDeviceBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GPUDeviceBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GPUDevice> result_;
  };

  static GPUDeviceBuilder<0> Builder() {
    return GPUDeviceBuilder<0>();
  }

 private:
  GPUDevice() { }

  double vendor_id_;
  double device_id_;
  base::Optional<double> sub_sys_id_;
  base::Optional<double> revision_;
  std::string vendor_string_;
  std::string device_string_;
  std::string driver_vendor_;
  std::string driver_version_;

  DISALLOW_COPY_AND_ASSIGN(GPUDevice);
};


// Describes the width and height dimensions of an entity.
class HEADLESS_EXPORT Size {
 public:
  static std::unique_ptr<Size> Parse(const base::Value& value, ErrorReporter* errors);
  ~Size() { }

  // Width in pixels.
  int GetWidth() const { return width_; }
  void SetWidth(int value) { width_ = value; }

  // Height in pixels.
  int GetHeight() const { return height_; }
  void SetHeight(int value) { height_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Size> Clone() const;

  template<int STATE>
  class SizeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kWidthSet = 1 << 1,
    kHeightSet = 1 << 2,
      kAllRequiredFieldsSet = (kWidthSet | kHeightSet | 0)
    };

    SizeBuilder<STATE | kWidthSet>& SetWidth(int value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    SizeBuilder<STATE | kHeightSet>& SetHeight(int value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    std::unique_ptr<Size> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Size;
    SizeBuilder() : result_(new Size()) { }

    template<int STEP> SizeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SizeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Size> result_;
  };

  static SizeBuilder<0> Builder() {
    return SizeBuilder<0>();
  }

 private:
  Size() { }

  int width_;
  int height_;

  DISALLOW_COPY_AND_ASSIGN(Size);
};


// Describes a supported video decoding profile with its associated minimum and
// maximum resolutions.
class HEADLESS_EXPORT VideoDecodeAcceleratorCapability {
 public:
  static std::unique_ptr<VideoDecodeAcceleratorCapability> Parse(const base::Value& value, ErrorReporter* errors);
  ~VideoDecodeAcceleratorCapability() { }

  // Video codec profile that is supported, e.g. VP9 Profile 2.
  std::string GetProfile() const { return profile_; }
  void SetProfile(const std::string& value) { profile_ = value; }

  // Maximum video dimensions in pixels supported for this |profile|.
  const ::headless::system_info::Size* GetMaxResolution() const { return max_resolution_.get(); }
  void SetMaxResolution(std::unique_ptr<::headless::system_info::Size> value) { max_resolution_ = std::move(value); }

  // Minimum video dimensions in pixels supported for this |profile|.
  const ::headless::system_info::Size* GetMinResolution() const { return min_resolution_.get(); }
  void SetMinResolution(std::unique_ptr<::headless::system_info::Size> value) { min_resolution_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VideoDecodeAcceleratorCapability> Clone() const;

  template<int STATE>
  class VideoDecodeAcceleratorCapabilityBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProfileSet = 1 << 1,
    kMaxResolutionSet = 1 << 2,
    kMinResolutionSet = 1 << 3,
      kAllRequiredFieldsSet = (kProfileSet | kMaxResolutionSet | kMinResolutionSet | 0)
    };

    VideoDecodeAcceleratorCapabilityBuilder<STATE | kProfileSet>& SetProfile(const std::string& value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(value);
      return CastState<kProfileSet>();
    }

    VideoDecodeAcceleratorCapabilityBuilder<STATE | kMaxResolutionSet>& SetMaxResolution(std::unique_ptr<::headless::system_info::Size> value) {
      static_assert(!(STATE & kMaxResolutionSet), "property maxResolution should not have already been set");
      result_->SetMaxResolution(std::move(value));
      return CastState<kMaxResolutionSet>();
    }

    VideoDecodeAcceleratorCapabilityBuilder<STATE | kMinResolutionSet>& SetMinResolution(std::unique_ptr<::headless::system_info::Size> value) {
      static_assert(!(STATE & kMinResolutionSet), "property minResolution should not have already been set");
      result_->SetMinResolution(std::move(value));
      return CastState<kMinResolutionSet>();
    }

    std::unique_ptr<VideoDecodeAcceleratorCapability> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VideoDecodeAcceleratorCapability;
    VideoDecodeAcceleratorCapabilityBuilder() : result_(new VideoDecodeAcceleratorCapability()) { }

    template<int STEP> VideoDecodeAcceleratorCapabilityBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VideoDecodeAcceleratorCapabilityBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VideoDecodeAcceleratorCapability> result_;
  };

  static VideoDecodeAcceleratorCapabilityBuilder<0> Builder() {
    return VideoDecodeAcceleratorCapabilityBuilder<0>();
  }

 private:
  VideoDecodeAcceleratorCapability() { }

  std::string profile_;
  std::unique_ptr<::headless::system_info::Size> max_resolution_;
  std::unique_ptr<::headless::system_info::Size> min_resolution_;

  DISALLOW_COPY_AND_ASSIGN(VideoDecodeAcceleratorCapability);
};


// Describes a supported video encoding profile with its associated maximum
// resolution and maximum framerate.
class HEADLESS_EXPORT VideoEncodeAcceleratorCapability {
 public:
  static std::unique_ptr<VideoEncodeAcceleratorCapability> Parse(const base::Value& value, ErrorReporter* errors);
  ~VideoEncodeAcceleratorCapability() { }

  // Video codec profile that is supported, e.g H264 Main.
  std::string GetProfile() const { return profile_; }
  void SetProfile(const std::string& value) { profile_ = value; }

  // Maximum video dimensions in pixels supported for this |profile|.
  const ::headless::system_info::Size* GetMaxResolution() const { return max_resolution_.get(); }
  void SetMaxResolution(std::unique_ptr<::headless::system_info::Size> value) { max_resolution_ = std::move(value); }

  // Maximum encoding framerate in frames per second supported for this
  // |profile|, as fraction's numerator and denominator, e.g. 24/1 fps,
  // 24000/1001 fps, etc.
  int GetMaxFramerateNumerator() const { return max_framerate_numerator_; }
  void SetMaxFramerateNumerator(int value) { max_framerate_numerator_ = value; }

  int GetMaxFramerateDenominator() const { return max_framerate_denominator_; }
  void SetMaxFramerateDenominator(int value) { max_framerate_denominator_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VideoEncodeAcceleratorCapability> Clone() const;

  template<int STATE>
  class VideoEncodeAcceleratorCapabilityBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProfileSet = 1 << 1,
    kMaxResolutionSet = 1 << 2,
    kMaxFramerateNumeratorSet = 1 << 3,
    kMaxFramerateDenominatorSet = 1 << 4,
      kAllRequiredFieldsSet = (kProfileSet | kMaxResolutionSet | kMaxFramerateNumeratorSet | kMaxFramerateDenominatorSet | 0)
    };

    VideoEncodeAcceleratorCapabilityBuilder<STATE | kProfileSet>& SetProfile(const std::string& value) {
      static_assert(!(STATE & kProfileSet), "property profile should not have already been set");
      result_->SetProfile(value);
      return CastState<kProfileSet>();
    }

    VideoEncodeAcceleratorCapabilityBuilder<STATE | kMaxResolutionSet>& SetMaxResolution(std::unique_ptr<::headless::system_info::Size> value) {
      static_assert(!(STATE & kMaxResolutionSet), "property maxResolution should not have already been set");
      result_->SetMaxResolution(std::move(value));
      return CastState<kMaxResolutionSet>();
    }

    VideoEncodeAcceleratorCapabilityBuilder<STATE | kMaxFramerateNumeratorSet>& SetMaxFramerateNumerator(int value) {
      static_assert(!(STATE & kMaxFramerateNumeratorSet), "property maxFramerateNumerator should not have already been set");
      result_->SetMaxFramerateNumerator(value);
      return CastState<kMaxFramerateNumeratorSet>();
    }

    VideoEncodeAcceleratorCapabilityBuilder<STATE | kMaxFramerateDenominatorSet>& SetMaxFramerateDenominator(int value) {
      static_assert(!(STATE & kMaxFramerateDenominatorSet), "property maxFramerateDenominator should not have already been set");
      result_->SetMaxFramerateDenominator(value);
      return CastState<kMaxFramerateDenominatorSet>();
    }

    std::unique_ptr<VideoEncodeAcceleratorCapability> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VideoEncodeAcceleratorCapability;
    VideoEncodeAcceleratorCapabilityBuilder() : result_(new VideoEncodeAcceleratorCapability()) { }

    template<int STEP> VideoEncodeAcceleratorCapabilityBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VideoEncodeAcceleratorCapabilityBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VideoEncodeAcceleratorCapability> result_;
  };

  static VideoEncodeAcceleratorCapabilityBuilder<0> Builder() {
    return VideoEncodeAcceleratorCapabilityBuilder<0>();
  }

 private:
  VideoEncodeAcceleratorCapability() { }

  std::string profile_;
  std::unique_ptr<::headless::system_info::Size> max_resolution_;
  int max_framerate_numerator_;
  int max_framerate_denominator_;

  DISALLOW_COPY_AND_ASSIGN(VideoEncodeAcceleratorCapability);
};


// Describes a supported image decoding profile with its associated minimum and
// maximum resolutions and subsampling.
class HEADLESS_EXPORT ImageDecodeAcceleratorCapability {
 public:
  static std::unique_ptr<ImageDecodeAcceleratorCapability> Parse(const base::Value& value, ErrorReporter* errors);
  ~ImageDecodeAcceleratorCapability() { }

  // Image coded, e.g. Jpeg.
  ::headless::system_info::ImageType GetImageType() const { return image_type_; }
  void SetImageType(::headless::system_info::ImageType value) { image_type_ = value; }

  // Maximum supported dimensions of the image in pixels.
  const ::headless::system_info::Size* GetMaxDimensions() const { return max_dimensions_.get(); }
  void SetMaxDimensions(std::unique_ptr<::headless::system_info::Size> value) { max_dimensions_ = std::move(value); }

  // Minimum supported dimensions of the image in pixels.
  const ::headless::system_info::Size* GetMinDimensions() const { return min_dimensions_.get(); }
  void SetMinDimensions(std::unique_ptr<::headless::system_info::Size> value) { min_dimensions_ = std::move(value); }

  // Optional array of supported subsampling formats, e.g. 4:2:0, if known.
  const std::vector<::headless::system_info::SubsamplingFormat>* GetSubsamplings() const { return &subsamplings_; }
  void SetSubsamplings(std::vector<::headless::system_info::SubsamplingFormat> value) { subsamplings_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ImageDecodeAcceleratorCapability> Clone() const;

  template<int STATE>
  class ImageDecodeAcceleratorCapabilityBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kImageTypeSet = 1 << 1,
    kMaxDimensionsSet = 1 << 2,
    kMinDimensionsSet = 1 << 3,
    kSubsamplingsSet = 1 << 4,
      kAllRequiredFieldsSet = (kImageTypeSet | kMaxDimensionsSet | kMinDimensionsSet | kSubsamplingsSet | 0)
    };

    ImageDecodeAcceleratorCapabilityBuilder<STATE | kImageTypeSet>& SetImageType(::headless::system_info::ImageType value) {
      static_assert(!(STATE & kImageTypeSet), "property imageType should not have already been set");
      result_->SetImageType(value);
      return CastState<kImageTypeSet>();
    }

    ImageDecodeAcceleratorCapabilityBuilder<STATE | kMaxDimensionsSet>& SetMaxDimensions(std::unique_ptr<::headless::system_info::Size> value) {
      static_assert(!(STATE & kMaxDimensionsSet), "property maxDimensions should not have already been set");
      result_->SetMaxDimensions(std::move(value));
      return CastState<kMaxDimensionsSet>();
    }

    ImageDecodeAcceleratorCapabilityBuilder<STATE | kMinDimensionsSet>& SetMinDimensions(std::unique_ptr<::headless::system_info::Size> value) {
      static_assert(!(STATE & kMinDimensionsSet), "property minDimensions should not have already been set");
      result_->SetMinDimensions(std::move(value));
      return CastState<kMinDimensionsSet>();
    }

    ImageDecodeAcceleratorCapabilityBuilder<STATE | kSubsamplingsSet>& SetSubsamplings(std::vector<::headless::system_info::SubsamplingFormat> value) {
      static_assert(!(STATE & kSubsamplingsSet), "property subsamplings should not have already been set");
      result_->SetSubsamplings(std::move(value));
      return CastState<kSubsamplingsSet>();
    }

    std::unique_ptr<ImageDecodeAcceleratorCapability> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ImageDecodeAcceleratorCapability;
    ImageDecodeAcceleratorCapabilityBuilder() : result_(new ImageDecodeAcceleratorCapability()) { }

    template<int STEP> ImageDecodeAcceleratorCapabilityBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ImageDecodeAcceleratorCapabilityBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ImageDecodeAcceleratorCapability> result_;
  };

  static ImageDecodeAcceleratorCapabilityBuilder<0> Builder() {
    return ImageDecodeAcceleratorCapabilityBuilder<0>();
  }

 private:
  ImageDecodeAcceleratorCapability() { }

  ::headless::system_info::ImageType image_type_;
  std::unique_ptr<::headless::system_info::Size> max_dimensions_;
  std::unique_ptr<::headless::system_info::Size> min_dimensions_;
  std::vector<::headless::system_info::SubsamplingFormat> subsamplings_;

  DISALLOW_COPY_AND_ASSIGN(ImageDecodeAcceleratorCapability);
};


// Provides information about the GPU(s) on the system.
class HEADLESS_EXPORT GPUInfo {
 public:
  static std::unique_ptr<GPUInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~GPUInfo() { }

  // The graphics devices on the system. Element 0 is the primary GPU.
  const std::vector<std::unique_ptr<::headless::system_info::GPUDevice>>* GetDevices() const { return &devices_; }
  void SetDevices(std::vector<std::unique_ptr<::headless::system_info::GPUDevice>> value) { devices_ = std::move(value); }

  // An optional dictionary of additional GPU related attributes.
  bool HasAuxAttributes() const { return !!aux_attributes_; }
  const base::Value* GetAuxAttributes() const { DCHECK(HasAuxAttributes()); return aux_attributes_.value().get(); }
  void SetAuxAttributes(std::unique_ptr<base::Value> value) { aux_attributes_ = std::move(value); }

  // An optional dictionary of graphics features and their status.
  bool HasFeatureStatus() const { return !!feature_status_; }
  const base::Value* GetFeatureStatus() const { DCHECK(HasFeatureStatus()); return feature_status_.value().get(); }
  void SetFeatureStatus(std::unique_ptr<base::Value> value) { feature_status_ = std::move(value); }

  // An optional array of GPU driver bug workarounds.
  const std::vector<std::string>* GetDriverBugWorkarounds() const { return &driver_bug_workarounds_; }
  void SetDriverBugWorkarounds(std::vector<std::string> value) { driver_bug_workarounds_ = std::move(value); }

  // Supported accelerated video decoding capabilities.
  const std::vector<std::unique_ptr<::headless::system_info::VideoDecodeAcceleratorCapability>>* GetVideoDecoding() const { return &video_decoding_; }
  void SetVideoDecoding(std::vector<std::unique_ptr<::headless::system_info::VideoDecodeAcceleratorCapability>> value) { video_decoding_ = std::move(value); }

  // Supported accelerated video encoding capabilities.
  const std::vector<std::unique_ptr<::headless::system_info::VideoEncodeAcceleratorCapability>>* GetVideoEncoding() const { return &video_encoding_; }
  void SetVideoEncoding(std::vector<std::unique_ptr<::headless::system_info::VideoEncodeAcceleratorCapability>> value) { video_encoding_ = std::move(value); }

  // Supported accelerated image decoding capabilities.
  const std::vector<std::unique_ptr<::headless::system_info::ImageDecodeAcceleratorCapability>>* GetImageDecoding() const { return &image_decoding_; }
  void SetImageDecoding(std::vector<std::unique_ptr<::headless::system_info::ImageDecodeAcceleratorCapability>> value) { image_decoding_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GPUInfo> Clone() const;

  template<int STATE>
  class GPUInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDevicesSet = 1 << 1,
    kDriverBugWorkaroundsSet = 1 << 2,
    kVideoDecodingSet = 1 << 3,
    kVideoEncodingSet = 1 << 4,
    kImageDecodingSet = 1 << 5,
      kAllRequiredFieldsSet = (kDevicesSet | kDriverBugWorkaroundsSet | kVideoDecodingSet | kVideoEncodingSet | kImageDecodingSet | 0)
    };

    GPUInfoBuilder<STATE | kDevicesSet>& SetDevices(std::vector<std::unique_ptr<::headless::system_info::GPUDevice>> value) {
      static_assert(!(STATE & kDevicesSet), "property devices should not have already been set");
      result_->SetDevices(std::move(value));
      return CastState<kDevicesSet>();
    }

    GPUInfoBuilder<STATE>& SetAuxAttributes(std::unique_ptr<base::Value> value) {
      result_->SetAuxAttributes(std::move(value));
      return *this;
    }

    GPUInfoBuilder<STATE>& SetFeatureStatus(std::unique_ptr<base::Value> value) {
      result_->SetFeatureStatus(std::move(value));
      return *this;
    }

    GPUInfoBuilder<STATE | kDriverBugWorkaroundsSet>& SetDriverBugWorkarounds(std::vector<std::string> value) {
      static_assert(!(STATE & kDriverBugWorkaroundsSet), "property driverBugWorkarounds should not have already been set");
      result_->SetDriverBugWorkarounds(std::move(value));
      return CastState<kDriverBugWorkaroundsSet>();
    }

    GPUInfoBuilder<STATE | kVideoDecodingSet>& SetVideoDecoding(std::vector<std::unique_ptr<::headless::system_info::VideoDecodeAcceleratorCapability>> value) {
      static_assert(!(STATE & kVideoDecodingSet), "property videoDecoding should not have already been set");
      result_->SetVideoDecoding(std::move(value));
      return CastState<kVideoDecodingSet>();
    }

    GPUInfoBuilder<STATE | kVideoEncodingSet>& SetVideoEncoding(std::vector<std::unique_ptr<::headless::system_info::VideoEncodeAcceleratorCapability>> value) {
      static_assert(!(STATE & kVideoEncodingSet), "property videoEncoding should not have already been set");
      result_->SetVideoEncoding(std::move(value));
      return CastState<kVideoEncodingSet>();
    }

    GPUInfoBuilder<STATE | kImageDecodingSet>& SetImageDecoding(std::vector<std::unique_ptr<::headless::system_info::ImageDecodeAcceleratorCapability>> value) {
      static_assert(!(STATE & kImageDecodingSet), "property imageDecoding should not have already been set");
      result_->SetImageDecoding(std::move(value));
      return CastState<kImageDecodingSet>();
    }

    std::unique_ptr<GPUInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GPUInfo;
    GPUInfoBuilder() : result_(new GPUInfo()) { }

    template<int STEP> GPUInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GPUInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GPUInfo> result_;
  };

  static GPUInfoBuilder<0> Builder() {
    return GPUInfoBuilder<0>();
  }

 private:
  GPUInfo() { }

  std::vector<std::unique_ptr<::headless::system_info::GPUDevice>> devices_;
  base::Optional<std::unique_ptr<base::Value>> aux_attributes_;
  base::Optional<std::unique_ptr<base::Value>> feature_status_;
  std::vector<std::string> driver_bug_workarounds_;
  std::vector<std::unique_ptr<::headless::system_info::VideoDecodeAcceleratorCapability>> video_decoding_;
  std::vector<std::unique_ptr<::headless::system_info::VideoEncodeAcceleratorCapability>> video_encoding_;
  std::vector<std::unique_ptr<::headless::system_info::ImageDecodeAcceleratorCapability>> image_decoding_;

  DISALLOW_COPY_AND_ASSIGN(GPUInfo);
};


// Represents process info.
class HEADLESS_EXPORT ProcessInfo {
 public:
  static std::unique_ptr<ProcessInfo> Parse(const base::Value& value, ErrorReporter* errors);
  ~ProcessInfo() { }

  // Specifies process type.
  std::string GetType() const { return type_; }
  void SetType(const std::string& value) { type_ = value; }

  // Specifies process id.
  int GetId() const { return id_; }
  void SetId(int value) { id_ = value; }

  // Specifies cumulative CPU usage in seconds across all threads of the
  // process since the process start.
  double GetCpuTime() const { return cpu_time_; }
  void SetCpuTime(double value) { cpu_time_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ProcessInfo> Clone() const;

  template<int STATE>
  class ProcessInfoBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTypeSet = 1 << 1,
    kIdSet = 1 << 2,
    kCpuTimeSet = 1 << 3,
      kAllRequiredFieldsSet = (kTypeSet | kIdSet | kCpuTimeSet | 0)
    };

    ProcessInfoBuilder<STATE | kTypeSet>& SetType(const std::string& value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    ProcessInfoBuilder<STATE | kIdSet>& SetId(int value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    ProcessInfoBuilder<STATE | kCpuTimeSet>& SetCpuTime(double value) {
      static_assert(!(STATE & kCpuTimeSet), "property cpuTime should not have already been set");
      result_->SetCpuTime(value);
      return CastState<kCpuTimeSet>();
    }

    std::unique_ptr<ProcessInfo> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ProcessInfo;
    ProcessInfoBuilder() : result_(new ProcessInfo()) { }

    template<int STEP> ProcessInfoBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ProcessInfoBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ProcessInfo> result_;
  };

  static ProcessInfoBuilder<0> Builder() {
    return ProcessInfoBuilder<0>();
  }

 private:
  ProcessInfo() { }

  std::string type_;
  int id_;
  double cpu_time_;

  DISALLOW_COPY_AND_ASSIGN(ProcessInfo);
};


// Parameters for the GetInfo command.
class HEADLESS_EXPORT GetInfoParams {
 public:
  static std::unique_ptr<GetInfoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetInfoParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetInfoParams> Clone() const;

  template<int STATE>
  class GetInfoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetInfoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetInfoParams;
    GetInfoParamsBuilder() : result_(new GetInfoParams()) { }

    template<int STEP> GetInfoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetInfoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetInfoParams> result_;
  };

  static GetInfoParamsBuilder<0> Builder() {
    return GetInfoParamsBuilder<0>();
  }

 private:
  GetInfoParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetInfoParams);
};


// Result for the GetInfo command.
class HEADLESS_EXPORT GetInfoResult {
 public:
  static std::unique_ptr<GetInfoResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetInfoResult() { }

  // Information about the GPUs on the system.
  const ::headless::system_info::GPUInfo* GetGpu() const { return gpu_.get(); }
  void SetGpu(std::unique_ptr<::headless::system_info::GPUInfo> value) { gpu_ = std::move(value); }

  // A platform-dependent description of the model of the machine. On Mac OS, this is, for
  // example, 'MacBookPro'. Will be the empty string if not supported.
  std::string GetModelName() const { return model_name_; }
  void SetModelName(const std::string& value) { model_name_ = value; }

  // A platform-dependent description of the version of the machine. On Mac OS, this is, for
  // example, '10.1'. Will be the empty string if not supported.
  std::string GetModelVersion() const { return model_version_; }
  void SetModelVersion(const std::string& value) { model_version_ = value; }

  // The command line string used to launch the browser. Will be the empty string if not
  // supported.
  std::string GetCommandLine() const { return command_line_; }
  void SetCommandLine(const std::string& value) { command_line_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetInfoResult> Clone() const;

  template<int STATE>
  class GetInfoResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kGpuSet = 1 << 1,
    kModelNameSet = 1 << 2,
    kModelVersionSet = 1 << 3,
    kCommandLineSet = 1 << 4,
      kAllRequiredFieldsSet = (kGpuSet | kModelNameSet | kModelVersionSet | kCommandLineSet | 0)
    };

    GetInfoResultBuilder<STATE | kGpuSet>& SetGpu(std::unique_ptr<::headless::system_info::GPUInfo> value) {
      static_assert(!(STATE & kGpuSet), "property gpu should not have already been set");
      result_->SetGpu(std::move(value));
      return CastState<kGpuSet>();
    }

    GetInfoResultBuilder<STATE | kModelNameSet>& SetModelName(const std::string& value) {
      static_assert(!(STATE & kModelNameSet), "property modelName should not have already been set");
      result_->SetModelName(value);
      return CastState<kModelNameSet>();
    }

    GetInfoResultBuilder<STATE | kModelVersionSet>& SetModelVersion(const std::string& value) {
      static_assert(!(STATE & kModelVersionSet), "property modelVersion should not have already been set");
      result_->SetModelVersion(value);
      return CastState<kModelVersionSet>();
    }

    GetInfoResultBuilder<STATE | kCommandLineSet>& SetCommandLine(const std::string& value) {
      static_assert(!(STATE & kCommandLineSet), "property commandLine should not have already been set");
      result_->SetCommandLine(value);
      return CastState<kCommandLineSet>();
    }

    std::unique_ptr<GetInfoResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetInfoResult;
    GetInfoResultBuilder() : result_(new GetInfoResult()) { }

    template<int STEP> GetInfoResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetInfoResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetInfoResult> result_;
  };

  static GetInfoResultBuilder<0> Builder() {
    return GetInfoResultBuilder<0>();
  }

 private:
  GetInfoResult() { }

  std::unique_ptr<::headless::system_info::GPUInfo> gpu_;
  std::string model_name_;
  std::string model_version_;
  std::string command_line_;

  DISALLOW_COPY_AND_ASSIGN(GetInfoResult);
};


// Parameters for the GetProcessInfo command.
class HEADLESS_EXPORT GetProcessInfoParams {
 public:
  static std::unique_ptr<GetProcessInfoParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetProcessInfoParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetProcessInfoParams> Clone() const;

  template<int STATE>
  class GetProcessInfoParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetProcessInfoParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetProcessInfoParams;
    GetProcessInfoParamsBuilder() : result_(new GetProcessInfoParams()) { }

    template<int STEP> GetProcessInfoParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetProcessInfoParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetProcessInfoParams> result_;
  };

  static GetProcessInfoParamsBuilder<0> Builder() {
    return GetProcessInfoParamsBuilder<0>();
  }

 private:
  GetProcessInfoParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetProcessInfoParams);
};


// Result for the GetProcessInfo command.
class HEADLESS_EXPORT GetProcessInfoResult {
 public:
  static std::unique_ptr<GetProcessInfoResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetProcessInfoResult() { }

  // An array of process info blocks.
  const std::vector<std::unique_ptr<::headless::system_info::ProcessInfo>>* GetProcessInfo() const { return &process_info_; }
  void SetProcessInfo(std::vector<std::unique_ptr<::headless::system_info::ProcessInfo>> value) { process_info_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetProcessInfoResult> Clone() const;

  template<int STATE>
  class GetProcessInfoResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kProcessInfoSet = 1 << 1,
      kAllRequiredFieldsSet = (kProcessInfoSet | 0)
    };

    GetProcessInfoResultBuilder<STATE | kProcessInfoSet>& SetProcessInfo(std::vector<std::unique_ptr<::headless::system_info::ProcessInfo>> value) {
      static_assert(!(STATE & kProcessInfoSet), "property processInfo should not have already been set");
      result_->SetProcessInfo(std::move(value));
      return CastState<kProcessInfoSet>();
    }

    std::unique_ptr<GetProcessInfoResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetProcessInfoResult;
    GetProcessInfoResultBuilder() : result_(new GetProcessInfoResult()) { }

    template<int STEP> GetProcessInfoResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetProcessInfoResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetProcessInfoResult> result_;
  };

  static GetProcessInfoResultBuilder<0> Builder() {
    return GetProcessInfoResultBuilder<0>();
  }

 private:
  GetProcessInfoResult() { }

  std::vector<std::unique_ptr<::headless::system_info::ProcessInfo>> process_info_;

  DISALLOW_COPY_AND_ASSIGN(GetProcessInfoResult);
};


}  // namespace system_info

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_SYSTEM_INFO_H_
