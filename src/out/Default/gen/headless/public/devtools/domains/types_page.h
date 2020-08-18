// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PAGE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PAGE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace page {

// Information about the Frame on the page.
class HEADLESS_EXPORT Frame {
 public:
  static std::unique_ptr<Frame> Parse(const base::Value& value, ErrorReporter* errors);
  ~Frame() { }

  // Frame unique identifier.
  std::string GetId() const { return id_; }
  void SetId(const std::string& value) { id_ = value; }

  // Parent frame identifier.
  bool HasParentId() const { return !!parent_id_; }
  std::string GetParentId() const { DCHECK(HasParentId()); return parent_id_.value(); }
  void SetParentId(const std::string& value) { parent_id_ = value; }

  // Identifier of the loader associated with this frame.
  std::string GetLoaderId() const { return loader_id_; }
  void SetLoaderId(const std::string& value) { loader_id_ = value; }

  // Frame's name as specified in the tag.
  bool HasName() const { return !!name_; }
  std::string GetName() const { DCHECK(HasName()); return name_.value(); }
  void SetName(const std::string& value) { name_ = value; }

  // Frame document's URL without fragment.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Frame document's URL fragment including the '#'.
  bool HasUrlFragment() const { return !!url_fragment_; }
  std::string GetUrlFragment() const { DCHECK(HasUrlFragment()); return url_fragment_.value(); }
  void SetUrlFragment(const std::string& value) { url_fragment_ = value; }

  // Frame document's security origin.
  std::string GetSecurityOrigin() const { return security_origin_; }
  void SetSecurityOrigin(const std::string& value) { security_origin_ = value; }

  // Frame document's mimeType as determined by the browser.
  std::string GetMimeType() const { return mime_type_; }
  void SetMimeType(const std::string& value) { mime_type_ = value; }

  // If the frame failed to load, this contains the URL that could not be loaded. Note that unlike url above, this URL may contain a fragment.
  bool HasUnreachableUrl() const { return !!unreachable_url_; }
  std::string GetUnreachableUrl() const { DCHECK(HasUnreachableUrl()); return unreachable_url_.value(); }
  void SetUnreachableUrl(const std::string& value) { unreachable_url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Frame> Clone() const;

  template<int STATE>
  class FrameBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kLoaderIdSet = 1 << 2,
    kUrlSet = 1 << 3,
    kSecurityOriginSet = 1 << 4,
    kMimeTypeSet = 1 << 5,
      kAllRequiredFieldsSet = (kIdSet | kLoaderIdSet | kUrlSet | kSecurityOriginSet | kMimeTypeSet | 0)
    };

    FrameBuilder<STATE | kIdSet>& SetId(const std::string& value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    FrameBuilder<STATE>& SetParentId(const std::string& value) {
      result_->SetParentId(value);
      return *this;
    }

    FrameBuilder<STATE | kLoaderIdSet>& SetLoaderId(const std::string& value) {
      static_assert(!(STATE & kLoaderIdSet), "property loaderId should not have already been set");
      result_->SetLoaderId(value);
      return CastState<kLoaderIdSet>();
    }

    FrameBuilder<STATE>& SetName(const std::string& value) {
      result_->SetName(value);
      return *this;
    }

    FrameBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    FrameBuilder<STATE>& SetUrlFragment(const std::string& value) {
      result_->SetUrlFragment(value);
      return *this;
    }

    FrameBuilder<STATE | kSecurityOriginSet>& SetSecurityOrigin(const std::string& value) {
      static_assert(!(STATE & kSecurityOriginSet), "property securityOrigin should not have already been set");
      result_->SetSecurityOrigin(value);
      return CastState<kSecurityOriginSet>();
    }

    FrameBuilder<STATE | kMimeTypeSet>& SetMimeType(const std::string& value) {
      static_assert(!(STATE & kMimeTypeSet), "property mimeType should not have already been set");
      result_->SetMimeType(value);
      return CastState<kMimeTypeSet>();
    }

    FrameBuilder<STATE>& SetUnreachableUrl(const std::string& value) {
      result_->SetUnreachableUrl(value);
      return *this;
    }

    std::unique_ptr<Frame> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Frame;
    FrameBuilder() : result_(new Frame()) { }

    template<int STEP> FrameBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Frame> result_;
  };

  static FrameBuilder<0> Builder() {
    return FrameBuilder<0>();
  }

 private:
  Frame() { }

  std::string id_;
  base::Optional<std::string> parent_id_;
  std::string loader_id_;
  base::Optional<std::string> name_;
  std::string url_;
  base::Optional<std::string> url_fragment_;
  std::string security_origin_;
  std::string mime_type_;
  base::Optional<std::string> unreachable_url_;

  DISALLOW_COPY_AND_ASSIGN(Frame);
};


// Information about the Resource on the page.
class HEADLESS_EXPORT FrameResource {
 public:
  static std::unique_ptr<FrameResource> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameResource() { }

  // Resource URL.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Type of this resource.
  ::headless::network::ResourceType GetType() const { return type_; }
  void SetType(::headless::network::ResourceType value) { type_ = value; }

  // Resource mimeType as determined by the browser.
  std::string GetMimeType() const { return mime_type_; }
  void SetMimeType(const std::string& value) { mime_type_ = value; }

  // last-modified timestamp as reported by server.
  bool HasLastModified() const { return !!last_modified_; }
  double GetLastModified() const { DCHECK(HasLastModified()); return last_modified_.value(); }
  void SetLastModified(double value) { last_modified_ = value; }

  // Resource content size.
  bool HasContentSize() const { return !!content_size_; }
  double GetContentSize() const { DCHECK(HasContentSize()); return content_size_.value(); }
  void SetContentSize(double value) { content_size_ = value; }

  // True if the resource failed to load.
  bool HasFailed() const { return !!failed_; }
  bool GetFailed() const { DCHECK(HasFailed()); return failed_.value(); }
  void SetFailed(bool value) { failed_ = value; }

  // True if the resource was canceled during loading.
  bool HasCanceled() const { return !!canceled_; }
  bool GetCanceled() const { DCHECK(HasCanceled()); return canceled_.value(); }
  void SetCanceled(bool value) { canceled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameResource> Clone() const;

  template<int STATE>
  class FrameResourceBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kTypeSet = 1 << 2,
    kMimeTypeSet = 1 << 3,
      kAllRequiredFieldsSet = (kUrlSet | kTypeSet | kMimeTypeSet | 0)
    };

    FrameResourceBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    FrameResourceBuilder<STATE | kTypeSet>& SetType(::headless::network::ResourceType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    FrameResourceBuilder<STATE | kMimeTypeSet>& SetMimeType(const std::string& value) {
      static_assert(!(STATE & kMimeTypeSet), "property mimeType should not have already been set");
      result_->SetMimeType(value);
      return CastState<kMimeTypeSet>();
    }

    FrameResourceBuilder<STATE>& SetLastModified(double value) {
      result_->SetLastModified(value);
      return *this;
    }

    FrameResourceBuilder<STATE>& SetContentSize(double value) {
      result_->SetContentSize(value);
      return *this;
    }

    FrameResourceBuilder<STATE>& SetFailed(bool value) {
      result_->SetFailed(value);
      return *this;
    }

    FrameResourceBuilder<STATE>& SetCanceled(bool value) {
      result_->SetCanceled(value);
      return *this;
    }

    std::unique_ptr<FrameResource> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameResource;
    FrameResourceBuilder() : result_(new FrameResource()) { }

    template<int STEP> FrameResourceBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameResourceBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameResource> result_;
  };

  static FrameResourceBuilder<0> Builder() {
    return FrameResourceBuilder<0>();
  }

 private:
  FrameResource() { }

  std::string url_;
  ::headless::network::ResourceType type_;
  std::string mime_type_;
  base::Optional<double> last_modified_;
  base::Optional<double> content_size_;
  base::Optional<bool> failed_;
  base::Optional<bool> canceled_;

  DISALLOW_COPY_AND_ASSIGN(FrameResource);
};


// Information about the Frame hierarchy along with their cached resources.
class HEADLESS_EXPORT FrameResourceTree {
 public:
  static std::unique_ptr<FrameResourceTree> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameResourceTree() { }

  // Frame information for this tree item.
  const ::headless::page::Frame* GetFrame() const { return frame_.get(); }
  void SetFrame(std::unique_ptr<::headless::page::Frame> value) { frame_ = std::move(value); }

  // Child frames.
  bool HasChildFrames() const { return !!child_frames_; }
  const std::vector<std::unique_ptr<::headless::page::FrameResourceTree>>* GetChildFrames() const { DCHECK(HasChildFrames()); return &child_frames_.value(); }
  void SetChildFrames(std::vector<std::unique_ptr<::headless::page::FrameResourceTree>> value) { child_frames_ = std::move(value); }

  // Information about frame resources.
  const std::vector<std::unique_ptr<::headless::page::FrameResource>>* GetResources() const { return &resources_; }
  void SetResources(std::vector<std::unique_ptr<::headless::page::FrameResource>> value) { resources_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameResourceTree> Clone() const;

  template<int STATE>
  class FrameResourceTreeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameSet = 1 << 1,
    kResourcesSet = 1 << 2,
      kAllRequiredFieldsSet = (kFrameSet | kResourcesSet | 0)
    };

    FrameResourceTreeBuilder<STATE | kFrameSet>& SetFrame(std::unique_ptr<::headless::page::Frame> value) {
      static_assert(!(STATE & kFrameSet), "property frame should not have already been set");
      result_->SetFrame(std::move(value));
      return CastState<kFrameSet>();
    }

    FrameResourceTreeBuilder<STATE>& SetChildFrames(std::vector<std::unique_ptr<::headless::page::FrameResourceTree>> value) {
      result_->SetChildFrames(std::move(value));
      return *this;
    }

    FrameResourceTreeBuilder<STATE | kResourcesSet>& SetResources(std::vector<std::unique_ptr<::headless::page::FrameResource>> value) {
      static_assert(!(STATE & kResourcesSet), "property resources should not have already been set");
      result_->SetResources(std::move(value));
      return CastState<kResourcesSet>();
    }

    std::unique_ptr<FrameResourceTree> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameResourceTree;
    FrameResourceTreeBuilder() : result_(new FrameResourceTree()) { }

    template<int STEP> FrameResourceTreeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameResourceTreeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameResourceTree> result_;
  };

  static FrameResourceTreeBuilder<0> Builder() {
    return FrameResourceTreeBuilder<0>();
  }

 private:
  FrameResourceTree() { }

  std::unique_ptr<::headless::page::Frame> frame_;
  base::Optional<std::vector<std::unique_ptr<::headless::page::FrameResourceTree>>> child_frames_;
  std::vector<std::unique_ptr<::headless::page::FrameResource>> resources_;

  DISALLOW_COPY_AND_ASSIGN(FrameResourceTree);
};


// Information about the Frame hierarchy.
class HEADLESS_EXPORT FrameTree {
 public:
  static std::unique_ptr<FrameTree> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameTree() { }

  // Frame information for this tree item.
  const ::headless::page::Frame* GetFrame() const { return frame_.get(); }
  void SetFrame(std::unique_ptr<::headless::page::Frame> value) { frame_ = std::move(value); }

  // Child frames.
  bool HasChildFrames() const { return !!child_frames_; }
  const std::vector<std::unique_ptr<::headless::page::FrameTree>>* GetChildFrames() const { DCHECK(HasChildFrames()); return &child_frames_.value(); }
  void SetChildFrames(std::vector<std::unique_ptr<::headless::page::FrameTree>> value) { child_frames_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameTree> Clone() const;

  template<int STATE>
  class FrameTreeBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameSet | 0)
    };

    FrameTreeBuilder<STATE | kFrameSet>& SetFrame(std::unique_ptr<::headless::page::Frame> value) {
      static_assert(!(STATE & kFrameSet), "property frame should not have already been set");
      result_->SetFrame(std::move(value));
      return CastState<kFrameSet>();
    }

    FrameTreeBuilder<STATE>& SetChildFrames(std::vector<std::unique_ptr<::headless::page::FrameTree>> value) {
      result_->SetChildFrames(std::move(value));
      return *this;
    }

    std::unique_ptr<FrameTree> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameTree;
    FrameTreeBuilder() : result_(new FrameTree()) { }

    template<int STEP> FrameTreeBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameTreeBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameTree> result_;
  };

  static FrameTreeBuilder<0> Builder() {
    return FrameTreeBuilder<0>();
  }

 private:
  FrameTree() { }

  std::unique_ptr<::headless::page::Frame> frame_;
  base::Optional<std::vector<std::unique_ptr<::headless::page::FrameTree>>> child_frames_;

  DISALLOW_COPY_AND_ASSIGN(FrameTree);
};


// Navigation history entry.
class HEADLESS_EXPORT NavigationEntry {
 public:
  static std::unique_ptr<NavigationEntry> Parse(const base::Value& value, ErrorReporter* errors);
  ~NavigationEntry() { }

  // Unique id of the navigation history entry.
  int GetId() const { return id_; }
  void SetId(int value) { id_ = value; }

  // URL of the navigation history entry.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // URL that the user typed in the url bar.
  std::string GetUserTypedURL() const { return user_typedurl_; }
  void SetUserTypedURL(const std::string& value) { user_typedurl_ = value; }

  // Title of the navigation history entry.
  std::string GetTitle() const { return title_; }
  void SetTitle(const std::string& value) { title_ = value; }

  // Transition type.
  ::headless::page::TransitionType GetTransitionType() const { return transition_type_; }
  void SetTransitionType(::headless::page::TransitionType value) { transition_type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NavigationEntry> Clone() const;

  template<int STATE>
  class NavigationEntryBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdSet = 1 << 1,
    kUrlSet = 1 << 2,
    kUserTypedURLSet = 1 << 3,
    kTitleSet = 1 << 4,
    kTransitionTypeSet = 1 << 5,
      kAllRequiredFieldsSet = (kIdSet | kUrlSet | kUserTypedURLSet | kTitleSet | kTransitionTypeSet | 0)
    };

    NavigationEntryBuilder<STATE | kIdSet>& SetId(int value) {
      static_assert(!(STATE & kIdSet), "property id should not have already been set");
      result_->SetId(value);
      return CastState<kIdSet>();
    }

    NavigationEntryBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    NavigationEntryBuilder<STATE | kUserTypedURLSet>& SetUserTypedURL(const std::string& value) {
      static_assert(!(STATE & kUserTypedURLSet), "property userTypedURL should not have already been set");
      result_->SetUserTypedURL(value);
      return CastState<kUserTypedURLSet>();
    }

    NavigationEntryBuilder<STATE | kTitleSet>& SetTitle(const std::string& value) {
      static_assert(!(STATE & kTitleSet), "property title should not have already been set");
      result_->SetTitle(value);
      return CastState<kTitleSet>();
    }

    NavigationEntryBuilder<STATE | kTransitionTypeSet>& SetTransitionType(::headless::page::TransitionType value) {
      static_assert(!(STATE & kTransitionTypeSet), "property transitionType should not have already been set");
      result_->SetTransitionType(value);
      return CastState<kTransitionTypeSet>();
    }

    std::unique_ptr<NavigationEntry> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NavigationEntry;
    NavigationEntryBuilder() : result_(new NavigationEntry()) { }

    template<int STEP> NavigationEntryBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NavigationEntryBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NavigationEntry> result_;
  };

  static NavigationEntryBuilder<0> Builder() {
    return NavigationEntryBuilder<0>();
  }

 private:
  NavigationEntry() { }

  int id_;
  std::string url_;
  std::string user_typedurl_;
  std::string title_;
  ::headless::page::TransitionType transition_type_;

  DISALLOW_COPY_AND_ASSIGN(NavigationEntry);
};


// Screencast frame metadata.
class HEADLESS_EXPORT ScreencastFrameMetadata {
 public:
  static std::unique_ptr<ScreencastFrameMetadata> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScreencastFrameMetadata() { }

  // Top offset in DIP.
  double GetOffsetTop() const { return offset_top_; }
  void SetOffsetTop(double value) { offset_top_ = value; }

  // Page scale factor.
  double GetPageScaleFactor() const { return page_scale_factor_; }
  void SetPageScaleFactor(double value) { page_scale_factor_ = value; }

  // Device screen width in DIP.
  double GetDeviceWidth() const { return device_width_; }
  void SetDeviceWidth(double value) { device_width_ = value; }

  // Device screen height in DIP.
  double GetDeviceHeight() const { return device_height_; }
  void SetDeviceHeight(double value) { device_height_ = value; }

  // Position of horizontal scroll in CSS pixels.
  double GetScrollOffsetX() const { return scroll_offsetx_; }
  void SetScrollOffsetX(double value) { scroll_offsetx_ = value; }

  // Position of vertical scroll in CSS pixels.
  double GetScrollOffsetY() const { return scroll_offsety_; }
  void SetScrollOffsetY(double value) { scroll_offsety_ = value; }

  // Frame swap timestamp.
  bool HasTimestamp() const { return !!timestamp_; }
  double GetTimestamp() const { DCHECK(HasTimestamp()); return timestamp_.value(); }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScreencastFrameMetadata> Clone() const;

  template<int STATE>
  class ScreencastFrameMetadataBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOffsetTopSet = 1 << 1,
    kPageScaleFactorSet = 1 << 2,
    kDeviceWidthSet = 1 << 3,
    kDeviceHeightSet = 1 << 4,
    kScrollOffsetXSet = 1 << 5,
    kScrollOffsetYSet = 1 << 6,
      kAllRequiredFieldsSet = (kOffsetTopSet | kPageScaleFactorSet | kDeviceWidthSet | kDeviceHeightSet | kScrollOffsetXSet | kScrollOffsetYSet | 0)
    };

    ScreencastFrameMetadataBuilder<STATE | kOffsetTopSet>& SetOffsetTop(double value) {
      static_assert(!(STATE & kOffsetTopSet), "property offsetTop should not have already been set");
      result_->SetOffsetTop(value);
      return CastState<kOffsetTopSet>();
    }

    ScreencastFrameMetadataBuilder<STATE | kPageScaleFactorSet>& SetPageScaleFactor(double value) {
      static_assert(!(STATE & kPageScaleFactorSet), "property pageScaleFactor should not have already been set");
      result_->SetPageScaleFactor(value);
      return CastState<kPageScaleFactorSet>();
    }

    ScreencastFrameMetadataBuilder<STATE | kDeviceWidthSet>& SetDeviceWidth(double value) {
      static_assert(!(STATE & kDeviceWidthSet), "property deviceWidth should not have already been set");
      result_->SetDeviceWidth(value);
      return CastState<kDeviceWidthSet>();
    }

    ScreencastFrameMetadataBuilder<STATE | kDeviceHeightSet>& SetDeviceHeight(double value) {
      static_assert(!(STATE & kDeviceHeightSet), "property deviceHeight should not have already been set");
      result_->SetDeviceHeight(value);
      return CastState<kDeviceHeightSet>();
    }

    ScreencastFrameMetadataBuilder<STATE | kScrollOffsetXSet>& SetScrollOffsetX(double value) {
      static_assert(!(STATE & kScrollOffsetXSet), "property scrollOffsetX should not have already been set");
      result_->SetScrollOffsetX(value);
      return CastState<kScrollOffsetXSet>();
    }

    ScreencastFrameMetadataBuilder<STATE | kScrollOffsetYSet>& SetScrollOffsetY(double value) {
      static_assert(!(STATE & kScrollOffsetYSet), "property scrollOffsetY should not have already been set");
      result_->SetScrollOffsetY(value);
      return CastState<kScrollOffsetYSet>();
    }

    ScreencastFrameMetadataBuilder<STATE>& SetTimestamp(double value) {
      result_->SetTimestamp(value);
      return *this;
    }

    std::unique_ptr<ScreencastFrameMetadata> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScreencastFrameMetadata;
    ScreencastFrameMetadataBuilder() : result_(new ScreencastFrameMetadata()) { }

    template<int STEP> ScreencastFrameMetadataBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScreencastFrameMetadataBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScreencastFrameMetadata> result_;
  };

  static ScreencastFrameMetadataBuilder<0> Builder() {
    return ScreencastFrameMetadataBuilder<0>();
  }

 private:
  ScreencastFrameMetadata() { }

  double offset_top_;
  double page_scale_factor_;
  double device_width_;
  double device_height_;
  double scroll_offsetx_;
  double scroll_offsety_;
  base::Optional<double> timestamp_;

  DISALLOW_COPY_AND_ASSIGN(ScreencastFrameMetadata);
};


// Error while paring app manifest.
class HEADLESS_EXPORT AppManifestError {
 public:
  static std::unique_ptr<AppManifestError> Parse(const base::Value& value, ErrorReporter* errors);
  ~AppManifestError() { }

  // Error message.
  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // If criticial, this is a non-recoverable parse error.
  int GetCritical() const { return critical_; }
  void SetCritical(int value) { critical_ = value; }

  // Error line.
  int GetLine() const { return line_; }
  void SetLine(int value) { line_ = value; }

  // Error column.
  int GetColumn() const { return column_; }
  void SetColumn(int value) { column_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AppManifestError> Clone() const;

  template<int STATE>
  class AppManifestErrorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMessageSet = 1 << 1,
    kCriticalSet = 1 << 2,
    kLineSet = 1 << 3,
    kColumnSet = 1 << 4,
      kAllRequiredFieldsSet = (kMessageSet | kCriticalSet | kLineSet | kColumnSet | 0)
    };

    AppManifestErrorBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    AppManifestErrorBuilder<STATE | kCriticalSet>& SetCritical(int value) {
      static_assert(!(STATE & kCriticalSet), "property critical should not have already been set");
      result_->SetCritical(value);
      return CastState<kCriticalSet>();
    }

    AppManifestErrorBuilder<STATE | kLineSet>& SetLine(int value) {
      static_assert(!(STATE & kLineSet), "property line should not have already been set");
      result_->SetLine(value);
      return CastState<kLineSet>();
    }

    AppManifestErrorBuilder<STATE | kColumnSet>& SetColumn(int value) {
      static_assert(!(STATE & kColumnSet), "property column should not have already been set");
      result_->SetColumn(value);
      return CastState<kColumnSet>();
    }

    std::unique_ptr<AppManifestError> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AppManifestError;
    AppManifestErrorBuilder() : result_(new AppManifestError()) { }

    template<int STEP> AppManifestErrorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AppManifestErrorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AppManifestError> result_;
  };

  static AppManifestErrorBuilder<0> Builder() {
    return AppManifestErrorBuilder<0>();
  }

 private:
  AppManifestError() { }

  std::string message_;
  int critical_;
  int line_;
  int column_;

  DISALLOW_COPY_AND_ASSIGN(AppManifestError);
};


// Parsed app manifest properties.
class HEADLESS_EXPORT AppManifestParsedProperties {
 public:
  static std::unique_ptr<AppManifestParsedProperties> Parse(const base::Value& value, ErrorReporter* errors);
  ~AppManifestParsedProperties() { }

  // Computed scope value
  std::string GetScope() const { return scope_; }
  void SetScope(const std::string& value) { scope_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AppManifestParsedProperties> Clone() const;

  template<int STATE>
  class AppManifestParsedPropertiesBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kScopeSet = 1 << 1,
      kAllRequiredFieldsSet = (kScopeSet | 0)
    };

    AppManifestParsedPropertiesBuilder<STATE | kScopeSet>& SetScope(const std::string& value) {
      static_assert(!(STATE & kScopeSet), "property scope should not have already been set");
      result_->SetScope(value);
      return CastState<kScopeSet>();
    }

    std::unique_ptr<AppManifestParsedProperties> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AppManifestParsedProperties;
    AppManifestParsedPropertiesBuilder() : result_(new AppManifestParsedProperties()) { }

    template<int STEP> AppManifestParsedPropertiesBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AppManifestParsedPropertiesBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AppManifestParsedProperties> result_;
  };

  static AppManifestParsedPropertiesBuilder<0> Builder() {
    return AppManifestParsedPropertiesBuilder<0>();
  }

 private:
  AppManifestParsedProperties() { }

  std::string scope_;

  DISALLOW_COPY_AND_ASSIGN(AppManifestParsedProperties);
};


// Layout viewport position and dimensions.
class HEADLESS_EXPORT LayoutViewport {
 public:
  static std::unique_ptr<LayoutViewport> Parse(const base::Value& value, ErrorReporter* errors);
  ~LayoutViewport() { }

  // Horizontal offset relative to the document (CSS pixels).
  int GetPageX() const { return pagex_; }
  void SetPageX(int value) { pagex_ = value; }

  // Vertical offset relative to the document (CSS pixels).
  int GetPageY() const { return pagey_; }
  void SetPageY(int value) { pagey_ = value; }

  // Width (CSS pixels), excludes scrollbar if present.
  int GetClientWidth() const { return client_width_; }
  void SetClientWidth(int value) { client_width_ = value; }

  // Height (CSS pixels), excludes scrollbar if present.
  int GetClientHeight() const { return client_height_; }
  void SetClientHeight(int value) { client_height_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LayoutViewport> Clone() const;

  template<int STATE>
  class LayoutViewportBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kPageXSet = 1 << 1,
    kPageYSet = 1 << 2,
    kClientWidthSet = 1 << 3,
    kClientHeightSet = 1 << 4,
      kAllRequiredFieldsSet = (kPageXSet | kPageYSet | kClientWidthSet | kClientHeightSet | 0)
    };

    LayoutViewportBuilder<STATE | kPageXSet>& SetPageX(int value) {
      static_assert(!(STATE & kPageXSet), "property pageX should not have already been set");
      result_->SetPageX(value);
      return CastState<kPageXSet>();
    }

    LayoutViewportBuilder<STATE | kPageYSet>& SetPageY(int value) {
      static_assert(!(STATE & kPageYSet), "property pageY should not have already been set");
      result_->SetPageY(value);
      return CastState<kPageYSet>();
    }

    LayoutViewportBuilder<STATE | kClientWidthSet>& SetClientWidth(int value) {
      static_assert(!(STATE & kClientWidthSet), "property clientWidth should not have already been set");
      result_->SetClientWidth(value);
      return CastState<kClientWidthSet>();
    }

    LayoutViewportBuilder<STATE | kClientHeightSet>& SetClientHeight(int value) {
      static_assert(!(STATE & kClientHeightSet), "property clientHeight should not have already been set");
      result_->SetClientHeight(value);
      return CastState<kClientHeightSet>();
    }

    std::unique_ptr<LayoutViewport> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LayoutViewport;
    LayoutViewportBuilder() : result_(new LayoutViewport()) { }

    template<int STEP> LayoutViewportBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LayoutViewportBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LayoutViewport> result_;
  };

  static LayoutViewportBuilder<0> Builder() {
    return LayoutViewportBuilder<0>();
  }

 private:
  LayoutViewport() { }

  int pagex_;
  int pagey_;
  int client_width_;
  int client_height_;

  DISALLOW_COPY_AND_ASSIGN(LayoutViewport);
};


// Visual viewport position, dimensions, and scale.
class HEADLESS_EXPORT VisualViewport {
 public:
  static std::unique_ptr<VisualViewport> Parse(const base::Value& value, ErrorReporter* errors);
  ~VisualViewport() { }

  // Horizontal offset relative to the layout viewport (CSS pixels).
  double GetOffsetX() const { return offsetx_; }
  void SetOffsetX(double value) { offsetx_ = value; }

  // Vertical offset relative to the layout viewport (CSS pixels).
  double GetOffsetY() const { return offsety_; }
  void SetOffsetY(double value) { offsety_ = value; }

  // Horizontal offset relative to the document (CSS pixels).
  double GetPageX() const { return pagex_; }
  void SetPageX(double value) { pagex_ = value; }

  // Vertical offset relative to the document (CSS pixels).
  double GetPageY() const { return pagey_; }
  void SetPageY(double value) { pagey_ = value; }

  // Width (CSS pixels), excludes scrollbar if present.
  double GetClientWidth() const { return client_width_; }
  void SetClientWidth(double value) { client_width_ = value; }

  // Height (CSS pixels), excludes scrollbar if present.
  double GetClientHeight() const { return client_height_; }
  void SetClientHeight(double value) { client_height_ = value; }

  // Scale relative to the ideal viewport (size at width=device-width).
  double GetScale() const { return scale_; }
  void SetScale(double value) { scale_ = value; }

  // Page zoom factor (CSS to device independent pixels ratio).
  bool HasZoom() const { return !!zoom_; }
  double GetZoom() const { DCHECK(HasZoom()); return zoom_.value(); }
  void SetZoom(double value) { zoom_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<VisualViewport> Clone() const;

  template<int STATE>
  class VisualViewportBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kOffsetXSet = 1 << 1,
    kOffsetYSet = 1 << 2,
    kPageXSet = 1 << 3,
    kPageYSet = 1 << 4,
    kClientWidthSet = 1 << 5,
    kClientHeightSet = 1 << 6,
    kScaleSet = 1 << 7,
      kAllRequiredFieldsSet = (kOffsetXSet | kOffsetYSet | kPageXSet | kPageYSet | kClientWidthSet | kClientHeightSet | kScaleSet | 0)
    };

    VisualViewportBuilder<STATE | kOffsetXSet>& SetOffsetX(double value) {
      static_assert(!(STATE & kOffsetXSet), "property offsetX should not have already been set");
      result_->SetOffsetX(value);
      return CastState<kOffsetXSet>();
    }

    VisualViewportBuilder<STATE | kOffsetYSet>& SetOffsetY(double value) {
      static_assert(!(STATE & kOffsetYSet), "property offsetY should not have already been set");
      result_->SetOffsetY(value);
      return CastState<kOffsetYSet>();
    }

    VisualViewportBuilder<STATE | kPageXSet>& SetPageX(double value) {
      static_assert(!(STATE & kPageXSet), "property pageX should not have already been set");
      result_->SetPageX(value);
      return CastState<kPageXSet>();
    }

    VisualViewportBuilder<STATE | kPageYSet>& SetPageY(double value) {
      static_assert(!(STATE & kPageYSet), "property pageY should not have already been set");
      result_->SetPageY(value);
      return CastState<kPageYSet>();
    }

    VisualViewportBuilder<STATE | kClientWidthSet>& SetClientWidth(double value) {
      static_assert(!(STATE & kClientWidthSet), "property clientWidth should not have already been set");
      result_->SetClientWidth(value);
      return CastState<kClientWidthSet>();
    }

    VisualViewportBuilder<STATE | kClientHeightSet>& SetClientHeight(double value) {
      static_assert(!(STATE & kClientHeightSet), "property clientHeight should not have already been set");
      result_->SetClientHeight(value);
      return CastState<kClientHeightSet>();
    }

    VisualViewportBuilder<STATE | kScaleSet>& SetScale(double value) {
      static_assert(!(STATE & kScaleSet), "property scale should not have already been set");
      result_->SetScale(value);
      return CastState<kScaleSet>();
    }

    VisualViewportBuilder<STATE>& SetZoom(double value) {
      result_->SetZoom(value);
      return *this;
    }

    std::unique_ptr<VisualViewport> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class VisualViewport;
    VisualViewportBuilder() : result_(new VisualViewport()) { }

    template<int STEP> VisualViewportBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<VisualViewportBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<VisualViewport> result_;
  };

  static VisualViewportBuilder<0> Builder() {
    return VisualViewportBuilder<0>();
  }

 private:
  VisualViewport() { }

  double offsetx_;
  double offsety_;
  double pagex_;
  double pagey_;
  double client_width_;
  double client_height_;
  double scale_;
  base::Optional<double> zoom_;

  DISALLOW_COPY_AND_ASSIGN(VisualViewport);
};


// Viewport for capturing screenshot.
class HEADLESS_EXPORT Viewport {
 public:
  static std::unique_ptr<Viewport> Parse(const base::Value& value, ErrorReporter* errors);
  ~Viewport() { }

  // X offset in device independent pixels (dip).
  double GetX() const { return x_; }
  void SetX(double value) { x_ = value; }

  // Y offset in device independent pixels (dip).
  double GetY() const { return y_; }
  void SetY(double value) { y_ = value; }

  // Rectangle width in device independent pixels (dip).
  double GetWidth() const { return width_; }
  void SetWidth(double value) { width_ = value; }

  // Rectangle height in device independent pixels (dip).
  double GetHeight() const { return height_; }
  void SetHeight(double value) { height_ = value; }

  // Page scale factor.
  double GetScale() const { return scale_; }
  void SetScale(double value) { scale_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<Viewport> Clone() const;

  template<int STATE>
  class ViewportBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kXSet = 1 << 1,
    kYSet = 1 << 2,
    kWidthSet = 1 << 3,
    kHeightSet = 1 << 4,
    kScaleSet = 1 << 5,
      kAllRequiredFieldsSet = (kXSet | kYSet | kWidthSet | kHeightSet | kScaleSet | 0)
    };

    ViewportBuilder<STATE | kXSet>& SetX(double value) {
      static_assert(!(STATE & kXSet), "property x should not have already been set");
      result_->SetX(value);
      return CastState<kXSet>();
    }

    ViewportBuilder<STATE | kYSet>& SetY(double value) {
      static_assert(!(STATE & kYSet), "property y should not have already been set");
      result_->SetY(value);
      return CastState<kYSet>();
    }

    ViewportBuilder<STATE | kWidthSet>& SetWidth(double value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    ViewportBuilder<STATE | kHeightSet>& SetHeight(double value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    ViewportBuilder<STATE | kScaleSet>& SetScale(double value) {
      static_assert(!(STATE & kScaleSet), "property scale should not have already been set");
      result_->SetScale(value);
      return CastState<kScaleSet>();
    }

    std::unique_ptr<Viewport> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class Viewport;
    ViewportBuilder() : result_(new Viewport()) { }

    template<int STEP> ViewportBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ViewportBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<Viewport> result_;
  };

  static ViewportBuilder<0> Builder() {
    return ViewportBuilder<0>();
  }

 private:
  Viewport() { }

  double x_;
  double y_;
  double width_;
  double height_;
  double scale_;

  DISALLOW_COPY_AND_ASSIGN(Viewport);
};


// Generic font families collection.
class HEADLESS_EXPORT FontFamilies {
 public:
  static std::unique_ptr<FontFamilies> Parse(const base::Value& value, ErrorReporter* errors);
  ~FontFamilies() { }

  // The standard font-family.
  bool HasStandard() const { return !!standard_; }
  std::string GetStandard() const { DCHECK(HasStandard()); return standard_.value(); }
  void SetStandard(const std::string& value) { standard_ = value; }

  // The fixed font-family.
  bool HasFixed() const { return !!fixed_; }
  std::string GetFixed() const { DCHECK(HasFixed()); return fixed_.value(); }
  void SetFixed(const std::string& value) { fixed_ = value; }

  // The serif font-family.
  bool HasSerif() const { return !!serif_; }
  std::string GetSerif() const { DCHECK(HasSerif()); return serif_.value(); }
  void SetSerif(const std::string& value) { serif_ = value; }

  // The sansSerif font-family.
  bool HasSansSerif() const { return !!sans_serif_; }
  std::string GetSansSerif() const { DCHECK(HasSansSerif()); return sans_serif_.value(); }
  void SetSansSerif(const std::string& value) { sans_serif_ = value; }

  // The cursive font-family.
  bool HasCursive() const { return !!cursive_; }
  std::string GetCursive() const { DCHECK(HasCursive()); return cursive_.value(); }
  void SetCursive(const std::string& value) { cursive_ = value; }

  // The fantasy font-family.
  bool HasFantasy() const { return !!fantasy_; }
  std::string GetFantasy() const { DCHECK(HasFantasy()); return fantasy_.value(); }
  void SetFantasy(const std::string& value) { fantasy_ = value; }

  // The pictograph font-family.
  bool HasPictograph() const { return !!pictograph_; }
  std::string GetPictograph() const { DCHECK(HasPictograph()); return pictograph_.value(); }
  void SetPictograph(const std::string& value) { pictograph_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FontFamilies> Clone() const;

  template<int STATE>
  class FontFamiliesBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    FontFamiliesBuilder<STATE>& SetStandard(const std::string& value) {
      result_->SetStandard(value);
      return *this;
    }

    FontFamiliesBuilder<STATE>& SetFixed(const std::string& value) {
      result_->SetFixed(value);
      return *this;
    }

    FontFamiliesBuilder<STATE>& SetSerif(const std::string& value) {
      result_->SetSerif(value);
      return *this;
    }

    FontFamiliesBuilder<STATE>& SetSansSerif(const std::string& value) {
      result_->SetSansSerif(value);
      return *this;
    }

    FontFamiliesBuilder<STATE>& SetCursive(const std::string& value) {
      result_->SetCursive(value);
      return *this;
    }

    FontFamiliesBuilder<STATE>& SetFantasy(const std::string& value) {
      result_->SetFantasy(value);
      return *this;
    }

    FontFamiliesBuilder<STATE>& SetPictograph(const std::string& value) {
      result_->SetPictograph(value);
      return *this;
    }

    std::unique_ptr<FontFamilies> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FontFamilies;
    FontFamiliesBuilder() : result_(new FontFamilies()) { }

    template<int STEP> FontFamiliesBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FontFamiliesBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FontFamilies> result_;
  };

  static FontFamiliesBuilder<0> Builder() {
    return FontFamiliesBuilder<0>();
  }

 private:
  FontFamilies() { }

  base::Optional<std::string> standard_;
  base::Optional<std::string> fixed_;
  base::Optional<std::string> serif_;
  base::Optional<std::string> sans_serif_;
  base::Optional<std::string> cursive_;
  base::Optional<std::string> fantasy_;
  base::Optional<std::string> pictograph_;

  DISALLOW_COPY_AND_ASSIGN(FontFamilies);
};


// Default font sizes.
class HEADLESS_EXPORT FontSizes {
 public:
  static std::unique_ptr<FontSizes> Parse(const base::Value& value, ErrorReporter* errors);
  ~FontSizes() { }

  // Default standard font size.
  bool HasStandard() const { return !!standard_; }
  int GetStandard() const { DCHECK(HasStandard()); return standard_.value(); }
  void SetStandard(int value) { standard_ = value; }

  // Default fixed font size.
  bool HasFixed() const { return !!fixed_; }
  int GetFixed() const { DCHECK(HasFixed()); return fixed_.value(); }
  void SetFixed(int value) { fixed_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FontSizes> Clone() const;

  template<int STATE>
  class FontSizesBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    FontSizesBuilder<STATE>& SetStandard(int value) {
      result_->SetStandard(value);
      return *this;
    }

    FontSizesBuilder<STATE>& SetFixed(int value) {
      result_->SetFixed(value);
      return *this;
    }

    std::unique_ptr<FontSizes> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FontSizes;
    FontSizesBuilder() : result_(new FontSizes()) { }

    template<int STEP> FontSizesBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FontSizesBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FontSizes> result_;
  };

  static FontSizesBuilder<0> Builder() {
    return FontSizesBuilder<0>();
  }

 private:
  FontSizes() { }

  base::Optional<int> standard_;
  base::Optional<int> fixed_;

  DISALLOW_COPY_AND_ASSIGN(FontSizes);
};


class HEADLESS_EXPORT InstallabilityErrorArgument {
 public:
  static std::unique_ptr<InstallabilityErrorArgument> Parse(const base::Value& value, ErrorReporter* errors);
  ~InstallabilityErrorArgument() { }

  // Argument name (e.g. name:'minimum-icon-size-in-pixels').
  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  // Argument value (e.g. value:'64').
  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InstallabilityErrorArgument> Clone() const;

  template<int STATE>
  class InstallabilityErrorArgumentBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kValueSet | 0)
    };

    InstallabilityErrorArgumentBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    InstallabilityErrorArgumentBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<InstallabilityErrorArgument> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InstallabilityErrorArgument;
    InstallabilityErrorArgumentBuilder() : result_(new InstallabilityErrorArgument()) { }

    template<int STEP> InstallabilityErrorArgumentBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InstallabilityErrorArgumentBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InstallabilityErrorArgument> result_;
  };

  static InstallabilityErrorArgumentBuilder<0> Builder() {
    return InstallabilityErrorArgumentBuilder<0>();
  }

 private:
  InstallabilityErrorArgument() { }

  std::string name_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(InstallabilityErrorArgument);
};


// The installability error
class HEADLESS_EXPORT InstallabilityError {
 public:
  static std::unique_ptr<InstallabilityError> Parse(const base::Value& value, ErrorReporter* errors);
  ~InstallabilityError() { }

  // The error id (e.g. 'manifest-missing-suitable-icon').
  std::string GetErrorId() const { return error_id_; }
  void SetErrorId(const std::string& value) { error_id_ = value; }

  // The list of error arguments (e.g. {name:'minimum-icon-size-in-pixels', value:'64'}).
  const std::vector<std::unique_ptr<::headless::page::InstallabilityErrorArgument>>* GetErrorArguments() const { return &error_arguments_; }
  void SetErrorArguments(std::vector<std::unique_ptr<::headless::page::InstallabilityErrorArgument>> value) { error_arguments_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InstallabilityError> Clone() const;

  template<int STATE>
  class InstallabilityErrorBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kErrorIdSet = 1 << 1,
    kErrorArgumentsSet = 1 << 2,
      kAllRequiredFieldsSet = (kErrorIdSet | kErrorArgumentsSet | 0)
    };

    InstallabilityErrorBuilder<STATE | kErrorIdSet>& SetErrorId(const std::string& value) {
      static_assert(!(STATE & kErrorIdSet), "property errorId should not have already been set");
      result_->SetErrorId(value);
      return CastState<kErrorIdSet>();
    }

    InstallabilityErrorBuilder<STATE | kErrorArgumentsSet>& SetErrorArguments(std::vector<std::unique_ptr<::headless::page::InstallabilityErrorArgument>> value) {
      static_assert(!(STATE & kErrorArgumentsSet), "property errorArguments should not have already been set");
      result_->SetErrorArguments(std::move(value));
      return CastState<kErrorArgumentsSet>();
    }

    std::unique_ptr<InstallabilityError> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InstallabilityError;
    InstallabilityErrorBuilder() : result_(new InstallabilityError()) { }

    template<int STEP> InstallabilityErrorBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InstallabilityErrorBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InstallabilityError> result_;
  };

  static InstallabilityErrorBuilder<0> Builder() {
    return InstallabilityErrorBuilder<0>();
  }

 private:
  InstallabilityError() { }

  std::string error_id_;
  std::vector<std::unique_ptr<::headless::page::InstallabilityErrorArgument>> error_arguments_;

  DISALLOW_COPY_AND_ASSIGN(InstallabilityError);
};


// Parameters for the AddScriptToEvaluateOnLoad command.
class HEADLESS_EXPORT AddScriptToEvaluateOnLoadParams {
 public:
  static std::unique_ptr<AddScriptToEvaluateOnLoadParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddScriptToEvaluateOnLoadParams() { }

  std::string GetScriptSource() const { return script_source_; }
  void SetScriptSource(const std::string& value) { script_source_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddScriptToEvaluateOnLoadParams> Clone() const;

  template<int STATE>
  class AddScriptToEvaluateOnLoadParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kScriptSourceSet = 1 << 1,
      kAllRequiredFieldsSet = (kScriptSourceSet | 0)
    };

    AddScriptToEvaluateOnLoadParamsBuilder<STATE | kScriptSourceSet>& SetScriptSource(const std::string& value) {
      static_assert(!(STATE & kScriptSourceSet), "property scriptSource should not have already been set");
      result_->SetScriptSource(value);
      return CastState<kScriptSourceSet>();
    }

    std::unique_ptr<AddScriptToEvaluateOnLoadParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddScriptToEvaluateOnLoadParams;
    AddScriptToEvaluateOnLoadParamsBuilder() : result_(new AddScriptToEvaluateOnLoadParams()) { }

    template<int STEP> AddScriptToEvaluateOnLoadParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddScriptToEvaluateOnLoadParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddScriptToEvaluateOnLoadParams> result_;
  };

  static AddScriptToEvaluateOnLoadParamsBuilder<0> Builder() {
    return AddScriptToEvaluateOnLoadParamsBuilder<0>();
  }

 private:
  AddScriptToEvaluateOnLoadParams() { }

  std::string script_source_;

  DISALLOW_COPY_AND_ASSIGN(AddScriptToEvaluateOnLoadParams);
};


// Result for the AddScriptToEvaluateOnLoad command.
class HEADLESS_EXPORT AddScriptToEvaluateOnLoadResult {
 public:
  static std::unique_ptr<AddScriptToEvaluateOnLoadResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddScriptToEvaluateOnLoadResult() { }

  // Identifier of the added script.
  std::string GetIdentifier() const { return identifier_; }
  void SetIdentifier(const std::string& value) { identifier_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddScriptToEvaluateOnLoadResult> Clone() const;

  template<int STATE>
  class AddScriptToEvaluateOnLoadResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdentifierSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdentifierSet | 0)
    };

    AddScriptToEvaluateOnLoadResultBuilder<STATE | kIdentifierSet>& SetIdentifier(const std::string& value) {
      static_assert(!(STATE & kIdentifierSet), "property identifier should not have already been set");
      result_->SetIdentifier(value);
      return CastState<kIdentifierSet>();
    }

    std::unique_ptr<AddScriptToEvaluateOnLoadResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddScriptToEvaluateOnLoadResult;
    AddScriptToEvaluateOnLoadResultBuilder() : result_(new AddScriptToEvaluateOnLoadResult()) { }

    template<int STEP> AddScriptToEvaluateOnLoadResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddScriptToEvaluateOnLoadResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddScriptToEvaluateOnLoadResult> result_;
  };

  static AddScriptToEvaluateOnLoadResultBuilder<0> Builder() {
    return AddScriptToEvaluateOnLoadResultBuilder<0>();
  }

 private:
  AddScriptToEvaluateOnLoadResult() { }

  std::string identifier_;

  DISALLOW_COPY_AND_ASSIGN(AddScriptToEvaluateOnLoadResult);
};


// Parameters for the AddScriptToEvaluateOnNewDocument command.
class HEADLESS_EXPORT AddScriptToEvaluateOnNewDocumentParams {
 public:
  static std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddScriptToEvaluateOnNewDocumentParams() { }

  std::string GetSource() const { return source_; }
  void SetSource(const std::string& value) { source_ = value; }

  // If specified, creates an isolated world with the given name and evaluates given script in it.
  // This world name will be used as the ExecutionContextDescription::name when the corresponding
  // event is emitted.
  bool HasWorldName() const { return !!world_name_; }
  std::string GetWorldName() const { DCHECK(HasWorldName()); return world_name_.value(); }
  void SetWorldName(const std::string& value) { world_name_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> Clone() const;

  template<int STATE>
  class AddScriptToEvaluateOnNewDocumentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSourceSet = 1 << 1,
      kAllRequiredFieldsSet = (kSourceSet | 0)
    };

    AddScriptToEvaluateOnNewDocumentParamsBuilder<STATE | kSourceSet>& SetSource(const std::string& value) {
      static_assert(!(STATE & kSourceSet), "property source should not have already been set");
      result_->SetSource(value);
      return CastState<kSourceSet>();
    }

    AddScriptToEvaluateOnNewDocumentParamsBuilder<STATE>& SetWorldName(const std::string& value) {
      result_->SetWorldName(value);
      return *this;
    }

    std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddScriptToEvaluateOnNewDocumentParams;
    AddScriptToEvaluateOnNewDocumentParamsBuilder() : result_(new AddScriptToEvaluateOnNewDocumentParams()) { }

    template<int STEP> AddScriptToEvaluateOnNewDocumentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddScriptToEvaluateOnNewDocumentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddScriptToEvaluateOnNewDocumentParams> result_;
  };

  static AddScriptToEvaluateOnNewDocumentParamsBuilder<0> Builder() {
    return AddScriptToEvaluateOnNewDocumentParamsBuilder<0>();
  }

 private:
  AddScriptToEvaluateOnNewDocumentParams() { }

  std::string source_;
  base::Optional<std::string> world_name_;

  DISALLOW_COPY_AND_ASSIGN(AddScriptToEvaluateOnNewDocumentParams);
};


// Result for the AddScriptToEvaluateOnNewDocument command.
class HEADLESS_EXPORT AddScriptToEvaluateOnNewDocumentResult {
 public:
  static std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddScriptToEvaluateOnNewDocumentResult() { }

  // Identifier of the added script.
  std::string GetIdentifier() const { return identifier_; }
  void SetIdentifier(const std::string& value) { identifier_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> Clone() const;

  template<int STATE>
  class AddScriptToEvaluateOnNewDocumentResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdentifierSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdentifierSet | 0)
    };

    AddScriptToEvaluateOnNewDocumentResultBuilder<STATE | kIdentifierSet>& SetIdentifier(const std::string& value) {
      static_assert(!(STATE & kIdentifierSet), "property identifier should not have already been set");
      result_->SetIdentifier(value);
      return CastState<kIdentifierSet>();
    }

    std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddScriptToEvaluateOnNewDocumentResult;
    AddScriptToEvaluateOnNewDocumentResultBuilder() : result_(new AddScriptToEvaluateOnNewDocumentResult()) { }

    template<int STEP> AddScriptToEvaluateOnNewDocumentResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddScriptToEvaluateOnNewDocumentResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddScriptToEvaluateOnNewDocumentResult> result_;
  };

  static AddScriptToEvaluateOnNewDocumentResultBuilder<0> Builder() {
    return AddScriptToEvaluateOnNewDocumentResultBuilder<0>();
  }

 private:
  AddScriptToEvaluateOnNewDocumentResult() { }

  std::string identifier_;

  DISALLOW_COPY_AND_ASSIGN(AddScriptToEvaluateOnNewDocumentResult);
};


// Parameters for the BringToFront command.
class HEADLESS_EXPORT BringToFrontParams {
 public:
  static std::unique_ptr<BringToFrontParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~BringToFrontParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BringToFrontParams> Clone() const;

  template<int STATE>
  class BringToFrontParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<BringToFrontParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BringToFrontParams;
    BringToFrontParamsBuilder() : result_(new BringToFrontParams()) { }

    template<int STEP> BringToFrontParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BringToFrontParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BringToFrontParams> result_;
  };

  static BringToFrontParamsBuilder<0> Builder() {
    return BringToFrontParamsBuilder<0>();
  }

 private:
  BringToFrontParams() { }


  DISALLOW_COPY_AND_ASSIGN(BringToFrontParams);
};


// Result for the BringToFront command.
class HEADLESS_EXPORT BringToFrontResult {
 public:
  static std::unique_ptr<BringToFrontResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~BringToFrontResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BringToFrontResult> Clone() const;

  template<int STATE>
  class BringToFrontResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<BringToFrontResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BringToFrontResult;
    BringToFrontResultBuilder() : result_(new BringToFrontResult()) { }

    template<int STEP> BringToFrontResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BringToFrontResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BringToFrontResult> result_;
  };

  static BringToFrontResultBuilder<0> Builder() {
    return BringToFrontResultBuilder<0>();
  }

 private:
  BringToFrontResult() { }


  DISALLOW_COPY_AND_ASSIGN(BringToFrontResult);
};


// Parameters for the CaptureScreenshot command.
class HEADLESS_EXPORT CaptureScreenshotParams {
 public:
  static std::unique_ptr<CaptureScreenshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CaptureScreenshotParams() { }

  // Image compression format (defaults to png).
  bool HasFormat() const { return !!format_; }
  ::headless::page::CaptureScreenshotFormat GetFormat() const { DCHECK(HasFormat()); return format_.value(); }
  void SetFormat(::headless::page::CaptureScreenshotFormat value) { format_ = value; }

  // Compression quality from range [0..100] (jpeg only).
  bool HasQuality() const { return !!quality_; }
  int GetQuality() const { DCHECK(HasQuality()); return quality_.value(); }
  void SetQuality(int value) { quality_ = value; }

  // Capture the screenshot of a given region only.
  bool HasClip() const { return !!clip_; }
  const ::headless::page::Viewport* GetClip() const { DCHECK(HasClip()); return clip_.value().get(); }
  void SetClip(std::unique_ptr<::headless::page::Viewport> value) { clip_ = std::move(value); }

  // Capture the screenshot from the surface, rather than the view. Defaults to true.
  bool HasFromSurface() const { return !!from_surface_; }
  bool GetFromSurface() const { DCHECK(HasFromSurface()); return from_surface_.value(); }
  void SetFromSurface(bool value) { from_surface_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CaptureScreenshotParams> Clone() const;

  template<int STATE>
  class CaptureScreenshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    CaptureScreenshotParamsBuilder<STATE>& SetFormat(::headless::page::CaptureScreenshotFormat value) {
      result_->SetFormat(value);
      return *this;
    }

    CaptureScreenshotParamsBuilder<STATE>& SetQuality(int value) {
      result_->SetQuality(value);
      return *this;
    }

    CaptureScreenshotParamsBuilder<STATE>& SetClip(std::unique_ptr<::headless::page::Viewport> value) {
      result_->SetClip(std::move(value));
      return *this;
    }

    CaptureScreenshotParamsBuilder<STATE>& SetFromSurface(bool value) {
      result_->SetFromSurface(value);
      return *this;
    }

    std::unique_ptr<CaptureScreenshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CaptureScreenshotParams;
    CaptureScreenshotParamsBuilder() : result_(new CaptureScreenshotParams()) { }

    template<int STEP> CaptureScreenshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CaptureScreenshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CaptureScreenshotParams> result_;
  };

  static CaptureScreenshotParamsBuilder<0> Builder() {
    return CaptureScreenshotParamsBuilder<0>();
  }

 private:
  CaptureScreenshotParams() { }

  base::Optional<::headless::page::CaptureScreenshotFormat> format_;
  base::Optional<int> quality_;
  base::Optional<std::unique_ptr<::headless::page::Viewport>> clip_;
  base::Optional<bool> from_surface_;

  DISALLOW_COPY_AND_ASSIGN(CaptureScreenshotParams);
};


// Result for the CaptureScreenshot command.
class HEADLESS_EXPORT CaptureScreenshotResult {
 public:
  static std::unique_ptr<CaptureScreenshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CaptureScreenshotResult() { }

  // Base64-encoded image data.
  protocol::Binary GetData() const { return data_; }
  void SetData(const protocol::Binary& value) { data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CaptureScreenshotResult> Clone() const;

  template<int STATE>
  class CaptureScreenshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataSet = 1 << 1,
      kAllRequiredFieldsSet = (kDataSet | 0)
    };

    CaptureScreenshotResultBuilder<STATE | kDataSet>& SetData(const protocol::Binary& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    std::unique_ptr<CaptureScreenshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CaptureScreenshotResult;
    CaptureScreenshotResultBuilder() : result_(new CaptureScreenshotResult()) { }

    template<int STEP> CaptureScreenshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CaptureScreenshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CaptureScreenshotResult> result_;
  };

  static CaptureScreenshotResultBuilder<0> Builder() {
    return CaptureScreenshotResultBuilder<0>();
  }

 private:
  CaptureScreenshotResult() { }

  protocol::Binary data_;

  DISALLOW_COPY_AND_ASSIGN(CaptureScreenshotResult);
};


// Parameters for the CaptureSnapshot command.
class HEADLESS_EXPORT CaptureSnapshotParams {
 public:
  static std::unique_ptr<CaptureSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CaptureSnapshotParams() { }

  // Format (defaults to mhtml).
  bool HasFormat() const { return !!format_; }
  ::headless::page::CaptureSnapshotFormat GetFormat() const { DCHECK(HasFormat()); return format_.value(); }
  void SetFormat(::headless::page::CaptureSnapshotFormat value) { format_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CaptureSnapshotParams> Clone() const;

  template<int STATE>
  class CaptureSnapshotParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    CaptureSnapshotParamsBuilder<STATE>& SetFormat(::headless::page::CaptureSnapshotFormat value) {
      result_->SetFormat(value);
      return *this;
    }

    std::unique_ptr<CaptureSnapshotParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CaptureSnapshotParams;
    CaptureSnapshotParamsBuilder() : result_(new CaptureSnapshotParams()) { }

    template<int STEP> CaptureSnapshotParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CaptureSnapshotParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CaptureSnapshotParams> result_;
  };

  static CaptureSnapshotParamsBuilder<0> Builder() {
    return CaptureSnapshotParamsBuilder<0>();
  }

 private:
  CaptureSnapshotParams() { }

  base::Optional<::headless::page::CaptureSnapshotFormat> format_;

  DISALLOW_COPY_AND_ASSIGN(CaptureSnapshotParams);
};


// Result for the CaptureSnapshot command.
class HEADLESS_EXPORT CaptureSnapshotResult {
 public:
  static std::unique_ptr<CaptureSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CaptureSnapshotResult() { }

  // Serialized page data.
  std::string GetData() const { return data_; }
  void SetData(const std::string& value) { data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CaptureSnapshotResult> Clone() const;

  template<int STATE>
  class CaptureSnapshotResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataSet = 1 << 1,
      kAllRequiredFieldsSet = (kDataSet | 0)
    };

    CaptureSnapshotResultBuilder<STATE | kDataSet>& SetData(const std::string& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    std::unique_ptr<CaptureSnapshotResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CaptureSnapshotResult;
    CaptureSnapshotResultBuilder() : result_(new CaptureSnapshotResult()) { }

    template<int STEP> CaptureSnapshotResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CaptureSnapshotResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CaptureSnapshotResult> result_;
  };

  static CaptureSnapshotResultBuilder<0> Builder() {
    return CaptureSnapshotResultBuilder<0>();
  }

 private:
  CaptureSnapshotResult() { }

  std::string data_;

  DISALLOW_COPY_AND_ASSIGN(CaptureSnapshotResult);
};


// Parameters for the ClearDeviceMetricsOverride command.
class HEADLESS_EXPORT ClearDeviceMetricsOverrideParams {
 public:
  static std::unique_ptr<ClearDeviceMetricsOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceMetricsOverrideParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceMetricsOverrideParams> Clone() const;

  template<int STATE>
  class ClearDeviceMetricsOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceMetricsOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceMetricsOverrideParams;
    ClearDeviceMetricsOverrideParamsBuilder() : result_(new ClearDeviceMetricsOverrideParams()) { }

    template<int STEP> ClearDeviceMetricsOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceMetricsOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceMetricsOverrideParams> result_;
  };

  static ClearDeviceMetricsOverrideParamsBuilder<0> Builder() {
    return ClearDeviceMetricsOverrideParamsBuilder<0>();
  }

 private:
  ClearDeviceMetricsOverrideParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceMetricsOverrideParams);
};


// Result for the ClearDeviceMetricsOverride command.
class HEADLESS_EXPORT ClearDeviceMetricsOverrideResult {
 public:
  static std::unique_ptr<ClearDeviceMetricsOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceMetricsOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceMetricsOverrideResult> Clone() const;

  template<int STATE>
  class ClearDeviceMetricsOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceMetricsOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceMetricsOverrideResult;
    ClearDeviceMetricsOverrideResultBuilder() : result_(new ClearDeviceMetricsOverrideResult()) { }

    template<int STEP> ClearDeviceMetricsOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceMetricsOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceMetricsOverrideResult> result_;
  };

  static ClearDeviceMetricsOverrideResultBuilder<0> Builder() {
    return ClearDeviceMetricsOverrideResultBuilder<0>();
  }

 private:
  ClearDeviceMetricsOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceMetricsOverrideResult);
};


// Parameters for the ClearDeviceOrientationOverride command.
class HEADLESS_EXPORT ClearDeviceOrientationOverrideParams {
 public:
  static std::unique_ptr<ClearDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceOrientationOverrideParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceOrientationOverrideParams> Clone() const;

  template<int STATE>
  class ClearDeviceOrientationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceOrientationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceOrientationOverrideParams;
    ClearDeviceOrientationOverrideParamsBuilder() : result_(new ClearDeviceOrientationOverrideParams()) { }

    template<int STEP> ClearDeviceOrientationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceOrientationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceOrientationOverrideParams> result_;
  };

  static ClearDeviceOrientationOverrideParamsBuilder<0> Builder() {
    return ClearDeviceOrientationOverrideParamsBuilder<0>();
  }

 private:
  ClearDeviceOrientationOverrideParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceOrientationOverrideParams);
};


// Result for the ClearDeviceOrientationOverride command.
class HEADLESS_EXPORT ClearDeviceOrientationOverrideResult {
 public:
  static std::unique_ptr<ClearDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearDeviceOrientationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearDeviceOrientationOverrideResult> Clone() const;

  template<int STATE>
  class ClearDeviceOrientationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearDeviceOrientationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearDeviceOrientationOverrideResult;
    ClearDeviceOrientationOverrideResultBuilder() : result_(new ClearDeviceOrientationOverrideResult()) { }

    template<int STEP> ClearDeviceOrientationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearDeviceOrientationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearDeviceOrientationOverrideResult> result_;
  };

  static ClearDeviceOrientationOverrideResultBuilder<0> Builder() {
    return ClearDeviceOrientationOverrideResultBuilder<0>();
  }

 private:
  ClearDeviceOrientationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearDeviceOrientationOverrideResult);
};


// Parameters for the ClearGeolocationOverride command.
class HEADLESS_EXPORT ClearGeolocationOverrideParams {
 public:
  static std::unique_ptr<ClearGeolocationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearGeolocationOverrideParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearGeolocationOverrideParams> Clone() const;

  template<int STATE>
  class ClearGeolocationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearGeolocationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearGeolocationOverrideParams;
    ClearGeolocationOverrideParamsBuilder() : result_(new ClearGeolocationOverrideParams()) { }

    template<int STEP> ClearGeolocationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearGeolocationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearGeolocationOverrideParams> result_;
  };

  static ClearGeolocationOverrideParamsBuilder<0> Builder() {
    return ClearGeolocationOverrideParamsBuilder<0>();
  }

 private:
  ClearGeolocationOverrideParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearGeolocationOverrideParams);
};


// Result for the ClearGeolocationOverride command.
class HEADLESS_EXPORT ClearGeolocationOverrideResult {
 public:
  static std::unique_ptr<ClearGeolocationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearGeolocationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearGeolocationOverrideResult> Clone() const;

  template<int STATE>
  class ClearGeolocationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearGeolocationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearGeolocationOverrideResult;
    ClearGeolocationOverrideResultBuilder() : result_(new ClearGeolocationOverrideResult()) { }

    template<int STEP> ClearGeolocationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearGeolocationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearGeolocationOverrideResult> result_;
  };

  static ClearGeolocationOverrideResultBuilder<0> Builder() {
    return ClearGeolocationOverrideResultBuilder<0>();
  }

 private:
  ClearGeolocationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearGeolocationOverrideResult);
};


// Parameters for the CreateIsolatedWorld command.
class HEADLESS_EXPORT CreateIsolatedWorldParams {
 public:
  static std::unique_ptr<CreateIsolatedWorldParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CreateIsolatedWorldParams() { }

  // Id of the frame in which the isolated world should be created.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // An optional name which is reported in the Execution Context.
  bool HasWorldName() const { return !!world_name_; }
  std::string GetWorldName() const { DCHECK(HasWorldName()); return world_name_.value(); }
  void SetWorldName(const std::string& value) { world_name_ = value; }

  // Whether or not universal access should be granted to the isolated world. This is a powerful
  // option, use with caution.
  bool HasGrantUniveralAccess() const { return !!grant_univeral_access_; }
  bool GetGrantUniveralAccess() const { DCHECK(HasGrantUniveralAccess()); return grant_univeral_access_.value(); }
  void SetGrantUniveralAccess(bool value) { grant_univeral_access_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CreateIsolatedWorldParams> Clone() const;

  template<int STATE>
  class CreateIsolatedWorldParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    CreateIsolatedWorldParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    CreateIsolatedWorldParamsBuilder<STATE>& SetWorldName(const std::string& value) {
      result_->SetWorldName(value);
      return *this;
    }

    CreateIsolatedWorldParamsBuilder<STATE>& SetGrantUniveralAccess(bool value) {
      result_->SetGrantUniveralAccess(value);
      return *this;
    }

    std::unique_ptr<CreateIsolatedWorldParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CreateIsolatedWorldParams;
    CreateIsolatedWorldParamsBuilder() : result_(new CreateIsolatedWorldParams()) { }

    template<int STEP> CreateIsolatedWorldParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CreateIsolatedWorldParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CreateIsolatedWorldParams> result_;
  };

  static CreateIsolatedWorldParamsBuilder<0> Builder() {
    return CreateIsolatedWorldParamsBuilder<0>();
  }

 private:
  CreateIsolatedWorldParams() { }

  std::string frame_id_;
  base::Optional<std::string> world_name_;
  base::Optional<bool> grant_univeral_access_;

  DISALLOW_COPY_AND_ASSIGN(CreateIsolatedWorldParams);
};


// Result for the CreateIsolatedWorld command.
class HEADLESS_EXPORT CreateIsolatedWorldResult {
 public:
  static std::unique_ptr<CreateIsolatedWorldResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CreateIsolatedWorldResult() { }

  // Execution context of the isolated world.
  int GetExecutionContextId() const { return execution_context_id_; }
  void SetExecutionContextId(int value) { execution_context_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CreateIsolatedWorldResult> Clone() const;

  template<int STATE>
  class CreateIsolatedWorldResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kExecutionContextIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kExecutionContextIdSet | 0)
    };

    CreateIsolatedWorldResultBuilder<STATE | kExecutionContextIdSet>& SetExecutionContextId(int value) {
      static_assert(!(STATE & kExecutionContextIdSet), "property executionContextId should not have already been set");
      result_->SetExecutionContextId(value);
      return CastState<kExecutionContextIdSet>();
    }

    std::unique_ptr<CreateIsolatedWorldResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CreateIsolatedWorldResult;
    CreateIsolatedWorldResultBuilder() : result_(new CreateIsolatedWorldResult()) { }

    template<int STEP> CreateIsolatedWorldResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CreateIsolatedWorldResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CreateIsolatedWorldResult> result_;
  };

  static CreateIsolatedWorldResultBuilder<0> Builder() {
    return CreateIsolatedWorldResultBuilder<0>();
  }

 private:
  CreateIsolatedWorldResult() { }

  int execution_context_id_;

  DISALLOW_COPY_AND_ASSIGN(CreateIsolatedWorldResult);
};


// Parameters for the DeleteCookie command.
class HEADLESS_EXPORT DeleteCookieParams {
 public:
  static std::unique_ptr<DeleteCookieParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteCookieParams() { }

  // Name of the cookie to remove.
  std::string GetCookieName() const { return cookie_name_; }
  void SetCookieName(const std::string& value) { cookie_name_ = value; }

  // URL to match cooke domain and path.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteCookieParams> Clone() const;

  template<int STATE>
  class DeleteCookieParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCookieNameSet = 1 << 1,
    kUrlSet = 1 << 2,
      kAllRequiredFieldsSet = (kCookieNameSet | kUrlSet | 0)
    };

    DeleteCookieParamsBuilder<STATE | kCookieNameSet>& SetCookieName(const std::string& value) {
      static_assert(!(STATE & kCookieNameSet), "property cookieName should not have already been set");
      result_->SetCookieName(value);
      return CastState<kCookieNameSet>();
    }

    DeleteCookieParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    std::unique_ptr<DeleteCookieParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteCookieParams;
    DeleteCookieParamsBuilder() : result_(new DeleteCookieParams()) { }

    template<int STEP> DeleteCookieParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteCookieParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteCookieParams> result_;
  };

  static DeleteCookieParamsBuilder<0> Builder() {
    return DeleteCookieParamsBuilder<0>();
  }

 private:
  DeleteCookieParams() { }

  std::string cookie_name_;
  std::string url_;

  DISALLOW_COPY_AND_ASSIGN(DeleteCookieParams);
};


// Result for the DeleteCookie command.
class HEADLESS_EXPORT DeleteCookieResult {
 public:
  static std::unique_ptr<DeleteCookieResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DeleteCookieResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DeleteCookieResult> Clone() const;

  template<int STATE>
  class DeleteCookieResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DeleteCookieResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DeleteCookieResult;
    DeleteCookieResultBuilder() : result_(new DeleteCookieResult()) { }

    template<int STEP> DeleteCookieResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DeleteCookieResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DeleteCookieResult> result_;
  };

  static DeleteCookieResultBuilder<0> Builder() {
    return DeleteCookieResultBuilder<0>();
  }

 private:
  DeleteCookieResult() { }


  DISALLOW_COPY_AND_ASSIGN(DeleteCookieResult);
};


// Parameters for the Disable command.
class HEADLESS_EXPORT DisableParams {
 public:
  static std::unique_ptr<DisableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableParams> Clone() const;

  template<int STATE>
  class DisableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableParams;
    DisableParamsBuilder() : result_(new DisableParams()) { }

    template<int STEP> DisableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableParams> result_;
  };

  static DisableParamsBuilder<0> Builder() {
    return DisableParamsBuilder<0>();
  }

 private:
  DisableParams() { }


  DISALLOW_COPY_AND_ASSIGN(DisableParams);
};


// Result for the Disable command.
class HEADLESS_EXPORT DisableResult {
 public:
  static std::unique_ptr<DisableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~DisableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DisableResult> Clone() const;

  template<int STATE>
  class DisableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<DisableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DisableResult;
    DisableResultBuilder() : result_(new DisableResult()) { }

    template<int STEP> DisableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DisableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DisableResult> result_;
  };

  static DisableResultBuilder<0> Builder() {
    return DisableResultBuilder<0>();
  }

 private:
  DisableResult() { }


  DISALLOW_COPY_AND_ASSIGN(DisableResult);
};


// Parameters for the Enable command.
class HEADLESS_EXPORT EnableParams {
 public:
  static std::unique_ptr<EnableParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableParams> Clone() const;

  template<int STATE>
  class EnableParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableParams;
    EnableParamsBuilder() : result_(new EnableParams()) { }

    template<int STEP> EnableParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableParams> result_;
  };

  static EnableParamsBuilder<0> Builder() {
    return EnableParamsBuilder<0>();
  }

 private:
  EnableParams() { }


  DISALLOW_COPY_AND_ASSIGN(EnableParams);
};


// Result for the Enable command.
class HEADLESS_EXPORT EnableResult {
 public:
  static std::unique_ptr<EnableResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EnableResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EnableResult> Clone() const;

  template<int STATE>
  class EnableResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EnableResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EnableResult;
    EnableResultBuilder() : result_(new EnableResult()) { }

    template<int STEP> EnableResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EnableResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EnableResult> result_;
  };

  static EnableResultBuilder<0> Builder() {
    return EnableResultBuilder<0>();
  }

 private:
  EnableResult() { }


  DISALLOW_COPY_AND_ASSIGN(EnableResult);
};


// Parameters for the GetAppManifest command.
class HEADLESS_EXPORT GetAppManifestParams {
 public:
  static std::unique_ptr<GetAppManifestParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAppManifestParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAppManifestParams> Clone() const;

  template<int STATE>
  class GetAppManifestParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetAppManifestParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAppManifestParams;
    GetAppManifestParamsBuilder() : result_(new GetAppManifestParams()) { }

    template<int STEP> GetAppManifestParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAppManifestParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAppManifestParams> result_;
  };

  static GetAppManifestParamsBuilder<0> Builder() {
    return GetAppManifestParamsBuilder<0>();
  }

 private:
  GetAppManifestParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetAppManifestParams);
};


// Result for the GetAppManifest command.
class HEADLESS_EXPORT GetAppManifestResult {
 public:
  static std::unique_ptr<GetAppManifestResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetAppManifestResult() { }

  // Manifest location.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  const std::vector<std::unique_ptr<::headless::page::AppManifestError>>* GetErrors() const { return &errors_; }
  void SetErrors(std::vector<std::unique_ptr<::headless::page::AppManifestError>> value) { errors_ = std::move(value); }

  // Manifest content.
  bool HasData() const { return !!data_; }
  std::string GetData() const { DCHECK(HasData()); return data_.value(); }
  void SetData(const std::string& value) { data_ = value; }

  // Parsed manifest properties
  bool HasParsed() const { return !!parsed_; }
  const ::headless::page::AppManifestParsedProperties* GetParsed() const { DCHECK(HasParsed()); return parsed_.value().get(); }
  void SetParsed(std::unique_ptr<::headless::page::AppManifestParsedProperties> value) { parsed_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetAppManifestResult> Clone() const;

  template<int STATE>
  class GetAppManifestResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kErrorsSet = 1 << 2,
      kAllRequiredFieldsSet = (kUrlSet | kErrorsSet | 0)
    };

    GetAppManifestResultBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    GetAppManifestResultBuilder<STATE | kErrorsSet>& SetErrors(std::vector<std::unique_ptr<::headless::page::AppManifestError>> value) {
      static_assert(!(STATE & kErrorsSet), "property errors should not have already been set");
      result_->SetErrors(std::move(value));
      return CastState<kErrorsSet>();
    }

    GetAppManifestResultBuilder<STATE>& SetData(const std::string& value) {
      result_->SetData(value);
      return *this;
    }

    GetAppManifestResultBuilder<STATE>& SetParsed(std::unique_ptr<::headless::page::AppManifestParsedProperties> value) {
      result_->SetParsed(std::move(value));
      return *this;
    }

    std::unique_ptr<GetAppManifestResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetAppManifestResult;
    GetAppManifestResultBuilder() : result_(new GetAppManifestResult()) { }

    template<int STEP> GetAppManifestResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetAppManifestResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetAppManifestResult> result_;
  };

  static GetAppManifestResultBuilder<0> Builder() {
    return GetAppManifestResultBuilder<0>();
  }

 private:
  GetAppManifestResult() { }

  std::string url_;
  std::vector<std::unique_ptr<::headless::page::AppManifestError>> errors_;
  base::Optional<std::string> data_;
  base::Optional<std::unique_ptr<::headless::page::AppManifestParsedProperties>> parsed_;

  DISALLOW_COPY_AND_ASSIGN(GetAppManifestResult);
};


// Parameters for the GetInstallabilityErrors command.
class HEADLESS_EXPORT GetInstallabilityErrorsParams {
 public:
  static std::unique_ptr<GetInstallabilityErrorsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetInstallabilityErrorsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetInstallabilityErrorsParams> Clone() const;

  template<int STATE>
  class GetInstallabilityErrorsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetInstallabilityErrorsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetInstallabilityErrorsParams;
    GetInstallabilityErrorsParamsBuilder() : result_(new GetInstallabilityErrorsParams()) { }

    template<int STEP> GetInstallabilityErrorsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetInstallabilityErrorsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetInstallabilityErrorsParams> result_;
  };

  static GetInstallabilityErrorsParamsBuilder<0> Builder() {
    return GetInstallabilityErrorsParamsBuilder<0>();
  }

 private:
  GetInstallabilityErrorsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetInstallabilityErrorsParams);
};


// Result for the GetInstallabilityErrors command.
class HEADLESS_EXPORT GetInstallabilityErrorsResult {
 public:
  static std::unique_ptr<GetInstallabilityErrorsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetInstallabilityErrorsResult() { }

  const std::vector<std::unique_ptr<::headless::page::InstallabilityError>>* GetInstallabilityErrors() const { return &installability_errors_; }
  void SetInstallabilityErrors(std::vector<std::unique_ptr<::headless::page::InstallabilityError>> value) { installability_errors_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetInstallabilityErrorsResult> Clone() const;

  template<int STATE>
  class GetInstallabilityErrorsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kInstallabilityErrorsSet = 1 << 1,
      kAllRequiredFieldsSet = (kInstallabilityErrorsSet | 0)
    };

    GetInstallabilityErrorsResultBuilder<STATE | kInstallabilityErrorsSet>& SetInstallabilityErrors(std::vector<std::unique_ptr<::headless::page::InstallabilityError>> value) {
      static_assert(!(STATE & kInstallabilityErrorsSet), "property installabilityErrors should not have already been set");
      result_->SetInstallabilityErrors(std::move(value));
      return CastState<kInstallabilityErrorsSet>();
    }

    std::unique_ptr<GetInstallabilityErrorsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetInstallabilityErrorsResult;
    GetInstallabilityErrorsResultBuilder() : result_(new GetInstallabilityErrorsResult()) { }

    template<int STEP> GetInstallabilityErrorsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetInstallabilityErrorsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetInstallabilityErrorsResult> result_;
  };

  static GetInstallabilityErrorsResultBuilder<0> Builder() {
    return GetInstallabilityErrorsResultBuilder<0>();
  }

 private:
  GetInstallabilityErrorsResult() { }

  std::vector<std::unique_ptr<::headless::page::InstallabilityError>> installability_errors_;

  DISALLOW_COPY_AND_ASSIGN(GetInstallabilityErrorsResult);
};


// Parameters for the GetManifestIcons command.
class HEADLESS_EXPORT GetManifestIconsParams {
 public:
  static std::unique_ptr<GetManifestIconsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetManifestIconsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetManifestIconsParams> Clone() const;

  template<int STATE>
  class GetManifestIconsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetManifestIconsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetManifestIconsParams;
    GetManifestIconsParamsBuilder() : result_(new GetManifestIconsParams()) { }

    template<int STEP> GetManifestIconsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetManifestIconsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetManifestIconsParams> result_;
  };

  static GetManifestIconsParamsBuilder<0> Builder() {
    return GetManifestIconsParamsBuilder<0>();
  }

 private:
  GetManifestIconsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetManifestIconsParams);
};


// Result for the GetManifestIcons command.
class HEADLESS_EXPORT GetManifestIconsResult {
 public:
  static std::unique_ptr<GetManifestIconsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetManifestIconsResult() { }

  bool HasPrimaryIcon() const { return !!primary_icon_; }
  protocol::Binary GetPrimaryIcon() const { DCHECK(HasPrimaryIcon()); return primary_icon_.value(); }
  void SetPrimaryIcon(const protocol::Binary& value) { primary_icon_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetManifestIconsResult> Clone() const;

  template<int STATE>
  class GetManifestIconsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    GetManifestIconsResultBuilder<STATE>& SetPrimaryIcon(const protocol::Binary& value) {
      result_->SetPrimaryIcon(value);
      return *this;
    }

    std::unique_ptr<GetManifestIconsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetManifestIconsResult;
    GetManifestIconsResultBuilder() : result_(new GetManifestIconsResult()) { }

    template<int STEP> GetManifestIconsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetManifestIconsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetManifestIconsResult> result_;
  };

  static GetManifestIconsResultBuilder<0> Builder() {
    return GetManifestIconsResultBuilder<0>();
  }

 private:
  GetManifestIconsResult() { }

  base::Optional<protocol::Binary> primary_icon_;

  DISALLOW_COPY_AND_ASSIGN(GetManifestIconsResult);
};


// Parameters for the GetCookies command.
class HEADLESS_EXPORT GetCookiesParams {
 public:
  static std::unique_ptr<GetCookiesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCookiesParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCookiesParams> Clone() const;

  template<int STATE>
  class GetCookiesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetCookiesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCookiesParams;
    GetCookiesParamsBuilder() : result_(new GetCookiesParams()) { }

    template<int STEP> GetCookiesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCookiesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCookiesParams> result_;
  };

  static GetCookiesParamsBuilder<0> Builder() {
    return GetCookiesParamsBuilder<0>();
  }

 private:
  GetCookiesParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetCookiesParams);
};


// Result for the GetCookies command.
class HEADLESS_EXPORT GetCookiesResult {
 public:
  static std::unique_ptr<GetCookiesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCookiesResult() { }

  // Array of cookie objects.
  const std::vector<std::unique_ptr<::headless::network::Cookie>>* GetCookies() const { return &cookies_; }
  void SetCookies(std::vector<std::unique_ptr<::headless::network::Cookie>> value) { cookies_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCookiesResult> Clone() const;

  template<int STATE>
  class GetCookiesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCookiesSet = 1 << 1,
      kAllRequiredFieldsSet = (kCookiesSet | 0)
    };

    GetCookiesResultBuilder<STATE | kCookiesSet>& SetCookies(std::vector<std::unique_ptr<::headless::network::Cookie>> value) {
      static_assert(!(STATE & kCookiesSet), "property cookies should not have already been set");
      result_->SetCookies(std::move(value));
      return CastState<kCookiesSet>();
    }

    std::unique_ptr<GetCookiesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCookiesResult;
    GetCookiesResultBuilder() : result_(new GetCookiesResult()) { }

    template<int STEP> GetCookiesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCookiesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCookiesResult> result_;
  };

  static GetCookiesResultBuilder<0> Builder() {
    return GetCookiesResultBuilder<0>();
  }

 private:
  GetCookiesResult() { }

  std::vector<std::unique_ptr<::headless::network::Cookie>> cookies_;

  DISALLOW_COPY_AND_ASSIGN(GetCookiesResult);
};


// Parameters for the GetFrameTree command.
class HEADLESS_EXPORT GetFrameTreeParams {
 public:
  static std::unique_ptr<GetFrameTreeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFrameTreeParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFrameTreeParams> Clone() const;

  template<int STATE>
  class GetFrameTreeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetFrameTreeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFrameTreeParams;
    GetFrameTreeParamsBuilder() : result_(new GetFrameTreeParams()) { }

    template<int STEP> GetFrameTreeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFrameTreeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFrameTreeParams> result_;
  };

  static GetFrameTreeParamsBuilder<0> Builder() {
    return GetFrameTreeParamsBuilder<0>();
  }

 private:
  GetFrameTreeParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetFrameTreeParams);
};


// Result for the GetFrameTree command.
class HEADLESS_EXPORT GetFrameTreeResult {
 public:
  static std::unique_ptr<GetFrameTreeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFrameTreeResult() { }

  // Present frame tree structure.
  const ::headless::page::FrameTree* GetFrameTree() const { return frame_tree_.get(); }
  void SetFrameTree(std::unique_ptr<::headless::page::FrameTree> value) { frame_tree_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFrameTreeResult> Clone() const;

  template<int STATE>
  class GetFrameTreeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameTreeSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameTreeSet | 0)
    };

    GetFrameTreeResultBuilder<STATE | kFrameTreeSet>& SetFrameTree(std::unique_ptr<::headless::page::FrameTree> value) {
      static_assert(!(STATE & kFrameTreeSet), "property frameTree should not have already been set");
      result_->SetFrameTree(std::move(value));
      return CastState<kFrameTreeSet>();
    }

    std::unique_ptr<GetFrameTreeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFrameTreeResult;
    GetFrameTreeResultBuilder() : result_(new GetFrameTreeResult()) { }

    template<int STEP> GetFrameTreeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFrameTreeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFrameTreeResult> result_;
  };

  static GetFrameTreeResultBuilder<0> Builder() {
    return GetFrameTreeResultBuilder<0>();
  }

 private:
  GetFrameTreeResult() { }

  std::unique_ptr<::headless::page::FrameTree> frame_tree_;

  DISALLOW_COPY_AND_ASSIGN(GetFrameTreeResult);
};


// Parameters for the GetLayoutMetrics command.
class HEADLESS_EXPORT GetLayoutMetricsParams {
 public:
  static std::unique_ptr<GetLayoutMetricsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetLayoutMetricsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetLayoutMetricsParams> Clone() const;

  template<int STATE>
  class GetLayoutMetricsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetLayoutMetricsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetLayoutMetricsParams;
    GetLayoutMetricsParamsBuilder() : result_(new GetLayoutMetricsParams()) { }

    template<int STEP> GetLayoutMetricsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetLayoutMetricsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetLayoutMetricsParams> result_;
  };

  static GetLayoutMetricsParamsBuilder<0> Builder() {
    return GetLayoutMetricsParamsBuilder<0>();
  }

 private:
  GetLayoutMetricsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetLayoutMetricsParams);
};


// Result for the GetLayoutMetrics command.
class HEADLESS_EXPORT GetLayoutMetricsResult {
 public:
  static std::unique_ptr<GetLayoutMetricsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetLayoutMetricsResult() { }

  // Metrics relating to the layout viewport.
  const ::headless::page::LayoutViewport* GetLayoutViewport() const { return layout_viewport_.get(); }
  void SetLayoutViewport(std::unique_ptr<::headless::page::LayoutViewport> value) { layout_viewport_ = std::move(value); }

  // Metrics relating to the visual viewport.
  const ::headless::page::VisualViewport* GetVisualViewport() const { return visual_viewport_.get(); }
  void SetVisualViewport(std::unique_ptr<::headless::page::VisualViewport> value) { visual_viewport_ = std::move(value); }

  // Size of scrollable area.
  const ::headless::dom::Rect* GetContentSize() const { return content_size_.get(); }
  void SetContentSize(std::unique_ptr<::headless::dom::Rect> value) { content_size_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetLayoutMetricsResult> Clone() const;

  template<int STATE>
  class GetLayoutMetricsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kLayoutViewportSet = 1 << 1,
    kVisualViewportSet = 1 << 2,
    kContentSizeSet = 1 << 3,
      kAllRequiredFieldsSet = (kLayoutViewportSet | kVisualViewportSet | kContentSizeSet | 0)
    };

    GetLayoutMetricsResultBuilder<STATE | kLayoutViewportSet>& SetLayoutViewport(std::unique_ptr<::headless::page::LayoutViewport> value) {
      static_assert(!(STATE & kLayoutViewportSet), "property layoutViewport should not have already been set");
      result_->SetLayoutViewport(std::move(value));
      return CastState<kLayoutViewportSet>();
    }

    GetLayoutMetricsResultBuilder<STATE | kVisualViewportSet>& SetVisualViewport(std::unique_ptr<::headless::page::VisualViewport> value) {
      static_assert(!(STATE & kVisualViewportSet), "property visualViewport should not have already been set");
      result_->SetVisualViewport(std::move(value));
      return CastState<kVisualViewportSet>();
    }

    GetLayoutMetricsResultBuilder<STATE | kContentSizeSet>& SetContentSize(std::unique_ptr<::headless::dom::Rect> value) {
      static_assert(!(STATE & kContentSizeSet), "property contentSize should not have already been set");
      result_->SetContentSize(std::move(value));
      return CastState<kContentSizeSet>();
    }

    std::unique_ptr<GetLayoutMetricsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetLayoutMetricsResult;
    GetLayoutMetricsResultBuilder() : result_(new GetLayoutMetricsResult()) { }

    template<int STEP> GetLayoutMetricsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetLayoutMetricsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetLayoutMetricsResult> result_;
  };

  static GetLayoutMetricsResultBuilder<0> Builder() {
    return GetLayoutMetricsResultBuilder<0>();
  }

 private:
  GetLayoutMetricsResult() { }

  std::unique_ptr<::headless::page::LayoutViewport> layout_viewport_;
  std::unique_ptr<::headless::page::VisualViewport> visual_viewport_;
  std::unique_ptr<::headless::dom::Rect> content_size_;

  DISALLOW_COPY_AND_ASSIGN(GetLayoutMetricsResult);
};


// Parameters for the GetNavigationHistory command.
class HEADLESS_EXPORT GetNavigationHistoryParams {
 public:
  static std::unique_ptr<GetNavigationHistoryParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetNavigationHistoryParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetNavigationHistoryParams> Clone() const;

  template<int STATE>
  class GetNavigationHistoryParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetNavigationHistoryParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetNavigationHistoryParams;
    GetNavigationHistoryParamsBuilder() : result_(new GetNavigationHistoryParams()) { }

    template<int STEP> GetNavigationHistoryParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetNavigationHistoryParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetNavigationHistoryParams> result_;
  };

  static GetNavigationHistoryParamsBuilder<0> Builder() {
    return GetNavigationHistoryParamsBuilder<0>();
  }

 private:
  GetNavigationHistoryParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetNavigationHistoryParams);
};


// Result for the GetNavigationHistory command.
class HEADLESS_EXPORT GetNavigationHistoryResult {
 public:
  static std::unique_ptr<GetNavigationHistoryResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetNavigationHistoryResult() { }

  // Index of the current navigation history entry.
  int GetCurrentIndex() const { return current_index_; }
  void SetCurrentIndex(int value) { current_index_ = value; }

  // Array of navigation history entries.
  const std::vector<std::unique_ptr<::headless::page::NavigationEntry>>* GetEntries() const { return &entries_; }
  void SetEntries(std::vector<std::unique_ptr<::headless::page::NavigationEntry>> value) { entries_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetNavigationHistoryResult> Clone() const;

  template<int STATE>
  class GetNavigationHistoryResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCurrentIndexSet = 1 << 1,
    kEntriesSet = 1 << 2,
      kAllRequiredFieldsSet = (kCurrentIndexSet | kEntriesSet | 0)
    };

    GetNavigationHistoryResultBuilder<STATE | kCurrentIndexSet>& SetCurrentIndex(int value) {
      static_assert(!(STATE & kCurrentIndexSet), "property currentIndex should not have already been set");
      result_->SetCurrentIndex(value);
      return CastState<kCurrentIndexSet>();
    }

    GetNavigationHistoryResultBuilder<STATE | kEntriesSet>& SetEntries(std::vector<std::unique_ptr<::headless::page::NavigationEntry>> value) {
      static_assert(!(STATE & kEntriesSet), "property entries should not have already been set");
      result_->SetEntries(std::move(value));
      return CastState<kEntriesSet>();
    }

    std::unique_ptr<GetNavigationHistoryResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetNavigationHistoryResult;
    GetNavigationHistoryResultBuilder() : result_(new GetNavigationHistoryResult()) { }

    template<int STEP> GetNavigationHistoryResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetNavigationHistoryResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetNavigationHistoryResult> result_;
  };

  static GetNavigationHistoryResultBuilder<0> Builder() {
    return GetNavigationHistoryResultBuilder<0>();
  }

 private:
  GetNavigationHistoryResult() { }

  int current_index_;
  std::vector<std::unique_ptr<::headless::page::NavigationEntry>> entries_;

  DISALLOW_COPY_AND_ASSIGN(GetNavigationHistoryResult);
};


// Parameters for the ResetNavigationHistory command.
class HEADLESS_EXPORT ResetNavigationHistoryParams {
 public:
  static std::unique_ptr<ResetNavigationHistoryParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResetNavigationHistoryParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResetNavigationHistoryParams> Clone() const;

  template<int STATE>
  class ResetNavigationHistoryParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ResetNavigationHistoryParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResetNavigationHistoryParams;
    ResetNavigationHistoryParamsBuilder() : result_(new ResetNavigationHistoryParams()) { }

    template<int STEP> ResetNavigationHistoryParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResetNavigationHistoryParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResetNavigationHistoryParams> result_;
  };

  static ResetNavigationHistoryParamsBuilder<0> Builder() {
    return ResetNavigationHistoryParamsBuilder<0>();
  }

 private:
  ResetNavigationHistoryParams() { }


  DISALLOW_COPY_AND_ASSIGN(ResetNavigationHistoryParams);
};


// Result for the ResetNavigationHistory command.
class HEADLESS_EXPORT ResetNavigationHistoryResult {
 public:
  static std::unique_ptr<ResetNavigationHistoryResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ResetNavigationHistoryResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ResetNavigationHistoryResult> Clone() const;

  template<int STATE>
  class ResetNavigationHistoryResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ResetNavigationHistoryResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ResetNavigationHistoryResult;
    ResetNavigationHistoryResultBuilder() : result_(new ResetNavigationHistoryResult()) { }

    template<int STEP> ResetNavigationHistoryResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ResetNavigationHistoryResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ResetNavigationHistoryResult> result_;
  };

  static ResetNavigationHistoryResultBuilder<0> Builder() {
    return ResetNavigationHistoryResultBuilder<0>();
  }

 private:
  ResetNavigationHistoryResult() { }


  DISALLOW_COPY_AND_ASSIGN(ResetNavigationHistoryResult);
};


// Parameters for the GetResourceContent command.
class HEADLESS_EXPORT GetResourceContentParams {
 public:
  static std::unique_ptr<GetResourceContentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResourceContentParams() { }

  // Frame id to get resource for.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // URL of the resource to get content for.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResourceContentParams> Clone() const;

  template<int STATE>
  class GetResourceContentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kUrlSet = 1 << 2,
      kAllRequiredFieldsSet = (kFrameIdSet | kUrlSet | 0)
    };

    GetResourceContentParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    GetResourceContentParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    std::unique_ptr<GetResourceContentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResourceContentParams;
    GetResourceContentParamsBuilder() : result_(new GetResourceContentParams()) { }

    template<int STEP> GetResourceContentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResourceContentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResourceContentParams> result_;
  };

  static GetResourceContentParamsBuilder<0> Builder() {
    return GetResourceContentParamsBuilder<0>();
  }

 private:
  GetResourceContentParams() { }

  std::string frame_id_;
  std::string url_;

  DISALLOW_COPY_AND_ASSIGN(GetResourceContentParams);
};


// Result for the GetResourceContent command.
class HEADLESS_EXPORT GetResourceContentResult {
 public:
  static std::unique_ptr<GetResourceContentResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResourceContentResult() { }

  // Resource content.
  std::string GetContent() const { return content_; }
  void SetContent(const std::string& value) { content_ = value; }

  // True, if content was served as base64.
  bool GetBase64Encoded() const { return base64_encoded_; }
  void SetBase64Encoded(bool value) { base64_encoded_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResourceContentResult> Clone() const;

  template<int STATE>
  class GetResourceContentResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kContentSet = 1 << 1,
    kBase64EncodedSet = 1 << 2,
      kAllRequiredFieldsSet = (kContentSet | kBase64EncodedSet | 0)
    };

    GetResourceContentResultBuilder<STATE | kContentSet>& SetContent(const std::string& value) {
      static_assert(!(STATE & kContentSet), "property content should not have already been set");
      result_->SetContent(value);
      return CastState<kContentSet>();
    }

    GetResourceContentResultBuilder<STATE | kBase64EncodedSet>& SetBase64Encoded(bool value) {
      static_assert(!(STATE & kBase64EncodedSet), "property base64Encoded should not have already been set");
      result_->SetBase64Encoded(value);
      return CastState<kBase64EncodedSet>();
    }

    std::unique_ptr<GetResourceContentResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResourceContentResult;
    GetResourceContentResultBuilder() : result_(new GetResourceContentResult()) { }

    template<int STEP> GetResourceContentResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResourceContentResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResourceContentResult> result_;
  };

  static GetResourceContentResultBuilder<0> Builder() {
    return GetResourceContentResultBuilder<0>();
  }

 private:
  GetResourceContentResult() { }

  std::string content_;
  bool base64_encoded_;

  DISALLOW_COPY_AND_ASSIGN(GetResourceContentResult);
};


// Parameters for the GetResourceTree command.
class HEADLESS_EXPORT GetResourceTreeParams {
 public:
  static std::unique_ptr<GetResourceTreeParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResourceTreeParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResourceTreeParams> Clone() const;

  template<int STATE>
  class GetResourceTreeParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetResourceTreeParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResourceTreeParams;
    GetResourceTreeParamsBuilder() : result_(new GetResourceTreeParams()) { }

    template<int STEP> GetResourceTreeParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResourceTreeParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResourceTreeParams> result_;
  };

  static GetResourceTreeParamsBuilder<0> Builder() {
    return GetResourceTreeParamsBuilder<0>();
  }

 private:
  GetResourceTreeParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetResourceTreeParams);
};


// Result for the GetResourceTree command.
class HEADLESS_EXPORT GetResourceTreeResult {
 public:
  static std::unique_ptr<GetResourceTreeResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetResourceTreeResult() { }

  // Present frame / resource tree structure.
  const ::headless::page::FrameResourceTree* GetFrameTree() const { return frame_tree_.get(); }
  void SetFrameTree(std::unique_ptr<::headless::page::FrameResourceTree> value) { frame_tree_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetResourceTreeResult> Clone() const;

  template<int STATE>
  class GetResourceTreeResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameTreeSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameTreeSet | 0)
    };

    GetResourceTreeResultBuilder<STATE | kFrameTreeSet>& SetFrameTree(std::unique_ptr<::headless::page::FrameResourceTree> value) {
      static_assert(!(STATE & kFrameTreeSet), "property frameTree should not have already been set");
      result_->SetFrameTree(std::move(value));
      return CastState<kFrameTreeSet>();
    }

    std::unique_ptr<GetResourceTreeResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetResourceTreeResult;
    GetResourceTreeResultBuilder() : result_(new GetResourceTreeResult()) { }

    template<int STEP> GetResourceTreeResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetResourceTreeResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetResourceTreeResult> result_;
  };

  static GetResourceTreeResultBuilder<0> Builder() {
    return GetResourceTreeResultBuilder<0>();
  }

 private:
  GetResourceTreeResult() { }

  std::unique_ptr<::headless::page::FrameResourceTree> frame_tree_;

  DISALLOW_COPY_AND_ASSIGN(GetResourceTreeResult);
};


// Parameters for the HandleJavaScriptDialog command.
class HEADLESS_EXPORT HandleJavaScriptDialogParams {
 public:
  static std::unique_ptr<HandleJavaScriptDialogParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~HandleJavaScriptDialogParams() { }

  // Whether to accept or dismiss the dialog.
  bool GetAccept() const { return accept_; }
  void SetAccept(bool value) { accept_ = value; }

  // The text to enter into the dialog prompt before accepting. Used only if this is a prompt
  // dialog.
  bool HasPromptText() const { return !!prompt_text_; }
  std::string GetPromptText() const { DCHECK(HasPromptText()); return prompt_text_.value(); }
  void SetPromptText(const std::string& value) { prompt_text_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HandleJavaScriptDialogParams> Clone() const;

  template<int STATE>
  class HandleJavaScriptDialogParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAcceptSet = 1 << 1,
      kAllRequiredFieldsSet = (kAcceptSet | 0)
    };

    HandleJavaScriptDialogParamsBuilder<STATE | kAcceptSet>& SetAccept(bool value) {
      static_assert(!(STATE & kAcceptSet), "property accept should not have already been set");
      result_->SetAccept(value);
      return CastState<kAcceptSet>();
    }

    HandleJavaScriptDialogParamsBuilder<STATE>& SetPromptText(const std::string& value) {
      result_->SetPromptText(value);
      return *this;
    }

    std::unique_ptr<HandleJavaScriptDialogParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HandleJavaScriptDialogParams;
    HandleJavaScriptDialogParamsBuilder() : result_(new HandleJavaScriptDialogParams()) { }

    template<int STEP> HandleJavaScriptDialogParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HandleJavaScriptDialogParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HandleJavaScriptDialogParams> result_;
  };

  static HandleJavaScriptDialogParamsBuilder<0> Builder() {
    return HandleJavaScriptDialogParamsBuilder<0>();
  }

 private:
  HandleJavaScriptDialogParams() { }

  bool accept_;
  base::Optional<std::string> prompt_text_;

  DISALLOW_COPY_AND_ASSIGN(HandleJavaScriptDialogParams);
};


// Result for the HandleJavaScriptDialog command.
class HEADLESS_EXPORT HandleJavaScriptDialogResult {
 public:
  static std::unique_ptr<HandleJavaScriptDialogResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~HandleJavaScriptDialogResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<HandleJavaScriptDialogResult> Clone() const;

  template<int STATE>
  class HandleJavaScriptDialogResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<HandleJavaScriptDialogResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class HandleJavaScriptDialogResult;
    HandleJavaScriptDialogResultBuilder() : result_(new HandleJavaScriptDialogResult()) { }

    template<int STEP> HandleJavaScriptDialogResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<HandleJavaScriptDialogResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<HandleJavaScriptDialogResult> result_;
  };

  static HandleJavaScriptDialogResultBuilder<0> Builder() {
    return HandleJavaScriptDialogResultBuilder<0>();
  }

 private:
  HandleJavaScriptDialogResult() { }


  DISALLOW_COPY_AND_ASSIGN(HandleJavaScriptDialogResult);
};


// Parameters for the Navigate command.
class HEADLESS_EXPORT NavigateParams {
 public:
  static std::unique_ptr<NavigateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NavigateParams() { }

  // URL to navigate the page to.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Referrer URL.
  bool HasReferrer() const { return !!referrer_; }
  std::string GetReferrer() const { DCHECK(HasReferrer()); return referrer_.value(); }
  void SetReferrer(const std::string& value) { referrer_ = value; }

  // Intended transition type.
  bool HasTransitionType() const { return !!transition_type_; }
  ::headless::page::TransitionType GetTransitionType() const { DCHECK(HasTransitionType()); return transition_type_.value(); }
  void SetTransitionType(::headless::page::TransitionType value) { transition_type_ = value; }

  // Frame id to navigate, if not specified navigates the top frame.
  bool HasFrameId() const { return !!frame_id_; }
  std::string GetFrameId() const { DCHECK(HasFrameId()); return frame_id_.value(); }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Referrer-policy used for the navigation.
  bool HasReferrerPolicy() const { return !!referrer_policy_; }
  ::headless::page::ReferrerPolicy GetReferrerPolicy() const { DCHECK(HasReferrerPolicy()); return referrer_policy_.value(); }
  void SetReferrerPolicy(::headless::page::ReferrerPolicy value) { referrer_policy_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NavigateParams> Clone() const;

  template<int STATE>
  class NavigateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
      kAllRequiredFieldsSet = (kUrlSet | 0)
    };

    NavigateParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    NavigateParamsBuilder<STATE>& SetReferrer(const std::string& value) {
      result_->SetReferrer(value);
      return *this;
    }

    NavigateParamsBuilder<STATE>& SetTransitionType(::headless::page::TransitionType value) {
      result_->SetTransitionType(value);
      return *this;
    }

    NavigateParamsBuilder<STATE>& SetFrameId(const std::string& value) {
      result_->SetFrameId(value);
      return *this;
    }

    NavigateParamsBuilder<STATE>& SetReferrerPolicy(::headless::page::ReferrerPolicy value) {
      result_->SetReferrerPolicy(value);
      return *this;
    }

    std::unique_ptr<NavigateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NavigateParams;
    NavigateParamsBuilder() : result_(new NavigateParams()) { }

    template<int STEP> NavigateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NavigateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NavigateParams> result_;
  };

  static NavigateParamsBuilder<0> Builder() {
    return NavigateParamsBuilder<0>();
  }

 private:
  NavigateParams() { }

  std::string url_;
  base::Optional<std::string> referrer_;
  base::Optional<::headless::page::TransitionType> transition_type_;
  base::Optional<std::string> frame_id_;
  base::Optional<::headless::page::ReferrerPolicy> referrer_policy_;

  DISALLOW_COPY_AND_ASSIGN(NavigateParams);
};


// Result for the Navigate command.
class HEADLESS_EXPORT NavigateResult {
 public:
  static std::unique_ptr<NavigateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~NavigateResult() { }

  // Frame id that has navigated (or failed to navigate)
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Loader identifier.
  bool HasLoaderId() const { return !!loader_id_; }
  std::string GetLoaderId() const { DCHECK(HasLoaderId()); return loader_id_.value(); }
  void SetLoaderId(const std::string& value) { loader_id_ = value; }

  // User friendly error message, present if and only if navigation has failed.
  bool HasErrorText() const { return !!error_text_; }
  std::string GetErrorText() const { DCHECK(HasErrorText()); return error_text_.value(); }
  void SetErrorText(const std::string& value) { error_text_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NavigateResult> Clone() const;

  template<int STATE>
  class NavigateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    NavigateResultBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    NavigateResultBuilder<STATE>& SetLoaderId(const std::string& value) {
      result_->SetLoaderId(value);
      return *this;
    }

    NavigateResultBuilder<STATE>& SetErrorText(const std::string& value) {
      result_->SetErrorText(value);
      return *this;
    }

    std::unique_ptr<NavigateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NavigateResult;
    NavigateResultBuilder() : result_(new NavigateResult()) { }

    template<int STEP> NavigateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NavigateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NavigateResult> result_;
  };

  static NavigateResultBuilder<0> Builder() {
    return NavigateResultBuilder<0>();
  }

 private:
  NavigateResult() { }

  std::string frame_id_;
  base::Optional<std::string> loader_id_;
  base::Optional<std::string> error_text_;

  DISALLOW_COPY_AND_ASSIGN(NavigateResult);
};


// Parameters for the NavigateToHistoryEntry command.
class HEADLESS_EXPORT NavigateToHistoryEntryParams {
 public:
  static std::unique_ptr<NavigateToHistoryEntryParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NavigateToHistoryEntryParams() { }

  // Unique id of the entry to navigate to.
  int GetEntryId() const { return entry_id_; }
  void SetEntryId(int value) { entry_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NavigateToHistoryEntryParams> Clone() const;

  template<int STATE>
  class NavigateToHistoryEntryParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEntryIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kEntryIdSet | 0)
    };

    NavigateToHistoryEntryParamsBuilder<STATE | kEntryIdSet>& SetEntryId(int value) {
      static_assert(!(STATE & kEntryIdSet), "property entryId should not have already been set");
      result_->SetEntryId(value);
      return CastState<kEntryIdSet>();
    }

    std::unique_ptr<NavigateToHistoryEntryParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NavigateToHistoryEntryParams;
    NavigateToHistoryEntryParamsBuilder() : result_(new NavigateToHistoryEntryParams()) { }

    template<int STEP> NavigateToHistoryEntryParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NavigateToHistoryEntryParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NavigateToHistoryEntryParams> result_;
  };

  static NavigateToHistoryEntryParamsBuilder<0> Builder() {
    return NavigateToHistoryEntryParamsBuilder<0>();
  }

 private:
  NavigateToHistoryEntryParams() { }

  int entry_id_;

  DISALLOW_COPY_AND_ASSIGN(NavigateToHistoryEntryParams);
};


// Result for the NavigateToHistoryEntry command.
class HEADLESS_EXPORT NavigateToHistoryEntryResult {
 public:
  static std::unique_ptr<NavigateToHistoryEntryResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~NavigateToHistoryEntryResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NavigateToHistoryEntryResult> Clone() const;

  template<int STATE>
  class NavigateToHistoryEntryResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<NavigateToHistoryEntryResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NavigateToHistoryEntryResult;
    NavigateToHistoryEntryResultBuilder() : result_(new NavigateToHistoryEntryResult()) { }

    template<int STEP> NavigateToHistoryEntryResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NavigateToHistoryEntryResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NavigateToHistoryEntryResult> result_;
  };

  static NavigateToHistoryEntryResultBuilder<0> Builder() {
    return NavigateToHistoryEntryResultBuilder<0>();
  }

 private:
  NavigateToHistoryEntryResult() { }


  DISALLOW_COPY_AND_ASSIGN(NavigateToHistoryEntryResult);
};


// Parameters for the PrintToPDF command.
class HEADLESS_EXPORT PrintToPDFParams {
 public:
  static std::unique_ptr<PrintToPDFParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~PrintToPDFParams() { }

  // Paper orientation. Defaults to false.
  bool HasLandscape() const { return !!landscape_; }
  bool GetLandscape() const { DCHECK(HasLandscape()); return landscape_.value(); }
  void SetLandscape(bool value) { landscape_ = value; }

  // Display header and footer. Defaults to false.
  bool HasDisplayHeaderFooter() const { return !!display_header_footer_; }
  bool GetDisplayHeaderFooter() const { DCHECK(HasDisplayHeaderFooter()); return display_header_footer_.value(); }
  void SetDisplayHeaderFooter(bool value) { display_header_footer_ = value; }

  // Print background graphics. Defaults to false.
  bool HasPrintBackground() const { return !!print_background_; }
  bool GetPrintBackground() const { DCHECK(HasPrintBackground()); return print_background_.value(); }
  void SetPrintBackground(bool value) { print_background_ = value; }

  // Scale of the webpage rendering. Defaults to 1.
  bool HasScale() const { return !!scale_; }
  double GetScale() const { DCHECK(HasScale()); return scale_.value(); }
  void SetScale(double value) { scale_ = value; }

  // Paper width in inches. Defaults to 8.5 inches.
  bool HasPaperWidth() const { return !!paper_width_; }
  double GetPaperWidth() const { DCHECK(HasPaperWidth()); return paper_width_.value(); }
  void SetPaperWidth(double value) { paper_width_ = value; }

  // Paper height in inches. Defaults to 11 inches.
  bool HasPaperHeight() const { return !!paper_height_; }
  double GetPaperHeight() const { DCHECK(HasPaperHeight()); return paper_height_.value(); }
  void SetPaperHeight(double value) { paper_height_ = value; }

  // Top margin in inches. Defaults to 1cm (~0.4 inches).
  bool HasMarginTop() const { return !!margin_top_; }
  double GetMarginTop() const { DCHECK(HasMarginTop()); return margin_top_.value(); }
  void SetMarginTop(double value) { margin_top_ = value; }

  // Bottom margin in inches. Defaults to 1cm (~0.4 inches).
  bool HasMarginBottom() const { return !!margin_bottom_; }
  double GetMarginBottom() const { DCHECK(HasMarginBottom()); return margin_bottom_.value(); }
  void SetMarginBottom(double value) { margin_bottom_ = value; }

  // Left margin in inches. Defaults to 1cm (~0.4 inches).
  bool HasMarginLeft() const { return !!margin_left_; }
  double GetMarginLeft() const { DCHECK(HasMarginLeft()); return margin_left_.value(); }
  void SetMarginLeft(double value) { margin_left_ = value; }

  // Right margin in inches. Defaults to 1cm (~0.4 inches).
  bool HasMarginRight() const { return !!margin_right_; }
  double GetMarginRight() const { DCHECK(HasMarginRight()); return margin_right_.value(); }
  void SetMarginRight(double value) { margin_right_ = value; }

  // Paper ranges to print, e.g., '1-5, 8, 11-13'. Defaults to the empty string, which means
  // print all pages.
  bool HasPageRanges() const { return !!page_ranges_; }
  std::string GetPageRanges() const { DCHECK(HasPageRanges()); return page_ranges_.value(); }
  void SetPageRanges(const std::string& value) { page_ranges_ = value; }

  // Whether to silently ignore invalid but successfully parsed page ranges, such as '3-2'.
  // Defaults to false.
  bool HasIgnoreInvalidPageRanges() const { return !!ignore_invalid_page_ranges_; }
  bool GetIgnoreInvalidPageRanges() const { DCHECK(HasIgnoreInvalidPageRanges()); return ignore_invalid_page_ranges_.value(); }
  void SetIgnoreInvalidPageRanges(bool value) { ignore_invalid_page_ranges_ = value; }

  // HTML template for the print header. Should be valid HTML markup with following
  // classes used to inject printing values into them:
  // - `date`: formatted print date
  // - `title`: document title
  // - `url`: document location
  // - `pageNumber`: current page number
  // - `totalPages`: total pages in the document
  // 
  // For example, `<span class=title></span>` would generate span containing the title.
  bool HasHeaderTemplate() const { return !!header_template_; }
  std::string GetHeaderTemplate() const { DCHECK(HasHeaderTemplate()); return header_template_.value(); }
  void SetHeaderTemplate(const std::string& value) { header_template_ = value; }

  // HTML template for the print footer. Should use the same format as the `headerTemplate`.
  bool HasFooterTemplate() const { return !!footer_template_; }
  std::string GetFooterTemplate() const { DCHECK(HasFooterTemplate()); return footer_template_.value(); }
  void SetFooterTemplate(const std::string& value) { footer_template_ = value; }

  // Whether or not to prefer page size as defined by css. Defaults to false,
  // in which case the content will be scaled to fit the paper size.
  bool HasPreferCSSPageSize() const { return !!prefercss_page_size_; }
  bool GetPreferCSSPageSize() const { DCHECK(HasPreferCSSPageSize()); return prefercss_page_size_.value(); }
  void SetPreferCSSPageSize(bool value) { prefercss_page_size_ = value; }

  // return as stream
  bool HasTransferMode() const { return !!transfer_mode_; }
  ::headless::page::PrintToPDFTransferMode GetTransferMode() const { DCHECK(HasTransferMode()); return transfer_mode_.value(); }
  void SetTransferMode(::headless::page::PrintToPDFTransferMode value) { transfer_mode_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PrintToPDFParams> Clone() const;

  template<int STATE>
  class PrintToPDFParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    PrintToPDFParamsBuilder<STATE>& SetLandscape(bool value) {
      result_->SetLandscape(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetDisplayHeaderFooter(bool value) {
      result_->SetDisplayHeaderFooter(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetPrintBackground(bool value) {
      result_->SetPrintBackground(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetScale(double value) {
      result_->SetScale(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetPaperWidth(double value) {
      result_->SetPaperWidth(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetPaperHeight(double value) {
      result_->SetPaperHeight(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetMarginTop(double value) {
      result_->SetMarginTop(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetMarginBottom(double value) {
      result_->SetMarginBottom(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetMarginLeft(double value) {
      result_->SetMarginLeft(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetMarginRight(double value) {
      result_->SetMarginRight(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetPageRanges(const std::string& value) {
      result_->SetPageRanges(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetIgnoreInvalidPageRanges(bool value) {
      result_->SetIgnoreInvalidPageRanges(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetHeaderTemplate(const std::string& value) {
      result_->SetHeaderTemplate(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetFooterTemplate(const std::string& value) {
      result_->SetFooterTemplate(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetPreferCSSPageSize(bool value) {
      result_->SetPreferCSSPageSize(value);
      return *this;
    }

    PrintToPDFParamsBuilder<STATE>& SetTransferMode(::headless::page::PrintToPDFTransferMode value) {
      result_->SetTransferMode(value);
      return *this;
    }

    std::unique_ptr<PrintToPDFParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PrintToPDFParams;
    PrintToPDFParamsBuilder() : result_(new PrintToPDFParams()) { }

    template<int STEP> PrintToPDFParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PrintToPDFParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PrintToPDFParams> result_;
  };

  static PrintToPDFParamsBuilder<0> Builder() {
    return PrintToPDFParamsBuilder<0>();
  }

 private:
  PrintToPDFParams() { }

  base::Optional<bool> landscape_;
  base::Optional<bool> display_header_footer_;
  base::Optional<bool> print_background_;
  base::Optional<double> scale_;
  base::Optional<double> paper_width_;
  base::Optional<double> paper_height_;
  base::Optional<double> margin_top_;
  base::Optional<double> margin_bottom_;
  base::Optional<double> margin_left_;
  base::Optional<double> margin_right_;
  base::Optional<std::string> page_ranges_;
  base::Optional<bool> ignore_invalid_page_ranges_;
  base::Optional<std::string> header_template_;
  base::Optional<std::string> footer_template_;
  base::Optional<bool> prefercss_page_size_;
  base::Optional<::headless::page::PrintToPDFTransferMode> transfer_mode_;

  DISALLOW_COPY_AND_ASSIGN(PrintToPDFParams);
};


// Result for the PrintToPDF command.
class HEADLESS_EXPORT PrintToPDFResult {
 public:
  static std::unique_ptr<PrintToPDFResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~PrintToPDFResult() { }

  // Base64-encoded pdf data. Empty if |returnAsStream| is specified.
  protocol::Binary GetData() const { return data_; }
  void SetData(const protocol::Binary& value) { data_ = value; }

  // A handle of the stream that holds resulting PDF data.
  bool HasStream() const { return !!stream_; }
  std::string GetStream() const { DCHECK(HasStream()); return stream_.value(); }
  void SetStream(const std::string& value) { stream_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<PrintToPDFResult> Clone() const;

  template<int STATE>
  class PrintToPDFResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataSet = 1 << 1,
      kAllRequiredFieldsSet = (kDataSet | 0)
    };

    PrintToPDFResultBuilder<STATE | kDataSet>& SetData(const protocol::Binary& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    PrintToPDFResultBuilder<STATE>& SetStream(const std::string& value) {
      result_->SetStream(value);
      return *this;
    }

    std::unique_ptr<PrintToPDFResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class PrintToPDFResult;
    PrintToPDFResultBuilder() : result_(new PrintToPDFResult()) { }

    template<int STEP> PrintToPDFResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<PrintToPDFResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<PrintToPDFResult> result_;
  };

  static PrintToPDFResultBuilder<0> Builder() {
    return PrintToPDFResultBuilder<0>();
  }

 private:
  PrintToPDFResult() { }

  protocol::Binary data_;
  base::Optional<std::string> stream_;

  DISALLOW_COPY_AND_ASSIGN(PrintToPDFResult);
};


// Parameters for the Reload command.
class HEADLESS_EXPORT ReloadParams {
 public:
  static std::unique_ptr<ReloadParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReloadParams() { }

  // If true, browser cache is ignored (as if the user pressed Shift+refresh).
  bool HasIgnoreCache() const { return !!ignore_cache_; }
  bool GetIgnoreCache() const { DCHECK(HasIgnoreCache()); return ignore_cache_.value(); }
  void SetIgnoreCache(bool value) { ignore_cache_ = value; }

  // If set, the script will be injected into all frames of the inspected page after reload.
  // Argument will be ignored if reloading dataURL origin.
  bool HasScriptToEvaluateOnLoad() const { return !!script_to_evaluate_on_load_; }
  std::string GetScriptToEvaluateOnLoad() const { DCHECK(HasScriptToEvaluateOnLoad()); return script_to_evaluate_on_load_.value(); }
  void SetScriptToEvaluateOnLoad(const std::string& value) { script_to_evaluate_on_load_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReloadParams> Clone() const;

  template<int STATE>
  class ReloadParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    ReloadParamsBuilder<STATE>& SetIgnoreCache(bool value) {
      result_->SetIgnoreCache(value);
      return *this;
    }

    ReloadParamsBuilder<STATE>& SetScriptToEvaluateOnLoad(const std::string& value) {
      result_->SetScriptToEvaluateOnLoad(value);
      return *this;
    }

    std::unique_ptr<ReloadParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReloadParams;
    ReloadParamsBuilder() : result_(new ReloadParams()) { }

    template<int STEP> ReloadParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReloadParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReloadParams> result_;
  };

  static ReloadParamsBuilder<0> Builder() {
    return ReloadParamsBuilder<0>();
  }

 private:
  ReloadParams() { }

  base::Optional<bool> ignore_cache_;
  base::Optional<std::string> script_to_evaluate_on_load_;

  DISALLOW_COPY_AND_ASSIGN(ReloadParams);
};


// Result for the Reload command.
class HEADLESS_EXPORT ReloadResult {
 public:
  static std::unique_ptr<ReloadResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ReloadResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ReloadResult> Clone() const;

  template<int STATE>
  class ReloadResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ReloadResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ReloadResult;
    ReloadResultBuilder() : result_(new ReloadResult()) { }

    template<int STEP> ReloadResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ReloadResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ReloadResult> result_;
  };

  static ReloadResultBuilder<0> Builder() {
    return ReloadResultBuilder<0>();
  }

 private:
  ReloadResult() { }


  DISALLOW_COPY_AND_ASSIGN(ReloadResult);
};


// Parameters for the RemoveScriptToEvaluateOnLoad command.
class HEADLESS_EXPORT RemoveScriptToEvaluateOnLoadParams {
 public:
  static std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveScriptToEvaluateOnLoadParams() { }

  std::string GetIdentifier() const { return identifier_; }
  void SetIdentifier(const std::string& value) { identifier_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> Clone() const;

  template<int STATE>
  class RemoveScriptToEvaluateOnLoadParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdentifierSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdentifierSet | 0)
    };

    RemoveScriptToEvaluateOnLoadParamsBuilder<STATE | kIdentifierSet>& SetIdentifier(const std::string& value) {
      static_assert(!(STATE & kIdentifierSet), "property identifier should not have already been set");
      result_->SetIdentifier(value);
      return CastState<kIdentifierSet>();
    }

    std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveScriptToEvaluateOnLoadParams;
    RemoveScriptToEvaluateOnLoadParamsBuilder() : result_(new RemoveScriptToEvaluateOnLoadParams()) { }

    template<int STEP> RemoveScriptToEvaluateOnLoadParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveScriptToEvaluateOnLoadParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveScriptToEvaluateOnLoadParams> result_;
  };

  static RemoveScriptToEvaluateOnLoadParamsBuilder<0> Builder() {
    return RemoveScriptToEvaluateOnLoadParamsBuilder<0>();
  }

 private:
  RemoveScriptToEvaluateOnLoadParams() { }

  std::string identifier_;

  DISALLOW_COPY_AND_ASSIGN(RemoveScriptToEvaluateOnLoadParams);
};


// Result for the RemoveScriptToEvaluateOnLoad command.
class HEADLESS_EXPORT RemoveScriptToEvaluateOnLoadResult {
 public:
  static std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveScriptToEvaluateOnLoadResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> Clone() const;

  template<int STATE>
  class RemoveScriptToEvaluateOnLoadResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveScriptToEvaluateOnLoadResult;
    RemoveScriptToEvaluateOnLoadResultBuilder() : result_(new RemoveScriptToEvaluateOnLoadResult()) { }

    template<int STEP> RemoveScriptToEvaluateOnLoadResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveScriptToEvaluateOnLoadResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveScriptToEvaluateOnLoadResult> result_;
  };

  static RemoveScriptToEvaluateOnLoadResultBuilder<0> Builder() {
    return RemoveScriptToEvaluateOnLoadResultBuilder<0>();
  }

 private:
  RemoveScriptToEvaluateOnLoadResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveScriptToEvaluateOnLoadResult);
};


// Parameters for the RemoveScriptToEvaluateOnNewDocument command.
class HEADLESS_EXPORT RemoveScriptToEvaluateOnNewDocumentParams {
 public:
  static std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveScriptToEvaluateOnNewDocumentParams() { }

  std::string GetIdentifier() const { return identifier_; }
  void SetIdentifier(const std::string& value) { identifier_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> Clone() const;

  template<int STATE>
  class RemoveScriptToEvaluateOnNewDocumentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIdentifierSet = 1 << 1,
      kAllRequiredFieldsSet = (kIdentifierSet | 0)
    };

    RemoveScriptToEvaluateOnNewDocumentParamsBuilder<STATE | kIdentifierSet>& SetIdentifier(const std::string& value) {
      static_assert(!(STATE & kIdentifierSet), "property identifier should not have already been set");
      result_->SetIdentifier(value);
      return CastState<kIdentifierSet>();
    }

    std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveScriptToEvaluateOnNewDocumentParams;
    RemoveScriptToEvaluateOnNewDocumentParamsBuilder() : result_(new RemoveScriptToEvaluateOnNewDocumentParams()) { }

    template<int STEP> RemoveScriptToEvaluateOnNewDocumentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveScriptToEvaluateOnNewDocumentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentParams> result_;
  };

  static RemoveScriptToEvaluateOnNewDocumentParamsBuilder<0> Builder() {
    return RemoveScriptToEvaluateOnNewDocumentParamsBuilder<0>();
  }

 private:
  RemoveScriptToEvaluateOnNewDocumentParams() { }

  std::string identifier_;

  DISALLOW_COPY_AND_ASSIGN(RemoveScriptToEvaluateOnNewDocumentParams);
};


// Result for the RemoveScriptToEvaluateOnNewDocument command.
class HEADLESS_EXPORT RemoveScriptToEvaluateOnNewDocumentResult {
 public:
  static std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RemoveScriptToEvaluateOnNewDocumentResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> Clone() const;

  template<int STATE>
  class RemoveScriptToEvaluateOnNewDocumentResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RemoveScriptToEvaluateOnNewDocumentResult;
    RemoveScriptToEvaluateOnNewDocumentResultBuilder() : result_(new RemoveScriptToEvaluateOnNewDocumentResult()) { }

    template<int STEP> RemoveScriptToEvaluateOnNewDocumentResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RemoveScriptToEvaluateOnNewDocumentResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RemoveScriptToEvaluateOnNewDocumentResult> result_;
  };

  static RemoveScriptToEvaluateOnNewDocumentResultBuilder<0> Builder() {
    return RemoveScriptToEvaluateOnNewDocumentResultBuilder<0>();
  }

 private:
  RemoveScriptToEvaluateOnNewDocumentResult() { }


  DISALLOW_COPY_AND_ASSIGN(RemoveScriptToEvaluateOnNewDocumentResult);
};


// Parameters for the ScreencastFrameAck command.
class HEADLESS_EXPORT ScreencastFrameAckParams {
 public:
  static std::unique_ptr<ScreencastFrameAckParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScreencastFrameAckParams() { }

  // Frame number.
  int GetSessionId() const { return session_id_; }
  void SetSessionId(int value) { session_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScreencastFrameAckParams> Clone() const;

  template<int STATE>
  class ScreencastFrameAckParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSessionIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSessionIdSet | 0)
    };

    ScreencastFrameAckParamsBuilder<STATE | kSessionIdSet>& SetSessionId(int value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    std::unique_ptr<ScreencastFrameAckParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScreencastFrameAckParams;
    ScreencastFrameAckParamsBuilder() : result_(new ScreencastFrameAckParams()) { }

    template<int STEP> ScreencastFrameAckParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScreencastFrameAckParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScreencastFrameAckParams> result_;
  };

  static ScreencastFrameAckParamsBuilder<0> Builder() {
    return ScreencastFrameAckParamsBuilder<0>();
  }

 private:
  ScreencastFrameAckParams() { }

  int session_id_;

  DISALLOW_COPY_AND_ASSIGN(ScreencastFrameAckParams);
};


// Result for the ScreencastFrameAck command.
class HEADLESS_EXPORT ScreencastFrameAckResult {
 public:
  static std::unique_ptr<ScreencastFrameAckResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScreencastFrameAckResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScreencastFrameAckResult> Clone() const;

  template<int STATE>
  class ScreencastFrameAckResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ScreencastFrameAckResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScreencastFrameAckResult;
    ScreencastFrameAckResultBuilder() : result_(new ScreencastFrameAckResult()) { }

    template<int STEP> ScreencastFrameAckResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScreencastFrameAckResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScreencastFrameAckResult> result_;
  };

  static ScreencastFrameAckResultBuilder<0> Builder() {
    return ScreencastFrameAckResultBuilder<0>();
  }

 private:
  ScreencastFrameAckResult() { }


  DISALLOW_COPY_AND_ASSIGN(ScreencastFrameAckResult);
};


// Parameters for the SearchInResource command.
class HEADLESS_EXPORT SearchInResourceParams {
 public:
  static std::unique_ptr<SearchInResourceParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SearchInResourceParams() { }

  // Frame id for resource to search in.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // URL of the resource to search in.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // String to search for.
  std::string GetQuery() const { return query_; }
  void SetQuery(const std::string& value) { query_ = value; }

  // If true, search is case sensitive.
  bool HasCaseSensitive() const { return !!case_sensitive_; }
  bool GetCaseSensitive() const { DCHECK(HasCaseSensitive()); return case_sensitive_.value(); }
  void SetCaseSensitive(bool value) { case_sensitive_ = value; }

  // If true, treats string parameter as regex.
  bool HasIsRegex() const { return !!is_regex_; }
  bool GetIsRegex() const { DCHECK(HasIsRegex()); return is_regex_.value(); }
  void SetIsRegex(bool value) { is_regex_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SearchInResourceParams> Clone() const;

  template<int STATE>
  class SearchInResourceParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kUrlSet = 1 << 2,
    kQuerySet = 1 << 3,
      kAllRequiredFieldsSet = (kFrameIdSet | kUrlSet | kQuerySet | 0)
    };

    SearchInResourceParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    SearchInResourceParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    SearchInResourceParamsBuilder<STATE | kQuerySet>& SetQuery(const std::string& value) {
      static_assert(!(STATE & kQuerySet), "property query should not have already been set");
      result_->SetQuery(value);
      return CastState<kQuerySet>();
    }

    SearchInResourceParamsBuilder<STATE>& SetCaseSensitive(bool value) {
      result_->SetCaseSensitive(value);
      return *this;
    }

    SearchInResourceParamsBuilder<STATE>& SetIsRegex(bool value) {
      result_->SetIsRegex(value);
      return *this;
    }

    std::unique_ptr<SearchInResourceParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SearchInResourceParams;
    SearchInResourceParamsBuilder() : result_(new SearchInResourceParams()) { }

    template<int STEP> SearchInResourceParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SearchInResourceParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SearchInResourceParams> result_;
  };

  static SearchInResourceParamsBuilder<0> Builder() {
    return SearchInResourceParamsBuilder<0>();
  }

 private:
  SearchInResourceParams() { }

  std::string frame_id_;
  std::string url_;
  std::string query_;
  base::Optional<bool> case_sensitive_;
  base::Optional<bool> is_regex_;

  DISALLOW_COPY_AND_ASSIGN(SearchInResourceParams);
};


// Result for the SearchInResource command.
class HEADLESS_EXPORT SearchInResourceResult {
 public:
  static std::unique_ptr<SearchInResourceResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SearchInResourceResult() { }

  // List of search matches.
  const std::vector<std::unique_ptr<::headless::debugger::SearchMatch>>* GetResult() const { return &result_; }
  void SetResult(std::vector<std::unique_ptr<::headless::debugger::SearchMatch>> value) { result_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SearchInResourceResult> Clone() const;

  template<int STATE>
  class SearchInResourceResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
      kAllRequiredFieldsSet = (kResultSet | 0)
    };

    SearchInResourceResultBuilder<STATE | kResultSet>& SetResult(std::vector<std::unique_ptr<::headless::debugger::SearchMatch>> value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(std::move(value));
      return CastState<kResultSet>();
    }

    std::unique_ptr<SearchInResourceResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SearchInResourceResult;
    SearchInResourceResultBuilder() : result_(new SearchInResourceResult()) { }

    template<int STEP> SearchInResourceResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SearchInResourceResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SearchInResourceResult> result_;
  };

  static SearchInResourceResultBuilder<0> Builder() {
    return SearchInResourceResultBuilder<0>();
  }

 private:
  SearchInResourceResult() { }

  std::vector<std::unique_ptr<::headless::debugger::SearchMatch>> result_;

  DISALLOW_COPY_AND_ASSIGN(SearchInResourceResult);
};


// Parameters for the SetAdBlockingEnabled command.
class HEADLESS_EXPORT SetAdBlockingEnabledParams {
 public:
  static std::unique_ptr<SetAdBlockingEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAdBlockingEnabledParams() { }

  // Whether to block ads.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAdBlockingEnabledParams> Clone() const;

  template<int STATE>
  class SetAdBlockingEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetAdBlockingEnabledParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetAdBlockingEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAdBlockingEnabledParams;
    SetAdBlockingEnabledParamsBuilder() : result_(new SetAdBlockingEnabledParams()) { }

    template<int STEP> SetAdBlockingEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAdBlockingEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAdBlockingEnabledParams> result_;
  };

  static SetAdBlockingEnabledParamsBuilder<0> Builder() {
    return SetAdBlockingEnabledParamsBuilder<0>();
  }

 private:
  SetAdBlockingEnabledParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetAdBlockingEnabledParams);
};


// Result for the SetAdBlockingEnabled command.
class HEADLESS_EXPORT SetAdBlockingEnabledResult {
 public:
  static std::unique_ptr<SetAdBlockingEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetAdBlockingEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetAdBlockingEnabledResult> Clone() const;

  template<int STATE>
  class SetAdBlockingEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetAdBlockingEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetAdBlockingEnabledResult;
    SetAdBlockingEnabledResultBuilder() : result_(new SetAdBlockingEnabledResult()) { }

    template<int STEP> SetAdBlockingEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetAdBlockingEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetAdBlockingEnabledResult> result_;
  };

  static SetAdBlockingEnabledResultBuilder<0> Builder() {
    return SetAdBlockingEnabledResultBuilder<0>();
  }

 private:
  SetAdBlockingEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetAdBlockingEnabledResult);
};


// Parameters for the SetBypassCSP command.
class HEADLESS_EXPORT SetBypassCSPParams {
 public:
  static std::unique_ptr<SetBypassCSPParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetBypassCSPParams() { }

  // Whether to bypass page CSP.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetBypassCSPParams> Clone() const;

  template<int STATE>
  class SetBypassCSPParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetBypassCSPParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetBypassCSPParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetBypassCSPParams;
    SetBypassCSPParamsBuilder() : result_(new SetBypassCSPParams()) { }

    template<int STEP> SetBypassCSPParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetBypassCSPParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetBypassCSPParams> result_;
  };

  static SetBypassCSPParamsBuilder<0> Builder() {
    return SetBypassCSPParamsBuilder<0>();
  }

 private:
  SetBypassCSPParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetBypassCSPParams);
};


// Result for the SetBypassCSP command.
class HEADLESS_EXPORT SetBypassCSPResult {
 public:
  static std::unique_ptr<SetBypassCSPResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetBypassCSPResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetBypassCSPResult> Clone() const;

  template<int STATE>
  class SetBypassCSPResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetBypassCSPResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetBypassCSPResult;
    SetBypassCSPResultBuilder() : result_(new SetBypassCSPResult()) { }

    template<int STEP> SetBypassCSPResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetBypassCSPResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetBypassCSPResult> result_;
  };

  static SetBypassCSPResultBuilder<0> Builder() {
    return SetBypassCSPResultBuilder<0>();
  }

 private:
  SetBypassCSPResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetBypassCSPResult);
};


// Parameters for the SetDeviceMetricsOverride command.
class HEADLESS_EXPORT SetDeviceMetricsOverrideParams {
 public:
  static std::unique_ptr<SetDeviceMetricsOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceMetricsOverrideParams() { }

  // Overriding width value in pixels (minimum 0, maximum 10000000). 0 disables the override.
  int GetWidth() const { return width_; }
  void SetWidth(int value) { width_ = value; }

  // Overriding height value in pixels (minimum 0, maximum 10000000). 0 disables the override.
  int GetHeight() const { return height_; }
  void SetHeight(int value) { height_ = value; }

  // Overriding device scale factor value. 0 disables the override.
  double GetDeviceScaleFactor() const { return device_scale_factor_; }
  void SetDeviceScaleFactor(double value) { device_scale_factor_ = value; }

  // Whether to emulate mobile device. This includes viewport meta tag, overlay scrollbars, text
  // autosizing and more.
  bool GetMobile() const { return mobile_; }
  void SetMobile(bool value) { mobile_ = value; }

  // Scale to apply to resulting view image.
  bool HasScale() const { return !!scale_; }
  double GetScale() const { DCHECK(HasScale()); return scale_.value(); }
  void SetScale(double value) { scale_ = value; }

  // Overriding screen width value in pixels (minimum 0, maximum 10000000).
  bool HasScreenWidth() const { return !!screen_width_; }
  int GetScreenWidth() const { DCHECK(HasScreenWidth()); return screen_width_.value(); }
  void SetScreenWidth(int value) { screen_width_ = value; }

  // Overriding screen height value in pixels (minimum 0, maximum 10000000).
  bool HasScreenHeight() const { return !!screen_height_; }
  int GetScreenHeight() const { DCHECK(HasScreenHeight()); return screen_height_.value(); }
  void SetScreenHeight(int value) { screen_height_ = value; }

  // Overriding view X position on screen in pixels (minimum 0, maximum 10000000).
  bool HasPositionX() const { return !!positionx_; }
  int GetPositionX() const { DCHECK(HasPositionX()); return positionx_.value(); }
  void SetPositionX(int value) { positionx_ = value; }

  // Overriding view Y position on screen in pixels (minimum 0, maximum 10000000).
  bool HasPositionY() const { return !!positiony_; }
  int GetPositionY() const { DCHECK(HasPositionY()); return positiony_.value(); }
  void SetPositionY(int value) { positiony_ = value; }

  // Do not set visible view size, rely upon explicit setVisibleSize call.
  bool HasDontSetVisibleSize() const { return !!dont_set_visible_size_; }
  bool GetDontSetVisibleSize() const { DCHECK(HasDontSetVisibleSize()); return dont_set_visible_size_.value(); }
  void SetDontSetVisibleSize(bool value) { dont_set_visible_size_ = value; }

  // Screen orientation override.
  bool HasScreenOrientation() const { return !!screen_orientation_; }
  const ::headless::emulation::ScreenOrientation* GetScreenOrientation() const { DCHECK(HasScreenOrientation()); return screen_orientation_.value().get(); }
  void SetScreenOrientation(std::unique_ptr<::headless::emulation::ScreenOrientation> value) { screen_orientation_ = std::move(value); }

  // The viewport dimensions and scale. If not set, the override is cleared.
  bool HasViewport() const { return !!viewport_; }
  const ::headless::page::Viewport* GetViewport() const { DCHECK(HasViewport()); return viewport_.value().get(); }
  void SetViewport(std::unique_ptr<::headless::page::Viewport> value) { viewport_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceMetricsOverrideParams> Clone() const;

  template<int STATE>
  class SetDeviceMetricsOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kWidthSet = 1 << 1,
    kHeightSet = 1 << 2,
    kDeviceScaleFactorSet = 1 << 3,
    kMobileSet = 1 << 4,
      kAllRequiredFieldsSet = (kWidthSet | kHeightSet | kDeviceScaleFactorSet | kMobileSet | 0)
    };

    SetDeviceMetricsOverrideParamsBuilder<STATE | kWidthSet>& SetWidth(int value) {
      static_assert(!(STATE & kWidthSet), "property width should not have already been set");
      result_->SetWidth(value);
      return CastState<kWidthSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE | kHeightSet>& SetHeight(int value) {
      static_assert(!(STATE & kHeightSet), "property height should not have already been set");
      result_->SetHeight(value);
      return CastState<kHeightSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE | kDeviceScaleFactorSet>& SetDeviceScaleFactor(double value) {
      static_assert(!(STATE & kDeviceScaleFactorSet), "property deviceScaleFactor should not have already been set");
      result_->SetDeviceScaleFactor(value);
      return CastState<kDeviceScaleFactorSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE | kMobileSet>& SetMobile(bool value) {
      static_assert(!(STATE & kMobileSet), "property mobile should not have already been set");
      result_->SetMobile(value);
      return CastState<kMobileSet>();
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScale(double value) {
      result_->SetScale(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScreenWidth(int value) {
      result_->SetScreenWidth(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScreenHeight(int value) {
      result_->SetScreenHeight(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetPositionX(int value) {
      result_->SetPositionX(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetPositionY(int value) {
      result_->SetPositionY(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetDontSetVisibleSize(bool value) {
      result_->SetDontSetVisibleSize(value);
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetScreenOrientation(std::unique_ptr<::headless::emulation::ScreenOrientation> value) {
      result_->SetScreenOrientation(std::move(value));
      return *this;
    }

    SetDeviceMetricsOverrideParamsBuilder<STATE>& SetViewport(std::unique_ptr<::headless::page::Viewport> value) {
      result_->SetViewport(std::move(value));
      return *this;
    }

    std::unique_ptr<SetDeviceMetricsOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceMetricsOverrideParams;
    SetDeviceMetricsOverrideParamsBuilder() : result_(new SetDeviceMetricsOverrideParams()) { }

    template<int STEP> SetDeviceMetricsOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceMetricsOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceMetricsOverrideParams> result_;
  };

  static SetDeviceMetricsOverrideParamsBuilder<0> Builder() {
    return SetDeviceMetricsOverrideParamsBuilder<0>();
  }

 private:
  SetDeviceMetricsOverrideParams() { }

  int width_;
  int height_;
  double device_scale_factor_;
  bool mobile_;
  base::Optional<double> scale_;
  base::Optional<int> screen_width_;
  base::Optional<int> screen_height_;
  base::Optional<int> positionx_;
  base::Optional<int> positiony_;
  base::Optional<bool> dont_set_visible_size_;
  base::Optional<std::unique_ptr<::headless::emulation::ScreenOrientation>> screen_orientation_;
  base::Optional<std::unique_ptr<::headless::page::Viewport>> viewport_;

  DISALLOW_COPY_AND_ASSIGN(SetDeviceMetricsOverrideParams);
};


// Result for the SetDeviceMetricsOverride command.
class HEADLESS_EXPORT SetDeviceMetricsOverrideResult {
 public:
  static std::unique_ptr<SetDeviceMetricsOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceMetricsOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceMetricsOverrideResult> Clone() const;

  template<int STATE>
  class SetDeviceMetricsOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDeviceMetricsOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceMetricsOverrideResult;
    SetDeviceMetricsOverrideResultBuilder() : result_(new SetDeviceMetricsOverrideResult()) { }

    template<int STEP> SetDeviceMetricsOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceMetricsOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceMetricsOverrideResult> result_;
  };

  static SetDeviceMetricsOverrideResultBuilder<0> Builder() {
    return SetDeviceMetricsOverrideResultBuilder<0>();
  }

 private:
  SetDeviceMetricsOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDeviceMetricsOverrideResult);
};


// Parameters for the SetDeviceOrientationOverride command.
class HEADLESS_EXPORT SetDeviceOrientationOverrideParams {
 public:
  static std::unique_ptr<SetDeviceOrientationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceOrientationOverrideParams() { }

  // Mock alpha
  double GetAlpha() const { return alpha_; }
  void SetAlpha(double value) { alpha_ = value; }

  // Mock beta
  double GetBeta() const { return beta_; }
  void SetBeta(double value) { beta_ = value; }

  // Mock gamma
  double GetGamma() const { return gamma_; }
  void SetGamma(double value) { gamma_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceOrientationOverrideParams> Clone() const;

  template<int STATE>
  class SetDeviceOrientationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kAlphaSet = 1 << 1,
    kBetaSet = 1 << 2,
    kGammaSet = 1 << 3,
      kAllRequiredFieldsSet = (kAlphaSet | kBetaSet | kGammaSet | 0)
    };

    SetDeviceOrientationOverrideParamsBuilder<STATE | kAlphaSet>& SetAlpha(double value) {
      static_assert(!(STATE & kAlphaSet), "property alpha should not have already been set");
      result_->SetAlpha(value);
      return CastState<kAlphaSet>();
    }

    SetDeviceOrientationOverrideParamsBuilder<STATE | kBetaSet>& SetBeta(double value) {
      static_assert(!(STATE & kBetaSet), "property beta should not have already been set");
      result_->SetBeta(value);
      return CastState<kBetaSet>();
    }

    SetDeviceOrientationOverrideParamsBuilder<STATE | kGammaSet>& SetGamma(double value) {
      static_assert(!(STATE & kGammaSet), "property gamma should not have already been set");
      result_->SetGamma(value);
      return CastState<kGammaSet>();
    }

    std::unique_ptr<SetDeviceOrientationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceOrientationOverrideParams;
    SetDeviceOrientationOverrideParamsBuilder() : result_(new SetDeviceOrientationOverrideParams()) { }

    template<int STEP> SetDeviceOrientationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceOrientationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceOrientationOverrideParams> result_;
  };

  static SetDeviceOrientationOverrideParamsBuilder<0> Builder() {
    return SetDeviceOrientationOverrideParamsBuilder<0>();
  }

 private:
  SetDeviceOrientationOverrideParams() { }

  double alpha_;
  double beta_;
  double gamma_;

  DISALLOW_COPY_AND_ASSIGN(SetDeviceOrientationOverrideParams);
};


// Result for the SetDeviceOrientationOverride command.
class HEADLESS_EXPORT SetDeviceOrientationOverrideResult {
 public:
  static std::unique_ptr<SetDeviceOrientationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDeviceOrientationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDeviceOrientationOverrideResult> Clone() const;

  template<int STATE>
  class SetDeviceOrientationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDeviceOrientationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDeviceOrientationOverrideResult;
    SetDeviceOrientationOverrideResultBuilder() : result_(new SetDeviceOrientationOverrideResult()) { }

    template<int STEP> SetDeviceOrientationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDeviceOrientationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDeviceOrientationOverrideResult> result_;
  };

  static SetDeviceOrientationOverrideResultBuilder<0> Builder() {
    return SetDeviceOrientationOverrideResultBuilder<0>();
  }

 private:
  SetDeviceOrientationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDeviceOrientationOverrideResult);
};


// Parameters for the SetFontFamilies command.
class HEADLESS_EXPORT SetFontFamiliesParams {
 public:
  static std::unique_ptr<SetFontFamiliesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFontFamiliesParams() { }

  // Specifies font families to set. If a font family is not specified, it won't be changed.
  const ::headless::page::FontFamilies* GetFontFamilies() const { return font_families_.get(); }
  void SetFontFamilies(std::unique_ptr<::headless::page::FontFamilies> value) { font_families_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFontFamiliesParams> Clone() const;

  template<int STATE>
  class SetFontFamiliesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFontFamiliesSet = 1 << 1,
      kAllRequiredFieldsSet = (kFontFamiliesSet | 0)
    };

    SetFontFamiliesParamsBuilder<STATE | kFontFamiliesSet>& SetFontFamilies(std::unique_ptr<::headless::page::FontFamilies> value) {
      static_assert(!(STATE & kFontFamiliesSet), "property fontFamilies should not have already been set");
      result_->SetFontFamilies(std::move(value));
      return CastState<kFontFamiliesSet>();
    }

    std::unique_ptr<SetFontFamiliesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFontFamiliesParams;
    SetFontFamiliesParamsBuilder() : result_(new SetFontFamiliesParams()) { }

    template<int STEP> SetFontFamiliesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFontFamiliesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFontFamiliesParams> result_;
  };

  static SetFontFamiliesParamsBuilder<0> Builder() {
    return SetFontFamiliesParamsBuilder<0>();
  }

 private:
  SetFontFamiliesParams() { }

  std::unique_ptr<::headless::page::FontFamilies> font_families_;

  DISALLOW_COPY_AND_ASSIGN(SetFontFamiliesParams);
};


// Result for the SetFontFamilies command.
class HEADLESS_EXPORT SetFontFamiliesResult {
 public:
  static std::unique_ptr<SetFontFamiliesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFontFamiliesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFontFamiliesResult> Clone() const;

  template<int STATE>
  class SetFontFamiliesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetFontFamiliesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFontFamiliesResult;
    SetFontFamiliesResultBuilder() : result_(new SetFontFamiliesResult()) { }

    template<int STEP> SetFontFamiliesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFontFamiliesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFontFamiliesResult> result_;
  };

  static SetFontFamiliesResultBuilder<0> Builder() {
    return SetFontFamiliesResultBuilder<0>();
  }

 private:
  SetFontFamiliesResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetFontFamiliesResult);
};


// Parameters for the SetFontSizes command.
class HEADLESS_EXPORT SetFontSizesParams {
 public:
  static std::unique_ptr<SetFontSizesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFontSizesParams() { }

  // Specifies font sizes to set. If a font size is not specified, it won't be changed.
  const ::headless::page::FontSizes* GetFontSizes() const { return font_sizes_.get(); }
  void SetFontSizes(std::unique_ptr<::headless::page::FontSizes> value) { font_sizes_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFontSizesParams> Clone() const;

  template<int STATE>
  class SetFontSizesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFontSizesSet = 1 << 1,
      kAllRequiredFieldsSet = (kFontSizesSet | 0)
    };

    SetFontSizesParamsBuilder<STATE | kFontSizesSet>& SetFontSizes(std::unique_ptr<::headless::page::FontSizes> value) {
      static_assert(!(STATE & kFontSizesSet), "property fontSizes should not have already been set");
      result_->SetFontSizes(std::move(value));
      return CastState<kFontSizesSet>();
    }

    std::unique_ptr<SetFontSizesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFontSizesParams;
    SetFontSizesParamsBuilder() : result_(new SetFontSizesParams()) { }

    template<int STEP> SetFontSizesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFontSizesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFontSizesParams> result_;
  };

  static SetFontSizesParamsBuilder<0> Builder() {
    return SetFontSizesParamsBuilder<0>();
  }

 private:
  SetFontSizesParams() { }

  std::unique_ptr<::headless::page::FontSizes> font_sizes_;

  DISALLOW_COPY_AND_ASSIGN(SetFontSizesParams);
};


// Result for the SetFontSizes command.
class HEADLESS_EXPORT SetFontSizesResult {
 public:
  static std::unique_ptr<SetFontSizesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetFontSizesResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetFontSizesResult> Clone() const;

  template<int STATE>
  class SetFontSizesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetFontSizesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetFontSizesResult;
    SetFontSizesResultBuilder() : result_(new SetFontSizesResult()) { }

    template<int STEP> SetFontSizesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetFontSizesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetFontSizesResult> result_;
  };

  static SetFontSizesResultBuilder<0> Builder() {
    return SetFontSizesResultBuilder<0>();
  }

 private:
  SetFontSizesResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetFontSizesResult);
};


// Parameters for the SetDocumentContent command.
class HEADLESS_EXPORT SetDocumentContentParams {
 public:
  static std::unique_ptr<SetDocumentContentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDocumentContentParams() { }

  // Frame id to set HTML for.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // HTML content to set.
  std::string GetHtml() const { return html_; }
  void SetHtml(const std::string& value) { html_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDocumentContentParams> Clone() const;

  template<int STATE>
  class SetDocumentContentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kHtmlSet = 1 << 2,
      kAllRequiredFieldsSet = (kFrameIdSet | kHtmlSet | 0)
    };

    SetDocumentContentParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    SetDocumentContentParamsBuilder<STATE | kHtmlSet>& SetHtml(const std::string& value) {
      static_assert(!(STATE & kHtmlSet), "property html should not have already been set");
      result_->SetHtml(value);
      return CastState<kHtmlSet>();
    }

    std::unique_ptr<SetDocumentContentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDocumentContentParams;
    SetDocumentContentParamsBuilder() : result_(new SetDocumentContentParams()) { }

    template<int STEP> SetDocumentContentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDocumentContentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDocumentContentParams> result_;
  };

  static SetDocumentContentParamsBuilder<0> Builder() {
    return SetDocumentContentParamsBuilder<0>();
  }

 private:
  SetDocumentContentParams() { }

  std::string frame_id_;
  std::string html_;

  DISALLOW_COPY_AND_ASSIGN(SetDocumentContentParams);
};


// Result for the SetDocumentContent command.
class HEADLESS_EXPORT SetDocumentContentResult {
 public:
  static std::unique_ptr<SetDocumentContentResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDocumentContentResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDocumentContentResult> Clone() const;

  template<int STATE>
  class SetDocumentContentResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDocumentContentResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDocumentContentResult;
    SetDocumentContentResultBuilder() : result_(new SetDocumentContentResult()) { }

    template<int STEP> SetDocumentContentResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDocumentContentResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDocumentContentResult> result_;
  };

  static SetDocumentContentResultBuilder<0> Builder() {
    return SetDocumentContentResultBuilder<0>();
  }

 private:
  SetDocumentContentResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDocumentContentResult);
};


// Parameters for the SetDownloadBehavior command.
class HEADLESS_EXPORT SetDownloadBehaviorParams {
 public:
  static std::unique_ptr<SetDownloadBehaviorParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDownloadBehaviorParams() { }

  // Whether to allow all or deny all download requests, or use default Chrome behavior if
  // available (otherwise deny).
  ::headless::page::SetDownloadBehaviorBehavior GetBehavior() const { return behavior_; }
  void SetBehavior(::headless::page::SetDownloadBehaviorBehavior value) { behavior_ = value; }

  // The default path to save downloaded files to. This is requred if behavior is set to 'allow'
  bool HasDownloadPath() const { return !!download_path_; }
  std::string GetDownloadPath() const { DCHECK(HasDownloadPath()); return download_path_.value(); }
  void SetDownloadPath(const std::string& value) { download_path_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDownloadBehaviorParams> Clone() const;

  template<int STATE>
  class SetDownloadBehaviorParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBehaviorSet = 1 << 1,
      kAllRequiredFieldsSet = (kBehaviorSet | 0)
    };

    SetDownloadBehaviorParamsBuilder<STATE | kBehaviorSet>& SetBehavior(::headless::page::SetDownloadBehaviorBehavior value) {
      static_assert(!(STATE & kBehaviorSet), "property behavior should not have already been set");
      result_->SetBehavior(value);
      return CastState<kBehaviorSet>();
    }

    SetDownloadBehaviorParamsBuilder<STATE>& SetDownloadPath(const std::string& value) {
      result_->SetDownloadPath(value);
      return *this;
    }

    std::unique_ptr<SetDownloadBehaviorParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDownloadBehaviorParams;
    SetDownloadBehaviorParamsBuilder() : result_(new SetDownloadBehaviorParams()) { }

    template<int STEP> SetDownloadBehaviorParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDownloadBehaviorParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDownloadBehaviorParams> result_;
  };

  static SetDownloadBehaviorParamsBuilder<0> Builder() {
    return SetDownloadBehaviorParamsBuilder<0>();
  }

 private:
  SetDownloadBehaviorParams() { }

  ::headless::page::SetDownloadBehaviorBehavior behavior_;
  base::Optional<std::string> download_path_;

  DISALLOW_COPY_AND_ASSIGN(SetDownloadBehaviorParams);
};


// Result for the SetDownloadBehavior command.
class HEADLESS_EXPORT SetDownloadBehaviorResult {
 public:
  static std::unique_ptr<SetDownloadBehaviorResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetDownloadBehaviorResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetDownloadBehaviorResult> Clone() const;

  template<int STATE>
  class SetDownloadBehaviorResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetDownloadBehaviorResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetDownloadBehaviorResult;
    SetDownloadBehaviorResultBuilder() : result_(new SetDownloadBehaviorResult()) { }

    template<int STEP> SetDownloadBehaviorResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetDownloadBehaviorResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetDownloadBehaviorResult> result_;
  };

  static SetDownloadBehaviorResultBuilder<0> Builder() {
    return SetDownloadBehaviorResultBuilder<0>();
  }

 private:
  SetDownloadBehaviorResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetDownloadBehaviorResult);
};


// Parameters for the SetGeolocationOverride command.
class HEADLESS_EXPORT SetGeolocationOverrideParams {
 public:
  static std::unique_ptr<SetGeolocationOverrideParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetGeolocationOverrideParams() { }

  // Mock latitude
  bool HasLatitude() const { return !!latitude_; }
  double GetLatitude() const { DCHECK(HasLatitude()); return latitude_.value(); }
  void SetLatitude(double value) { latitude_ = value; }

  // Mock longitude
  bool HasLongitude() const { return !!longitude_; }
  double GetLongitude() const { DCHECK(HasLongitude()); return longitude_.value(); }
  void SetLongitude(double value) { longitude_ = value; }

  // Mock accuracy
  bool HasAccuracy() const { return !!accuracy_; }
  double GetAccuracy() const { DCHECK(HasAccuracy()); return accuracy_.value(); }
  void SetAccuracy(double value) { accuracy_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetGeolocationOverrideParams> Clone() const;

  template<int STATE>
  class SetGeolocationOverrideParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    SetGeolocationOverrideParamsBuilder<STATE>& SetLatitude(double value) {
      result_->SetLatitude(value);
      return *this;
    }

    SetGeolocationOverrideParamsBuilder<STATE>& SetLongitude(double value) {
      result_->SetLongitude(value);
      return *this;
    }

    SetGeolocationOverrideParamsBuilder<STATE>& SetAccuracy(double value) {
      result_->SetAccuracy(value);
      return *this;
    }

    std::unique_ptr<SetGeolocationOverrideParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetGeolocationOverrideParams;
    SetGeolocationOverrideParamsBuilder() : result_(new SetGeolocationOverrideParams()) { }

    template<int STEP> SetGeolocationOverrideParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetGeolocationOverrideParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetGeolocationOverrideParams> result_;
  };

  static SetGeolocationOverrideParamsBuilder<0> Builder() {
    return SetGeolocationOverrideParamsBuilder<0>();
  }

 private:
  SetGeolocationOverrideParams() { }

  base::Optional<double> latitude_;
  base::Optional<double> longitude_;
  base::Optional<double> accuracy_;

  DISALLOW_COPY_AND_ASSIGN(SetGeolocationOverrideParams);
};


// Result for the SetGeolocationOverride command.
class HEADLESS_EXPORT SetGeolocationOverrideResult {
 public:
  static std::unique_ptr<SetGeolocationOverrideResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetGeolocationOverrideResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetGeolocationOverrideResult> Clone() const;

  template<int STATE>
  class SetGeolocationOverrideResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetGeolocationOverrideResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetGeolocationOverrideResult;
    SetGeolocationOverrideResultBuilder() : result_(new SetGeolocationOverrideResult()) { }

    template<int STEP> SetGeolocationOverrideResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetGeolocationOverrideResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetGeolocationOverrideResult> result_;
  };

  static SetGeolocationOverrideResultBuilder<0> Builder() {
    return SetGeolocationOverrideResultBuilder<0>();
  }

 private:
  SetGeolocationOverrideResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetGeolocationOverrideResult);
};


// Parameters for the SetLifecycleEventsEnabled command.
class HEADLESS_EXPORT SetLifecycleEventsEnabledParams {
 public:
  static std::unique_ptr<SetLifecycleEventsEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetLifecycleEventsEnabledParams() { }

  // If true, starts emitting lifecycle events.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetLifecycleEventsEnabledParams> Clone() const;

  template<int STATE>
  class SetLifecycleEventsEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetLifecycleEventsEnabledParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetLifecycleEventsEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetLifecycleEventsEnabledParams;
    SetLifecycleEventsEnabledParamsBuilder() : result_(new SetLifecycleEventsEnabledParams()) { }

    template<int STEP> SetLifecycleEventsEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetLifecycleEventsEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetLifecycleEventsEnabledParams> result_;
  };

  static SetLifecycleEventsEnabledParamsBuilder<0> Builder() {
    return SetLifecycleEventsEnabledParamsBuilder<0>();
  }

 private:
  SetLifecycleEventsEnabledParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetLifecycleEventsEnabledParams);
};


// Result for the SetLifecycleEventsEnabled command.
class HEADLESS_EXPORT SetLifecycleEventsEnabledResult {
 public:
  static std::unique_ptr<SetLifecycleEventsEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetLifecycleEventsEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetLifecycleEventsEnabledResult> Clone() const;

  template<int STATE>
  class SetLifecycleEventsEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetLifecycleEventsEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetLifecycleEventsEnabledResult;
    SetLifecycleEventsEnabledResultBuilder() : result_(new SetLifecycleEventsEnabledResult()) { }

    template<int STEP> SetLifecycleEventsEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetLifecycleEventsEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetLifecycleEventsEnabledResult> result_;
  };

  static SetLifecycleEventsEnabledResultBuilder<0> Builder() {
    return SetLifecycleEventsEnabledResultBuilder<0>();
  }

 private:
  SetLifecycleEventsEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetLifecycleEventsEnabledResult);
};


// Parameters for the SetTouchEmulationEnabled command.
class HEADLESS_EXPORT SetTouchEmulationEnabledParams {
 public:
  static std::unique_ptr<SetTouchEmulationEnabledParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTouchEmulationEnabledParams() { }

  // Whether the touch event emulation should be enabled.
  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  // Touch/gesture events configuration. Default: current platform.
  bool HasConfiguration() const { return !!configuration_; }
  ::headless::page::SetTouchEmulationEnabledConfiguration GetConfiguration() const { DCHECK(HasConfiguration()); return configuration_.value(); }
  void SetConfiguration(::headless::page::SetTouchEmulationEnabledConfiguration value) { configuration_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTouchEmulationEnabledParams> Clone() const;

  template<int STATE>
  class SetTouchEmulationEnabledParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetTouchEmulationEnabledParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    SetTouchEmulationEnabledParamsBuilder<STATE>& SetConfiguration(::headless::page::SetTouchEmulationEnabledConfiguration value) {
      result_->SetConfiguration(value);
      return *this;
    }

    std::unique_ptr<SetTouchEmulationEnabledParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTouchEmulationEnabledParams;
    SetTouchEmulationEnabledParamsBuilder() : result_(new SetTouchEmulationEnabledParams()) { }

    template<int STEP> SetTouchEmulationEnabledParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTouchEmulationEnabledParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTouchEmulationEnabledParams> result_;
  };

  static SetTouchEmulationEnabledParamsBuilder<0> Builder() {
    return SetTouchEmulationEnabledParamsBuilder<0>();
  }

 private:
  SetTouchEmulationEnabledParams() { }

  bool enabled_;
  base::Optional<::headless::page::SetTouchEmulationEnabledConfiguration> configuration_;

  DISALLOW_COPY_AND_ASSIGN(SetTouchEmulationEnabledParams);
};


// Result for the SetTouchEmulationEnabled command.
class HEADLESS_EXPORT SetTouchEmulationEnabledResult {
 public:
  static std::unique_ptr<SetTouchEmulationEnabledResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetTouchEmulationEnabledResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetTouchEmulationEnabledResult> Clone() const;

  template<int STATE>
  class SetTouchEmulationEnabledResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetTouchEmulationEnabledResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetTouchEmulationEnabledResult;
    SetTouchEmulationEnabledResultBuilder() : result_(new SetTouchEmulationEnabledResult()) { }

    template<int STEP> SetTouchEmulationEnabledResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetTouchEmulationEnabledResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetTouchEmulationEnabledResult> result_;
  };

  static SetTouchEmulationEnabledResultBuilder<0> Builder() {
    return SetTouchEmulationEnabledResultBuilder<0>();
  }

 private:
  SetTouchEmulationEnabledResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetTouchEmulationEnabledResult);
};


// Parameters for the StartScreencast command.
class HEADLESS_EXPORT StartScreencastParams {
 public:
  static std::unique_ptr<StartScreencastParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartScreencastParams() { }

  // Image compression format.
  bool HasFormat() const { return !!format_; }
  ::headless::page::StartScreencastFormat GetFormat() const { DCHECK(HasFormat()); return format_.value(); }
  void SetFormat(::headless::page::StartScreencastFormat value) { format_ = value; }

  // Compression quality from range [0..100].
  bool HasQuality() const { return !!quality_; }
  int GetQuality() const { DCHECK(HasQuality()); return quality_.value(); }
  void SetQuality(int value) { quality_ = value; }

  // Maximum screenshot width.
  bool HasMaxWidth() const { return !!max_width_; }
  int GetMaxWidth() const { DCHECK(HasMaxWidth()); return max_width_.value(); }
  void SetMaxWidth(int value) { max_width_ = value; }

  // Maximum screenshot height.
  bool HasMaxHeight() const { return !!max_height_; }
  int GetMaxHeight() const { DCHECK(HasMaxHeight()); return max_height_.value(); }
  void SetMaxHeight(int value) { max_height_ = value; }

  // Send every n-th frame.
  bool HasEveryNthFrame() const { return !!every_nth_frame_; }
  int GetEveryNthFrame() const { DCHECK(HasEveryNthFrame()); return every_nth_frame_.value(); }
  void SetEveryNthFrame(int value) { every_nth_frame_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartScreencastParams> Clone() const;

  template<int STATE>
  class StartScreencastParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    StartScreencastParamsBuilder<STATE>& SetFormat(::headless::page::StartScreencastFormat value) {
      result_->SetFormat(value);
      return *this;
    }

    StartScreencastParamsBuilder<STATE>& SetQuality(int value) {
      result_->SetQuality(value);
      return *this;
    }

    StartScreencastParamsBuilder<STATE>& SetMaxWidth(int value) {
      result_->SetMaxWidth(value);
      return *this;
    }

    StartScreencastParamsBuilder<STATE>& SetMaxHeight(int value) {
      result_->SetMaxHeight(value);
      return *this;
    }

    StartScreencastParamsBuilder<STATE>& SetEveryNthFrame(int value) {
      result_->SetEveryNthFrame(value);
      return *this;
    }

    std::unique_ptr<StartScreencastParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartScreencastParams;
    StartScreencastParamsBuilder() : result_(new StartScreencastParams()) { }

    template<int STEP> StartScreencastParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartScreencastParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartScreencastParams> result_;
  };

  static StartScreencastParamsBuilder<0> Builder() {
    return StartScreencastParamsBuilder<0>();
  }

 private:
  StartScreencastParams() { }

  base::Optional<::headless::page::StartScreencastFormat> format_;
  base::Optional<int> quality_;
  base::Optional<int> max_width_;
  base::Optional<int> max_height_;
  base::Optional<int> every_nth_frame_;

  DISALLOW_COPY_AND_ASSIGN(StartScreencastParams);
};


// Result for the StartScreencast command.
class HEADLESS_EXPORT StartScreencastResult {
 public:
  static std::unique_ptr<StartScreencastResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartScreencastResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartScreencastResult> Clone() const;

  template<int STATE>
  class StartScreencastResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartScreencastResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartScreencastResult;
    StartScreencastResultBuilder() : result_(new StartScreencastResult()) { }

    template<int STEP> StartScreencastResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartScreencastResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartScreencastResult> result_;
  };

  static StartScreencastResultBuilder<0> Builder() {
    return StartScreencastResultBuilder<0>();
  }

 private:
  StartScreencastResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartScreencastResult);
};


// Parameters for the StopLoading command.
class HEADLESS_EXPORT StopLoadingParams {
 public:
  static std::unique_ptr<StopLoadingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopLoadingParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopLoadingParams> Clone() const;

  template<int STATE>
  class StopLoadingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopLoadingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopLoadingParams;
    StopLoadingParamsBuilder() : result_(new StopLoadingParams()) { }

    template<int STEP> StopLoadingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopLoadingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopLoadingParams> result_;
  };

  static StopLoadingParamsBuilder<0> Builder() {
    return StopLoadingParamsBuilder<0>();
  }

 private:
  StopLoadingParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopLoadingParams);
};


// Result for the StopLoading command.
class HEADLESS_EXPORT StopLoadingResult {
 public:
  static std::unique_ptr<StopLoadingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopLoadingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopLoadingResult> Clone() const;

  template<int STATE>
  class StopLoadingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopLoadingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopLoadingResult;
    StopLoadingResultBuilder() : result_(new StopLoadingResult()) { }

    template<int STEP> StopLoadingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopLoadingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopLoadingResult> result_;
  };

  static StopLoadingResultBuilder<0> Builder() {
    return StopLoadingResultBuilder<0>();
  }

 private:
  StopLoadingResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopLoadingResult);
};


// Parameters for the Crash command.
class HEADLESS_EXPORT CrashParams {
 public:
  static std::unique_ptr<CrashParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CrashParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CrashParams> Clone() const;

  template<int STATE>
  class CrashParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CrashParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CrashParams;
    CrashParamsBuilder() : result_(new CrashParams()) { }

    template<int STEP> CrashParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CrashParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CrashParams> result_;
  };

  static CrashParamsBuilder<0> Builder() {
    return CrashParamsBuilder<0>();
  }

 private:
  CrashParams() { }


  DISALLOW_COPY_AND_ASSIGN(CrashParams);
};


// Result for the Crash command.
class HEADLESS_EXPORT CrashResult {
 public:
  static std::unique_ptr<CrashResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CrashResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CrashResult> Clone() const;

  template<int STATE>
  class CrashResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CrashResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CrashResult;
    CrashResultBuilder() : result_(new CrashResult()) { }

    template<int STEP> CrashResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CrashResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CrashResult> result_;
  };

  static CrashResultBuilder<0> Builder() {
    return CrashResultBuilder<0>();
  }

 private:
  CrashResult() { }


  DISALLOW_COPY_AND_ASSIGN(CrashResult);
};


// Parameters for the Close command.
class HEADLESS_EXPORT CloseParams {
 public:
  static std::unique_ptr<CloseParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CloseParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CloseParams> Clone() const;

  template<int STATE>
  class CloseParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CloseParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CloseParams;
    CloseParamsBuilder() : result_(new CloseParams()) { }

    template<int STEP> CloseParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CloseParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CloseParams> result_;
  };

  static CloseParamsBuilder<0> Builder() {
    return CloseParamsBuilder<0>();
  }

 private:
  CloseParams() { }


  DISALLOW_COPY_AND_ASSIGN(CloseParams);
};


// Result for the Close command.
class HEADLESS_EXPORT CloseResult {
 public:
  static std::unique_ptr<CloseResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~CloseResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CloseResult> Clone() const;

  template<int STATE>
  class CloseResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<CloseResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CloseResult;
    CloseResultBuilder() : result_(new CloseResult()) { }

    template<int STEP> CloseResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CloseResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CloseResult> result_;
  };

  static CloseResultBuilder<0> Builder() {
    return CloseResultBuilder<0>();
  }

 private:
  CloseResult() { }


  DISALLOW_COPY_AND_ASSIGN(CloseResult);
};


// Parameters for the SetWebLifecycleState command.
class HEADLESS_EXPORT SetWebLifecycleStateParams {
 public:
  static std::unique_ptr<SetWebLifecycleStateParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetWebLifecycleStateParams() { }

  // Target lifecycle state
  ::headless::page::SetWebLifecycleStateState GetState() const { return state_; }
  void SetState(::headless::page::SetWebLifecycleStateState value) { state_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetWebLifecycleStateParams> Clone() const;

  template<int STATE>
  class SetWebLifecycleStateParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kStateSet = 1 << 1,
      kAllRequiredFieldsSet = (kStateSet | 0)
    };

    SetWebLifecycleStateParamsBuilder<STATE | kStateSet>& SetState(::headless::page::SetWebLifecycleStateState value) {
      static_assert(!(STATE & kStateSet), "property state should not have already been set");
      result_->SetState(value);
      return CastState<kStateSet>();
    }

    std::unique_ptr<SetWebLifecycleStateParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetWebLifecycleStateParams;
    SetWebLifecycleStateParamsBuilder() : result_(new SetWebLifecycleStateParams()) { }

    template<int STEP> SetWebLifecycleStateParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetWebLifecycleStateParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetWebLifecycleStateParams> result_;
  };

  static SetWebLifecycleStateParamsBuilder<0> Builder() {
    return SetWebLifecycleStateParamsBuilder<0>();
  }

 private:
  SetWebLifecycleStateParams() { }

  ::headless::page::SetWebLifecycleStateState state_;

  DISALLOW_COPY_AND_ASSIGN(SetWebLifecycleStateParams);
};


// Result for the SetWebLifecycleState command.
class HEADLESS_EXPORT SetWebLifecycleStateResult {
 public:
  static std::unique_ptr<SetWebLifecycleStateResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetWebLifecycleStateResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetWebLifecycleStateResult> Clone() const;

  template<int STATE>
  class SetWebLifecycleStateResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetWebLifecycleStateResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetWebLifecycleStateResult;
    SetWebLifecycleStateResultBuilder() : result_(new SetWebLifecycleStateResult()) { }

    template<int STEP> SetWebLifecycleStateResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetWebLifecycleStateResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetWebLifecycleStateResult> result_;
  };

  static SetWebLifecycleStateResultBuilder<0> Builder() {
    return SetWebLifecycleStateResultBuilder<0>();
  }

 private:
  SetWebLifecycleStateResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetWebLifecycleStateResult);
};


// Parameters for the StopScreencast command.
class HEADLESS_EXPORT StopScreencastParams {
 public:
  static std::unique_ptr<StopScreencastParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopScreencastParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopScreencastParams> Clone() const;

  template<int STATE>
  class StopScreencastParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopScreencastParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopScreencastParams;
    StopScreencastParamsBuilder() : result_(new StopScreencastParams()) { }

    template<int STEP> StopScreencastParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopScreencastParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopScreencastParams> result_;
  };

  static StopScreencastParamsBuilder<0> Builder() {
    return StopScreencastParamsBuilder<0>();
  }

 private:
  StopScreencastParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopScreencastParams);
};


// Result for the StopScreencast command.
class HEADLESS_EXPORT StopScreencastResult {
 public:
  static std::unique_ptr<StopScreencastResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopScreencastResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopScreencastResult> Clone() const;

  template<int STATE>
  class StopScreencastResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopScreencastResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopScreencastResult;
    StopScreencastResultBuilder() : result_(new StopScreencastResult()) { }

    template<int STEP> StopScreencastResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopScreencastResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopScreencastResult> result_;
  };

  static StopScreencastResultBuilder<0> Builder() {
    return StopScreencastResultBuilder<0>();
  }

 private:
  StopScreencastResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopScreencastResult);
};


// Parameters for the SetProduceCompilationCache command.
class HEADLESS_EXPORT SetProduceCompilationCacheParams {
 public:
  static std::unique_ptr<SetProduceCompilationCacheParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetProduceCompilationCacheParams() { }

  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetProduceCompilationCacheParams> Clone() const;

  template<int STATE>
  class SetProduceCompilationCacheParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetProduceCompilationCacheParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetProduceCompilationCacheParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetProduceCompilationCacheParams;
    SetProduceCompilationCacheParamsBuilder() : result_(new SetProduceCompilationCacheParams()) { }

    template<int STEP> SetProduceCompilationCacheParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetProduceCompilationCacheParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetProduceCompilationCacheParams> result_;
  };

  static SetProduceCompilationCacheParamsBuilder<0> Builder() {
    return SetProduceCompilationCacheParamsBuilder<0>();
  }

 private:
  SetProduceCompilationCacheParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetProduceCompilationCacheParams);
};


// Result for the SetProduceCompilationCache command.
class HEADLESS_EXPORT SetProduceCompilationCacheResult {
 public:
  static std::unique_ptr<SetProduceCompilationCacheResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetProduceCompilationCacheResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetProduceCompilationCacheResult> Clone() const;

  template<int STATE>
  class SetProduceCompilationCacheResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetProduceCompilationCacheResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetProduceCompilationCacheResult;
    SetProduceCompilationCacheResultBuilder() : result_(new SetProduceCompilationCacheResult()) { }

    template<int STEP> SetProduceCompilationCacheResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetProduceCompilationCacheResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetProduceCompilationCacheResult> result_;
  };

  static SetProduceCompilationCacheResultBuilder<0> Builder() {
    return SetProduceCompilationCacheResultBuilder<0>();
  }

 private:
  SetProduceCompilationCacheResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetProduceCompilationCacheResult);
};


// Parameters for the AddCompilationCache command.
class HEADLESS_EXPORT AddCompilationCacheParams {
 public:
  static std::unique_ptr<AddCompilationCacheParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddCompilationCacheParams() { }

  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Base64-encoded data
  protocol::Binary GetData() const { return data_; }
  void SetData(const protocol::Binary& value) { data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddCompilationCacheParams> Clone() const;

  template<int STATE>
  class AddCompilationCacheParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kDataSet = 1 << 2,
      kAllRequiredFieldsSet = (kUrlSet | kDataSet | 0)
    };

    AddCompilationCacheParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    AddCompilationCacheParamsBuilder<STATE | kDataSet>& SetData(const protocol::Binary& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    std::unique_ptr<AddCompilationCacheParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddCompilationCacheParams;
    AddCompilationCacheParamsBuilder() : result_(new AddCompilationCacheParams()) { }

    template<int STEP> AddCompilationCacheParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddCompilationCacheParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddCompilationCacheParams> result_;
  };

  static AddCompilationCacheParamsBuilder<0> Builder() {
    return AddCompilationCacheParamsBuilder<0>();
  }

 private:
  AddCompilationCacheParams() { }

  std::string url_;
  protocol::Binary data_;

  DISALLOW_COPY_AND_ASSIGN(AddCompilationCacheParams);
};


// Result for the AddCompilationCache command.
class HEADLESS_EXPORT AddCompilationCacheResult {
 public:
  static std::unique_ptr<AddCompilationCacheResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~AddCompilationCacheResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<AddCompilationCacheResult> Clone() const;

  template<int STATE>
  class AddCompilationCacheResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<AddCompilationCacheResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class AddCompilationCacheResult;
    AddCompilationCacheResultBuilder() : result_(new AddCompilationCacheResult()) { }

    template<int STEP> AddCompilationCacheResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<AddCompilationCacheResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<AddCompilationCacheResult> result_;
  };

  static AddCompilationCacheResultBuilder<0> Builder() {
    return AddCompilationCacheResultBuilder<0>();
  }

 private:
  AddCompilationCacheResult() { }


  DISALLOW_COPY_AND_ASSIGN(AddCompilationCacheResult);
};


// Parameters for the ClearCompilationCache command.
class HEADLESS_EXPORT ClearCompilationCacheParams {
 public:
  static std::unique_ptr<ClearCompilationCacheParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearCompilationCacheParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearCompilationCacheParams> Clone() const;

  template<int STATE>
  class ClearCompilationCacheParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearCompilationCacheParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearCompilationCacheParams;
    ClearCompilationCacheParamsBuilder() : result_(new ClearCompilationCacheParams()) { }

    template<int STEP> ClearCompilationCacheParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearCompilationCacheParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearCompilationCacheParams> result_;
  };

  static ClearCompilationCacheParamsBuilder<0> Builder() {
    return ClearCompilationCacheParamsBuilder<0>();
  }

 private:
  ClearCompilationCacheParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearCompilationCacheParams);
};


// Result for the ClearCompilationCache command.
class HEADLESS_EXPORT ClearCompilationCacheResult {
 public:
  static std::unique_ptr<ClearCompilationCacheResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearCompilationCacheResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearCompilationCacheResult> Clone() const;

  template<int STATE>
  class ClearCompilationCacheResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearCompilationCacheResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearCompilationCacheResult;
    ClearCompilationCacheResultBuilder() : result_(new ClearCompilationCacheResult()) { }

    template<int STEP> ClearCompilationCacheResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearCompilationCacheResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearCompilationCacheResult> result_;
  };

  static ClearCompilationCacheResultBuilder<0> Builder() {
    return ClearCompilationCacheResultBuilder<0>();
  }

 private:
  ClearCompilationCacheResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearCompilationCacheResult);
};


// Parameters for the GenerateTestReport command.
class HEADLESS_EXPORT GenerateTestReportParams {
 public:
  static std::unique_ptr<GenerateTestReportParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GenerateTestReportParams() { }

  // Message to be displayed in the report.
  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // Specifies the endpoint group to deliver the report to.
  bool HasGroup() const { return !!group_; }
  std::string GetGroup() const { DCHECK(HasGroup()); return group_.value(); }
  void SetGroup(const std::string& value) { group_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GenerateTestReportParams> Clone() const;

  template<int STATE>
  class GenerateTestReportParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kMessageSet = 1 << 1,
      kAllRequiredFieldsSet = (kMessageSet | 0)
    };

    GenerateTestReportParamsBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    GenerateTestReportParamsBuilder<STATE>& SetGroup(const std::string& value) {
      result_->SetGroup(value);
      return *this;
    }

    std::unique_ptr<GenerateTestReportParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GenerateTestReportParams;
    GenerateTestReportParamsBuilder() : result_(new GenerateTestReportParams()) { }

    template<int STEP> GenerateTestReportParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GenerateTestReportParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GenerateTestReportParams> result_;
  };

  static GenerateTestReportParamsBuilder<0> Builder() {
    return GenerateTestReportParamsBuilder<0>();
  }

 private:
  GenerateTestReportParams() { }

  std::string message_;
  base::Optional<std::string> group_;

  DISALLOW_COPY_AND_ASSIGN(GenerateTestReportParams);
};


// Result for the GenerateTestReport command.
class HEADLESS_EXPORT GenerateTestReportResult {
 public:
  static std::unique_ptr<GenerateTestReportResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GenerateTestReportResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GenerateTestReportResult> Clone() const;

  template<int STATE>
  class GenerateTestReportResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GenerateTestReportResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GenerateTestReportResult;
    GenerateTestReportResultBuilder() : result_(new GenerateTestReportResult()) { }

    template<int STEP> GenerateTestReportResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GenerateTestReportResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GenerateTestReportResult> result_;
  };

  static GenerateTestReportResultBuilder<0> Builder() {
    return GenerateTestReportResultBuilder<0>();
  }

 private:
  GenerateTestReportResult() { }


  DISALLOW_COPY_AND_ASSIGN(GenerateTestReportResult);
};


// Parameters for the WaitForDebugger command.
class HEADLESS_EXPORT WaitForDebuggerParams {
 public:
  static std::unique_ptr<WaitForDebuggerParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WaitForDebuggerParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WaitForDebuggerParams> Clone() const;

  template<int STATE>
  class WaitForDebuggerParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<WaitForDebuggerParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WaitForDebuggerParams;
    WaitForDebuggerParamsBuilder() : result_(new WaitForDebuggerParams()) { }

    template<int STEP> WaitForDebuggerParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WaitForDebuggerParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WaitForDebuggerParams> result_;
  };

  static WaitForDebuggerParamsBuilder<0> Builder() {
    return WaitForDebuggerParamsBuilder<0>();
  }

 private:
  WaitForDebuggerParams() { }


  DISALLOW_COPY_AND_ASSIGN(WaitForDebuggerParams);
};


// Result for the WaitForDebugger command.
class HEADLESS_EXPORT WaitForDebuggerResult {
 public:
  static std::unique_ptr<WaitForDebuggerResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~WaitForDebuggerResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WaitForDebuggerResult> Clone() const;

  template<int STATE>
  class WaitForDebuggerResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<WaitForDebuggerResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WaitForDebuggerResult;
    WaitForDebuggerResultBuilder() : result_(new WaitForDebuggerResult()) { }

    template<int STEP> WaitForDebuggerResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WaitForDebuggerResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WaitForDebuggerResult> result_;
  };

  static WaitForDebuggerResultBuilder<0> Builder() {
    return WaitForDebuggerResultBuilder<0>();
  }

 private:
  WaitForDebuggerResult() { }


  DISALLOW_COPY_AND_ASSIGN(WaitForDebuggerResult);
};


// Parameters for the SetInterceptFileChooserDialog command.
class HEADLESS_EXPORT SetInterceptFileChooserDialogParams {
 public:
  static std::unique_ptr<SetInterceptFileChooserDialogParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetInterceptFileChooserDialogParams() { }

  bool GetEnabled() const { return enabled_; }
  void SetEnabled(bool value) { enabled_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetInterceptFileChooserDialogParams> Clone() const;

  template<int STATE>
  class SetInterceptFileChooserDialogParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEnabledSet = 1 << 1,
      kAllRequiredFieldsSet = (kEnabledSet | 0)
    };

    SetInterceptFileChooserDialogParamsBuilder<STATE | kEnabledSet>& SetEnabled(bool value) {
      static_assert(!(STATE & kEnabledSet), "property enabled should not have already been set");
      result_->SetEnabled(value);
      return CastState<kEnabledSet>();
    }

    std::unique_ptr<SetInterceptFileChooserDialogParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetInterceptFileChooserDialogParams;
    SetInterceptFileChooserDialogParamsBuilder() : result_(new SetInterceptFileChooserDialogParams()) { }

    template<int STEP> SetInterceptFileChooserDialogParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetInterceptFileChooserDialogParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetInterceptFileChooserDialogParams> result_;
  };

  static SetInterceptFileChooserDialogParamsBuilder<0> Builder() {
    return SetInterceptFileChooserDialogParamsBuilder<0>();
  }

 private:
  SetInterceptFileChooserDialogParams() { }

  bool enabled_;

  DISALLOW_COPY_AND_ASSIGN(SetInterceptFileChooserDialogParams);
};


// Result for the SetInterceptFileChooserDialog command.
class HEADLESS_EXPORT SetInterceptFileChooserDialogResult {
 public:
  static std::unique_ptr<SetInterceptFileChooserDialogResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetInterceptFileChooserDialogResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetInterceptFileChooserDialogResult> Clone() const;

  template<int STATE>
  class SetInterceptFileChooserDialogResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetInterceptFileChooserDialogResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetInterceptFileChooserDialogResult;
    SetInterceptFileChooserDialogResultBuilder() : result_(new SetInterceptFileChooserDialogResult()) { }

    template<int STEP> SetInterceptFileChooserDialogResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetInterceptFileChooserDialogResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetInterceptFileChooserDialogResult> result_;
  };

  static SetInterceptFileChooserDialogResultBuilder<0> Builder() {
    return SetInterceptFileChooserDialogResultBuilder<0>();
  }

 private:
  SetInterceptFileChooserDialogResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetInterceptFileChooserDialogResult);
};


// Parameters for the DomContentEventFired event.
class HEADLESS_EXPORT DomContentEventFiredParams {
 public:
  static std::unique_ptr<DomContentEventFiredParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DomContentEventFiredParams() { }

  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DomContentEventFiredParams> Clone() const;

  template<int STATE>
  class DomContentEventFiredParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
      kAllRequiredFieldsSet = (kTimestampSet | 0)
    };

    DomContentEventFiredParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<DomContentEventFiredParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DomContentEventFiredParams;
    DomContentEventFiredParamsBuilder() : result_(new DomContentEventFiredParams()) { }

    template<int STEP> DomContentEventFiredParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DomContentEventFiredParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DomContentEventFiredParams> result_;
  };

  static DomContentEventFiredParamsBuilder<0> Builder() {
    return DomContentEventFiredParamsBuilder<0>();
  }

 private:
  DomContentEventFiredParams() { }

  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(DomContentEventFiredParams);
};


// Parameters for the FileChooserOpened event.
class HEADLESS_EXPORT FileChooserOpenedParams {
 public:
  static std::unique_ptr<FileChooserOpenedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FileChooserOpenedParams() { }

  // Id of the frame containing input node.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Input node id.
  int GetBackendNodeId() const { return backend_node_id_; }
  void SetBackendNodeId(int value) { backend_node_id_ = value; }

  // Input mode.
  ::headless::page::FileChooserOpenedMode GetMode() const { return mode_; }
  void SetMode(::headless::page::FileChooserOpenedMode value) { mode_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FileChooserOpenedParams> Clone() const;

  template<int STATE>
  class FileChooserOpenedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kBackendNodeIdSet = 1 << 2,
    kModeSet = 1 << 3,
      kAllRequiredFieldsSet = (kFrameIdSet | kBackendNodeIdSet | kModeSet | 0)
    };

    FileChooserOpenedParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    FileChooserOpenedParamsBuilder<STATE | kBackendNodeIdSet>& SetBackendNodeId(int value) {
      static_assert(!(STATE & kBackendNodeIdSet), "property backendNodeId should not have already been set");
      result_->SetBackendNodeId(value);
      return CastState<kBackendNodeIdSet>();
    }

    FileChooserOpenedParamsBuilder<STATE | kModeSet>& SetMode(::headless::page::FileChooserOpenedMode value) {
      static_assert(!(STATE & kModeSet), "property mode should not have already been set");
      result_->SetMode(value);
      return CastState<kModeSet>();
    }

    std::unique_ptr<FileChooserOpenedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FileChooserOpenedParams;
    FileChooserOpenedParamsBuilder() : result_(new FileChooserOpenedParams()) { }

    template<int STEP> FileChooserOpenedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FileChooserOpenedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FileChooserOpenedParams> result_;
  };

  static FileChooserOpenedParamsBuilder<0> Builder() {
    return FileChooserOpenedParamsBuilder<0>();
  }

 private:
  FileChooserOpenedParams() { }

  std::string frame_id_;
  int backend_node_id_;
  ::headless::page::FileChooserOpenedMode mode_;

  DISALLOW_COPY_AND_ASSIGN(FileChooserOpenedParams);
};


// Parameters for the FrameAttached event.
class HEADLESS_EXPORT FrameAttachedParams {
 public:
  static std::unique_ptr<FrameAttachedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameAttachedParams() { }

  // Id of the frame that has been attached.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Parent frame identifier.
  std::string GetParentFrameId() const { return parent_frame_id_; }
  void SetParentFrameId(const std::string& value) { parent_frame_id_ = value; }

  // JavaScript stack trace of when frame was attached, only set if frame initiated from script.
  bool HasStack() const { return !!stack_; }
  const ::headless::runtime::StackTrace* GetStack() const { DCHECK(HasStack()); return stack_.value().get(); }
  void SetStack(std::unique_ptr<::headless::runtime::StackTrace> value) { stack_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameAttachedParams> Clone() const;

  template<int STATE>
  class FrameAttachedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kParentFrameIdSet = 1 << 2,
      kAllRequiredFieldsSet = (kFrameIdSet | kParentFrameIdSet | 0)
    };

    FrameAttachedParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    FrameAttachedParamsBuilder<STATE | kParentFrameIdSet>& SetParentFrameId(const std::string& value) {
      static_assert(!(STATE & kParentFrameIdSet), "property parentFrameId should not have already been set");
      result_->SetParentFrameId(value);
      return CastState<kParentFrameIdSet>();
    }

    FrameAttachedParamsBuilder<STATE>& SetStack(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetStack(std::move(value));
      return *this;
    }

    std::unique_ptr<FrameAttachedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameAttachedParams;
    FrameAttachedParamsBuilder() : result_(new FrameAttachedParams()) { }

    template<int STEP> FrameAttachedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameAttachedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameAttachedParams> result_;
  };

  static FrameAttachedParamsBuilder<0> Builder() {
    return FrameAttachedParamsBuilder<0>();
  }

 private:
  FrameAttachedParams() { }

  std::string frame_id_;
  std::string parent_frame_id_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> stack_;

  DISALLOW_COPY_AND_ASSIGN(FrameAttachedParams);
};


// Parameters for the FrameClearedScheduledNavigation event.
class HEADLESS_EXPORT FrameClearedScheduledNavigationParams {
 public:
  static std::unique_ptr<FrameClearedScheduledNavigationParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameClearedScheduledNavigationParams() { }

  // Id of the frame that has cleared its scheduled navigation.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameClearedScheduledNavigationParams> Clone() const;

  template<int STATE>
  class FrameClearedScheduledNavigationParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    FrameClearedScheduledNavigationParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<FrameClearedScheduledNavigationParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameClearedScheduledNavigationParams;
    FrameClearedScheduledNavigationParamsBuilder() : result_(new FrameClearedScheduledNavigationParams()) { }

    template<int STEP> FrameClearedScheduledNavigationParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameClearedScheduledNavigationParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameClearedScheduledNavigationParams> result_;
  };

  static FrameClearedScheduledNavigationParamsBuilder<0> Builder() {
    return FrameClearedScheduledNavigationParamsBuilder<0>();
  }

 private:
  FrameClearedScheduledNavigationParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(FrameClearedScheduledNavigationParams);
};


// Parameters for the FrameDetached event.
class HEADLESS_EXPORT FrameDetachedParams {
 public:
  static std::unique_ptr<FrameDetachedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameDetachedParams() { }

  // Id of the frame that has been detached.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameDetachedParams> Clone() const;

  template<int STATE>
  class FrameDetachedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    FrameDetachedParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<FrameDetachedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameDetachedParams;
    FrameDetachedParamsBuilder() : result_(new FrameDetachedParams()) { }

    template<int STEP> FrameDetachedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameDetachedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameDetachedParams> result_;
  };

  static FrameDetachedParamsBuilder<0> Builder() {
    return FrameDetachedParamsBuilder<0>();
  }

 private:
  FrameDetachedParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(FrameDetachedParams);
};


// Parameters for the FrameNavigated event.
class HEADLESS_EXPORT FrameNavigatedParams {
 public:
  static std::unique_ptr<FrameNavigatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameNavigatedParams() { }

  // Frame object.
  const ::headless::page::Frame* GetFrame() const { return frame_.get(); }
  void SetFrame(std::unique_ptr<::headless::page::Frame> value) { frame_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameNavigatedParams> Clone() const;

  template<int STATE>
  class FrameNavigatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameSet | 0)
    };

    FrameNavigatedParamsBuilder<STATE | kFrameSet>& SetFrame(std::unique_ptr<::headless::page::Frame> value) {
      static_assert(!(STATE & kFrameSet), "property frame should not have already been set");
      result_->SetFrame(std::move(value));
      return CastState<kFrameSet>();
    }

    std::unique_ptr<FrameNavigatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameNavigatedParams;
    FrameNavigatedParamsBuilder() : result_(new FrameNavigatedParams()) { }

    template<int STEP> FrameNavigatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameNavigatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameNavigatedParams> result_;
  };

  static FrameNavigatedParamsBuilder<0> Builder() {
    return FrameNavigatedParamsBuilder<0>();
  }

 private:
  FrameNavigatedParams() { }

  std::unique_ptr<::headless::page::Frame> frame_;

  DISALLOW_COPY_AND_ASSIGN(FrameNavigatedParams);
};


// Parameters for the FrameResized event.
class HEADLESS_EXPORT FrameResizedParams {
 public:
  static std::unique_ptr<FrameResizedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameResizedParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameResizedParams> Clone() const;

  template<int STATE>
  class FrameResizedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<FrameResizedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameResizedParams;
    FrameResizedParamsBuilder() : result_(new FrameResizedParams()) { }

    template<int STEP> FrameResizedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameResizedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameResizedParams> result_;
  };

  static FrameResizedParamsBuilder<0> Builder() {
    return FrameResizedParamsBuilder<0>();
  }

 private:
  FrameResizedParams() { }


  DISALLOW_COPY_AND_ASSIGN(FrameResizedParams);
};


// Parameters for the FrameRequestedNavigation event.
class HEADLESS_EXPORT FrameRequestedNavigationParams {
 public:
  static std::unique_ptr<FrameRequestedNavigationParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameRequestedNavigationParams() { }

  // Id of the frame that is being navigated.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // The reason for the navigation.
  ::headless::page::ClientNavigationReason GetReason() const { return reason_; }
  void SetReason(::headless::page::ClientNavigationReason value) { reason_ = value; }

  // The destination URL for the requested navigation.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // The disposition for the navigation.
  ::headless::page::ClientNavigationDisposition GetDisposition() const { return disposition_; }
  void SetDisposition(::headless::page::ClientNavigationDisposition value) { disposition_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameRequestedNavigationParams> Clone() const;

  template<int STATE>
  class FrameRequestedNavigationParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kReasonSet = 1 << 2,
    kUrlSet = 1 << 3,
    kDispositionSet = 1 << 4,
      kAllRequiredFieldsSet = (kFrameIdSet | kReasonSet | kUrlSet | kDispositionSet | 0)
    };

    FrameRequestedNavigationParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    FrameRequestedNavigationParamsBuilder<STATE | kReasonSet>& SetReason(::headless::page::ClientNavigationReason value) {
      static_assert(!(STATE & kReasonSet), "property reason should not have already been set");
      result_->SetReason(value);
      return CastState<kReasonSet>();
    }

    FrameRequestedNavigationParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    FrameRequestedNavigationParamsBuilder<STATE | kDispositionSet>& SetDisposition(::headless::page::ClientNavigationDisposition value) {
      static_assert(!(STATE & kDispositionSet), "property disposition should not have already been set");
      result_->SetDisposition(value);
      return CastState<kDispositionSet>();
    }

    std::unique_ptr<FrameRequestedNavigationParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameRequestedNavigationParams;
    FrameRequestedNavigationParamsBuilder() : result_(new FrameRequestedNavigationParams()) { }

    template<int STEP> FrameRequestedNavigationParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameRequestedNavigationParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameRequestedNavigationParams> result_;
  };

  static FrameRequestedNavigationParamsBuilder<0> Builder() {
    return FrameRequestedNavigationParamsBuilder<0>();
  }

 private:
  FrameRequestedNavigationParams() { }

  std::string frame_id_;
  ::headless::page::ClientNavigationReason reason_;
  std::string url_;
  ::headless::page::ClientNavigationDisposition disposition_;

  DISALLOW_COPY_AND_ASSIGN(FrameRequestedNavigationParams);
};


// Parameters for the FrameScheduledNavigation event.
class HEADLESS_EXPORT FrameScheduledNavigationParams {
 public:
  static std::unique_ptr<FrameScheduledNavigationParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameScheduledNavigationParams() { }

  // Id of the frame that has scheduled a navigation.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Delay (in seconds) until the navigation is scheduled to begin. The navigation is not
  // guaranteed to start.
  double GetDelay() const { return delay_; }
  void SetDelay(double value) { delay_ = value; }

  // The reason for the navigation.
  ::headless::page::ClientNavigationReason GetReason() const { return reason_; }
  void SetReason(::headless::page::ClientNavigationReason value) { reason_ = value; }

  // The destination URL for the scheduled navigation.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameScheduledNavigationParams> Clone() const;

  template<int STATE>
  class FrameScheduledNavigationParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kDelaySet = 1 << 2,
    kReasonSet = 1 << 3,
    kUrlSet = 1 << 4,
      kAllRequiredFieldsSet = (kFrameIdSet | kDelaySet | kReasonSet | kUrlSet | 0)
    };

    FrameScheduledNavigationParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    FrameScheduledNavigationParamsBuilder<STATE | kDelaySet>& SetDelay(double value) {
      static_assert(!(STATE & kDelaySet), "property delay should not have already been set");
      result_->SetDelay(value);
      return CastState<kDelaySet>();
    }

    FrameScheduledNavigationParamsBuilder<STATE | kReasonSet>& SetReason(::headless::page::ClientNavigationReason value) {
      static_assert(!(STATE & kReasonSet), "property reason should not have already been set");
      result_->SetReason(value);
      return CastState<kReasonSet>();
    }

    FrameScheduledNavigationParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    std::unique_ptr<FrameScheduledNavigationParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameScheduledNavigationParams;
    FrameScheduledNavigationParamsBuilder() : result_(new FrameScheduledNavigationParams()) { }

    template<int STEP> FrameScheduledNavigationParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameScheduledNavigationParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameScheduledNavigationParams> result_;
  };

  static FrameScheduledNavigationParamsBuilder<0> Builder() {
    return FrameScheduledNavigationParamsBuilder<0>();
  }

 private:
  FrameScheduledNavigationParams() { }

  std::string frame_id_;
  double delay_;
  ::headless::page::ClientNavigationReason reason_;
  std::string url_;

  DISALLOW_COPY_AND_ASSIGN(FrameScheduledNavigationParams);
};


// Parameters for the FrameStartedLoading event.
class HEADLESS_EXPORT FrameStartedLoadingParams {
 public:
  static std::unique_ptr<FrameStartedLoadingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameStartedLoadingParams() { }

  // Id of the frame that has started loading.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameStartedLoadingParams> Clone() const;

  template<int STATE>
  class FrameStartedLoadingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    FrameStartedLoadingParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<FrameStartedLoadingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameStartedLoadingParams;
    FrameStartedLoadingParamsBuilder() : result_(new FrameStartedLoadingParams()) { }

    template<int STEP> FrameStartedLoadingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameStartedLoadingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameStartedLoadingParams> result_;
  };

  static FrameStartedLoadingParamsBuilder<0> Builder() {
    return FrameStartedLoadingParamsBuilder<0>();
  }

 private:
  FrameStartedLoadingParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(FrameStartedLoadingParams);
};


// Parameters for the FrameStoppedLoading event.
class HEADLESS_EXPORT FrameStoppedLoadingParams {
 public:
  static std::unique_ptr<FrameStoppedLoadingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameStoppedLoadingParams() { }

  // Id of the frame that has stopped loading.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameStoppedLoadingParams> Clone() const;

  template<int STATE>
  class FrameStoppedLoadingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    FrameStoppedLoadingParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<FrameStoppedLoadingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameStoppedLoadingParams;
    FrameStoppedLoadingParamsBuilder() : result_(new FrameStoppedLoadingParams()) { }

    template<int STEP> FrameStoppedLoadingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameStoppedLoadingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameStoppedLoadingParams> result_;
  };

  static FrameStoppedLoadingParamsBuilder<0> Builder() {
    return FrameStoppedLoadingParamsBuilder<0>();
  }

 private:
  FrameStoppedLoadingParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(FrameStoppedLoadingParams);
};


// Parameters for the DownloadWillBegin event.
class HEADLESS_EXPORT DownloadWillBeginParams {
 public:
  static std::unique_ptr<DownloadWillBeginParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DownloadWillBeginParams() { }

  // Id of the frame that caused download to begin.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Global unique identifier of the download.
  std::string GetGuid() const { return guid_; }
  void SetGuid(const std::string& value) { guid_ = value; }

  // URL of the resource being downloaded.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Suggested file name of the resource (the actual name of the file saved on disk may differ).
  std::string GetSuggestedFilename() const { return suggested_filename_; }
  void SetSuggestedFilename(const std::string& value) { suggested_filename_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DownloadWillBeginParams> Clone() const;

  template<int STATE>
  class DownloadWillBeginParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kGuidSet = 1 << 2,
    kUrlSet = 1 << 3,
    kSuggestedFilenameSet = 1 << 4,
      kAllRequiredFieldsSet = (kFrameIdSet | kGuidSet | kUrlSet | kSuggestedFilenameSet | 0)
    };

    DownloadWillBeginParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    DownloadWillBeginParamsBuilder<STATE | kGuidSet>& SetGuid(const std::string& value) {
      static_assert(!(STATE & kGuidSet), "property guid should not have already been set");
      result_->SetGuid(value);
      return CastState<kGuidSet>();
    }

    DownloadWillBeginParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    DownloadWillBeginParamsBuilder<STATE | kSuggestedFilenameSet>& SetSuggestedFilename(const std::string& value) {
      static_assert(!(STATE & kSuggestedFilenameSet), "property suggestedFilename should not have already been set");
      result_->SetSuggestedFilename(value);
      return CastState<kSuggestedFilenameSet>();
    }

    std::unique_ptr<DownloadWillBeginParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DownloadWillBeginParams;
    DownloadWillBeginParamsBuilder() : result_(new DownloadWillBeginParams()) { }

    template<int STEP> DownloadWillBeginParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DownloadWillBeginParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DownloadWillBeginParams> result_;
  };

  static DownloadWillBeginParamsBuilder<0> Builder() {
    return DownloadWillBeginParamsBuilder<0>();
  }

 private:
  DownloadWillBeginParams() { }

  std::string frame_id_;
  std::string guid_;
  std::string url_;
  std::string suggested_filename_;

  DISALLOW_COPY_AND_ASSIGN(DownloadWillBeginParams);
};


// Parameters for the DownloadProgress event.
class HEADLESS_EXPORT DownloadProgressParams {
 public:
  static std::unique_ptr<DownloadProgressParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DownloadProgressParams() { }

  // Global unique identifier of the download.
  std::string GetGuid() const { return guid_; }
  void SetGuid(const std::string& value) { guid_ = value; }

  // Total expected bytes to download.
  double GetTotalBytes() const { return total_bytes_; }
  void SetTotalBytes(double value) { total_bytes_ = value; }

  // Total bytes received.
  double GetReceivedBytes() const { return received_bytes_; }
  void SetReceivedBytes(double value) { received_bytes_ = value; }

  // Download status.
  ::headless::page::DownloadProgressState GetState() const { return state_; }
  void SetState(::headless::page::DownloadProgressState value) { state_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DownloadProgressParams> Clone() const;

  template<int STATE>
  class DownloadProgressParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kGuidSet = 1 << 1,
    kTotalBytesSet = 1 << 2,
    kReceivedBytesSet = 1 << 3,
    kStateSet = 1 << 4,
      kAllRequiredFieldsSet = (kGuidSet | kTotalBytesSet | kReceivedBytesSet | kStateSet | 0)
    };

    DownloadProgressParamsBuilder<STATE | kGuidSet>& SetGuid(const std::string& value) {
      static_assert(!(STATE & kGuidSet), "property guid should not have already been set");
      result_->SetGuid(value);
      return CastState<kGuidSet>();
    }

    DownloadProgressParamsBuilder<STATE | kTotalBytesSet>& SetTotalBytes(double value) {
      static_assert(!(STATE & kTotalBytesSet), "property totalBytes should not have already been set");
      result_->SetTotalBytes(value);
      return CastState<kTotalBytesSet>();
    }

    DownloadProgressParamsBuilder<STATE | kReceivedBytesSet>& SetReceivedBytes(double value) {
      static_assert(!(STATE & kReceivedBytesSet), "property receivedBytes should not have already been set");
      result_->SetReceivedBytes(value);
      return CastState<kReceivedBytesSet>();
    }

    DownloadProgressParamsBuilder<STATE | kStateSet>& SetState(::headless::page::DownloadProgressState value) {
      static_assert(!(STATE & kStateSet), "property state should not have already been set");
      result_->SetState(value);
      return CastState<kStateSet>();
    }

    std::unique_ptr<DownloadProgressParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DownloadProgressParams;
    DownloadProgressParamsBuilder() : result_(new DownloadProgressParams()) { }

    template<int STEP> DownloadProgressParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DownloadProgressParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DownloadProgressParams> result_;
  };

  static DownloadProgressParamsBuilder<0> Builder() {
    return DownloadProgressParamsBuilder<0>();
  }

 private:
  DownloadProgressParams() { }

  std::string guid_;
  double total_bytes_;
  double received_bytes_;
  ::headless::page::DownloadProgressState state_;

  DISALLOW_COPY_AND_ASSIGN(DownloadProgressParams);
};


// Parameters for the InterstitialHidden event.
class HEADLESS_EXPORT InterstitialHiddenParams {
 public:
  static std::unique_ptr<InterstitialHiddenParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~InterstitialHiddenParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InterstitialHiddenParams> Clone() const;

  template<int STATE>
  class InterstitialHiddenParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<InterstitialHiddenParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InterstitialHiddenParams;
    InterstitialHiddenParamsBuilder() : result_(new InterstitialHiddenParams()) { }

    template<int STEP> InterstitialHiddenParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InterstitialHiddenParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InterstitialHiddenParams> result_;
  };

  static InterstitialHiddenParamsBuilder<0> Builder() {
    return InterstitialHiddenParamsBuilder<0>();
  }

 private:
  InterstitialHiddenParams() { }


  DISALLOW_COPY_AND_ASSIGN(InterstitialHiddenParams);
};


// Parameters for the InterstitialShown event.
class HEADLESS_EXPORT InterstitialShownParams {
 public:
  static std::unique_ptr<InterstitialShownParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~InterstitialShownParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<InterstitialShownParams> Clone() const;

  template<int STATE>
  class InterstitialShownParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<InterstitialShownParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class InterstitialShownParams;
    InterstitialShownParamsBuilder() : result_(new InterstitialShownParams()) { }

    template<int STEP> InterstitialShownParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<InterstitialShownParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<InterstitialShownParams> result_;
  };

  static InterstitialShownParamsBuilder<0> Builder() {
    return InterstitialShownParamsBuilder<0>();
  }

 private:
  InterstitialShownParams() { }


  DISALLOW_COPY_AND_ASSIGN(InterstitialShownParams);
};


// Parameters for the JavascriptDialogClosed event.
class HEADLESS_EXPORT JavascriptDialogClosedParams {
 public:
  static std::unique_ptr<JavascriptDialogClosedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~JavascriptDialogClosedParams() { }

  // Whether dialog was confirmed.
  bool GetResult() const { return result_; }
  void SetResult(bool value) { result_ = value; }

  // User input in case of prompt.
  std::string GetUserInput() const { return user_input_; }
  void SetUserInput(const std::string& value) { user_input_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<JavascriptDialogClosedParams> Clone() const;

  template<int STATE>
  class JavascriptDialogClosedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kResultSet = 1 << 1,
    kUserInputSet = 1 << 2,
      kAllRequiredFieldsSet = (kResultSet | kUserInputSet | 0)
    };

    JavascriptDialogClosedParamsBuilder<STATE | kResultSet>& SetResult(bool value) {
      static_assert(!(STATE & kResultSet), "property result should not have already been set");
      result_->SetResult(value);
      return CastState<kResultSet>();
    }

    JavascriptDialogClosedParamsBuilder<STATE | kUserInputSet>& SetUserInput(const std::string& value) {
      static_assert(!(STATE & kUserInputSet), "property userInput should not have already been set");
      result_->SetUserInput(value);
      return CastState<kUserInputSet>();
    }

    std::unique_ptr<JavascriptDialogClosedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class JavascriptDialogClosedParams;
    JavascriptDialogClosedParamsBuilder() : result_(new JavascriptDialogClosedParams()) { }

    template<int STEP> JavascriptDialogClosedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<JavascriptDialogClosedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<JavascriptDialogClosedParams> result_;
  };

  static JavascriptDialogClosedParamsBuilder<0> Builder() {
    return JavascriptDialogClosedParamsBuilder<0>();
  }

 private:
  JavascriptDialogClosedParams() { }

  bool result_;
  std::string user_input_;

  DISALLOW_COPY_AND_ASSIGN(JavascriptDialogClosedParams);
};


// Parameters for the JavascriptDialogOpening event.
class HEADLESS_EXPORT JavascriptDialogOpeningParams {
 public:
  static std::unique_ptr<JavascriptDialogOpeningParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~JavascriptDialogOpeningParams() { }

  // Frame url.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Message that will be displayed by the dialog.
  std::string GetMessage() const { return message_; }
  void SetMessage(const std::string& value) { message_ = value; }

  // Dialog type.
  ::headless::page::DialogType GetType() const { return type_; }
  void SetType(::headless::page::DialogType value) { type_ = value; }

  // True iff browser is capable showing or acting on the given dialog. When browser has no
  // dialog handler for given target, calling alert while Page domain is engaged will stall
  // the page execution. Execution can be resumed via calling Page.handleJavaScriptDialog.
  bool GetHasBrowserHandler() const { return has_browser_handler_; }
  void SetHasBrowserHandler(bool value) { has_browser_handler_ = value; }

  // Default dialog prompt.
  bool HasDefaultPrompt() const { return !!default_prompt_; }
  std::string GetDefaultPrompt() const { DCHECK(HasDefaultPrompt()); return default_prompt_.value(); }
  void SetDefaultPrompt(const std::string& value) { default_prompt_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<JavascriptDialogOpeningParams> Clone() const;

  template<int STATE>
  class JavascriptDialogOpeningParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kMessageSet = 1 << 2,
    kTypeSet = 1 << 3,
    kHasBrowserHandlerSet = 1 << 4,
      kAllRequiredFieldsSet = (kUrlSet | kMessageSet | kTypeSet | kHasBrowserHandlerSet | 0)
    };

    JavascriptDialogOpeningParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    JavascriptDialogOpeningParamsBuilder<STATE | kMessageSet>& SetMessage(const std::string& value) {
      static_assert(!(STATE & kMessageSet), "property message should not have already been set");
      result_->SetMessage(value);
      return CastState<kMessageSet>();
    }

    JavascriptDialogOpeningParamsBuilder<STATE | kTypeSet>& SetType(::headless::page::DialogType value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    JavascriptDialogOpeningParamsBuilder<STATE | kHasBrowserHandlerSet>& SetHasBrowserHandler(bool value) {
      static_assert(!(STATE & kHasBrowserHandlerSet), "property hasBrowserHandler should not have already been set");
      result_->SetHasBrowserHandler(value);
      return CastState<kHasBrowserHandlerSet>();
    }

    JavascriptDialogOpeningParamsBuilder<STATE>& SetDefaultPrompt(const std::string& value) {
      result_->SetDefaultPrompt(value);
      return *this;
    }

    std::unique_ptr<JavascriptDialogOpeningParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class JavascriptDialogOpeningParams;
    JavascriptDialogOpeningParamsBuilder() : result_(new JavascriptDialogOpeningParams()) { }

    template<int STEP> JavascriptDialogOpeningParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<JavascriptDialogOpeningParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<JavascriptDialogOpeningParams> result_;
  };

  static JavascriptDialogOpeningParamsBuilder<0> Builder() {
    return JavascriptDialogOpeningParamsBuilder<0>();
  }

 private:
  JavascriptDialogOpeningParams() { }

  std::string url_;
  std::string message_;
  ::headless::page::DialogType type_;
  bool has_browser_handler_;
  base::Optional<std::string> default_prompt_;

  DISALLOW_COPY_AND_ASSIGN(JavascriptDialogOpeningParams);
};


// Parameters for the LifecycleEvent event.
class HEADLESS_EXPORT LifecycleEventParams {
 public:
  static std::unique_ptr<LifecycleEventParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LifecycleEventParams() { }

  // Id of the frame.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Loader identifier. Empty string if the request is fetched from worker.
  std::string GetLoaderId() const { return loader_id_; }
  void SetLoaderId(const std::string& value) { loader_id_ = value; }

  std::string GetName() const { return name_; }
  void SetName(const std::string& value) { name_ = value; }

  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LifecycleEventParams> Clone() const;

  template<int STATE>
  class LifecycleEventParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kLoaderIdSet = 1 << 2,
    kNameSet = 1 << 3,
    kTimestampSet = 1 << 4,
      kAllRequiredFieldsSet = (kFrameIdSet | kLoaderIdSet | kNameSet | kTimestampSet | 0)
    };

    LifecycleEventParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    LifecycleEventParamsBuilder<STATE | kLoaderIdSet>& SetLoaderId(const std::string& value) {
      static_assert(!(STATE & kLoaderIdSet), "property loaderId should not have already been set");
      result_->SetLoaderId(value);
      return CastState<kLoaderIdSet>();
    }

    LifecycleEventParamsBuilder<STATE | kNameSet>& SetName(const std::string& value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    LifecycleEventParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<LifecycleEventParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LifecycleEventParams;
    LifecycleEventParamsBuilder() : result_(new LifecycleEventParams()) { }

    template<int STEP> LifecycleEventParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LifecycleEventParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LifecycleEventParams> result_;
  };

  static LifecycleEventParamsBuilder<0> Builder() {
    return LifecycleEventParamsBuilder<0>();
  }

 private:
  LifecycleEventParams() { }

  std::string frame_id_;
  std::string loader_id_;
  std::string name_;
  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(LifecycleEventParams);
};


// Parameters for the LoadEventFired event.
class HEADLESS_EXPORT LoadEventFiredParams {
 public:
  static std::unique_ptr<LoadEventFiredParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~LoadEventFiredParams() { }

  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LoadEventFiredParams> Clone() const;

  template<int STATE>
  class LoadEventFiredParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
      kAllRequiredFieldsSet = (kTimestampSet | 0)
    };

    LoadEventFiredParamsBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    std::unique_ptr<LoadEventFiredParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LoadEventFiredParams;
    LoadEventFiredParamsBuilder() : result_(new LoadEventFiredParams()) { }

    template<int STEP> LoadEventFiredParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LoadEventFiredParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LoadEventFiredParams> result_;
  };

  static LoadEventFiredParamsBuilder<0> Builder() {
    return LoadEventFiredParamsBuilder<0>();
  }

 private:
  LoadEventFiredParams() { }

  double timestamp_;

  DISALLOW_COPY_AND_ASSIGN(LoadEventFiredParams);
};


// Parameters for the NavigatedWithinDocument event.
class HEADLESS_EXPORT NavigatedWithinDocumentParams {
 public:
  static std::unique_ptr<NavigatedWithinDocumentParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NavigatedWithinDocumentParams() { }

  // Id of the frame.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Frame's new url.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NavigatedWithinDocumentParams> Clone() const;

  template<int STATE>
  class NavigatedWithinDocumentParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kUrlSet = 1 << 2,
      kAllRequiredFieldsSet = (kFrameIdSet | kUrlSet | 0)
    };

    NavigatedWithinDocumentParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    NavigatedWithinDocumentParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    std::unique_ptr<NavigatedWithinDocumentParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NavigatedWithinDocumentParams;
    NavigatedWithinDocumentParamsBuilder() : result_(new NavigatedWithinDocumentParams()) { }

    template<int STEP> NavigatedWithinDocumentParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NavigatedWithinDocumentParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NavigatedWithinDocumentParams> result_;
  };

  static NavigatedWithinDocumentParamsBuilder<0> Builder() {
    return NavigatedWithinDocumentParamsBuilder<0>();
  }

 private:
  NavigatedWithinDocumentParams() { }

  std::string frame_id_;
  std::string url_;

  DISALLOW_COPY_AND_ASSIGN(NavigatedWithinDocumentParams);
};


// Parameters for the ScreencastFrame event.
class HEADLESS_EXPORT ScreencastFrameParams {
 public:
  static std::unique_ptr<ScreencastFrameParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScreencastFrameParams() { }

  // Base64-encoded compressed image.
  protocol::Binary GetData() const { return data_; }
  void SetData(const protocol::Binary& value) { data_ = value; }

  // Screencast frame metadata.
  const ::headless::page::ScreencastFrameMetadata* GetMetadata() const { return metadata_.get(); }
  void SetMetadata(std::unique_ptr<::headless::page::ScreencastFrameMetadata> value) { metadata_ = std::move(value); }

  // Frame number.
  int GetSessionId() const { return session_id_; }
  void SetSessionId(int value) { session_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScreencastFrameParams> Clone() const;

  template<int STATE>
  class ScreencastFrameParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataSet = 1 << 1,
    kMetadataSet = 1 << 2,
    kSessionIdSet = 1 << 3,
      kAllRequiredFieldsSet = (kDataSet | kMetadataSet | kSessionIdSet | 0)
    };

    ScreencastFrameParamsBuilder<STATE | kDataSet>& SetData(const protocol::Binary& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    ScreencastFrameParamsBuilder<STATE | kMetadataSet>& SetMetadata(std::unique_ptr<::headless::page::ScreencastFrameMetadata> value) {
      static_assert(!(STATE & kMetadataSet), "property metadata should not have already been set");
      result_->SetMetadata(std::move(value));
      return CastState<kMetadataSet>();
    }

    ScreencastFrameParamsBuilder<STATE | kSessionIdSet>& SetSessionId(int value) {
      static_assert(!(STATE & kSessionIdSet), "property sessionId should not have already been set");
      result_->SetSessionId(value);
      return CastState<kSessionIdSet>();
    }

    std::unique_ptr<ScreencastFrameParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScreencastFrameParams;
    ScreencastFrameParamsBuilder() : result_(new ScreencastFrameParams()) { }

    template<int STEP> ScreencastFrameParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScreencastFrameParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScreencastFrameParams> result_;
  };

  static ScreencastFrameParamsBuilder<0> Builder() {
    return ScreencastFrameParamsBuilder<0>();
  }

 private:
  ScreencastFrameParams() { }

  protocol::Binary data_;
  std::unique_ptr<::headless::page::ScreencastFrameMetadata> metadata_;
  int session_id_;

  DISALLOW_COPY_AND_ASSIGN(ScreencastFrameParams);
};


// Parameters for the ScreencastVisibilityChanged event.
class HEADLESS_EXPORT ScreencastVisibilityChangedParams {
 public:
  static std::unique_ptr<ScreencastVisibilityChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ScreencastVisibilityChangedParams() { }

  // True if the page is visible.
  bool GetVisible() const { return visible_; }
  void SetVisible(bool value) { visible_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ScreencastVisibilityChangedParams> Clone() const;

  template<int STATE>
  class ScreencastVisibilityChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kVisibleSet = 1 << 1,
      kAllRequiredFieldsSet = (kVisibleSet | 0)
    };

    ScreencastVisibilityChangedParamsBuilder<STATE | kVisibleSet>& SetVisible(bool value) {
      static_assert(!(STATE & kVisibleSet), "property visible should not have already been set");
      result_->SetVisible(value);
      return CastState<kVisibleSet>();
    }

    std::unique_ptr<ScreencastVisibilityChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ScreencastVisibilityChangedParams;
    ScreencastVisibilityChangedParamsBuilder() : result_(new ScreencastVisibilityChangedParams()) { }

    template<int STEP> ScreencastVisibilityChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ScreencastVisibilityChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ScreencastVisibilityChangedParams> result_;
  };

  static ScreencastVisibilityChangedParamsBuilder<0> Builder() {
    return ScreencastVisibilityChangedParamsBuilder<0>();
  }

 private:
  ScreencastVisibilityChangedParams() { }

  bool visible_;

  DISALLOW_COPY_AND_ASSIGN(ScreencastVisibilityChangedParams);
};


// Parameters for the WindowOpen event.
class HEADLESS_EXPORT WindowOpenParams {
 public:
  static std::unique_ptr<WindowOpenParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~WindowOpenParams() { }

  // The URL for the new window.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Window name.
  std::string GetWindowName() const { return window_name_; }
  void SetWindowName(const std::string& value) { window_name_ = value; }

  // An array of enabled window features.
  const std::vector<std::string>* GetWindowFeatures() const { return &window_features_; }
  void SetWindowFeatures(std::vector<std::string> value) { window_features_ = std::move(value); }

  // Whether or not it was triggered by user gesture.
  bool GetUserGesture() const { return user_gesture_; }
  void SetUserGesture(bool value) { user_gesture_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<WindowOpenParams> Clone() const;

  template<int STATE>
  class WindowOpenParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kWindowNameSet = 1 << 2,
    kWindowFeaturesSet = 1 << 3,
    kUserGestureSet = 1 << 4,
      kAllRequiredFieldsSet = (kUrlSet | kWindowNameSet | kWindowFeaturesSet | kUserGestureSet | 0)
    };

    WindowOpenParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    WindowOpenParamsBuilder<STATE | kWindowNameSet>& SetWindowName(const std::string& value) {
      static_assert(!(STATE & kWindowNameSet), "property windowName should not have already been set");
      result_->SetWindowName(value);
      return CastState<kWindowNameSet>();
    }

    WindowOpenParamsBuilder<STATE | kWindowFeaturesSet>& SetWindowFeatures(std::vector<std::string> value) {
      static_assert(!(STATE & kWindowFeaturesSet), "property windowFeatures should not have already been set");
      result_->SetWindowFeatures(std::move(value));
      return CastState<kWindowFeaturesSet>();
    }

    WindowOpenParamsBuilder<STATE | kUserGestureSet>& SetUserGesture(bool value) {
      static_assert(!(STATE & kUserGestureSet), "property userGesture should not have already been set");
      result_->SetUserGesture(value);
      return CastState<kUserGestureSet>();
    }

    std::unique_ptr<WindowOpenParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class WindowOpenParams;
    WindowOpenParamsBuilder() : result_(new WindowOpenParams()) { }

    template<int STEP> WindowOpenParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<WindowOpenParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<WindowOpenParams> result_;
  };

  static WindowOpenParamsBuilder<0> Builder() {
    return WindowOpenParamsBuilder<0>();
  }

 private:
  WindowOpenParams() { }

  std::string url_;
  std::string window_name_;
  std::vector<std::string> window_features_;
  bool user_gesture_;

  DISALLOW_COPY_AND_ASSIGN(WindowOpenParams);
};


// Parameters for the CompilationCacheProduced event.
class HEADLESS_EXPORT CompilationCacheProducedParams {
 public:
  static std::unique_ptr<CompilationCacheProducedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~CompilationCacheProducedParams() { }

  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Base64-encoded data
  protocol::Binary GetData() const { return data_; }
  void SetData(const protocol::Binary& value) { data_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<CompilationCacheProducedParams> Clone() const;

  template<int STATE>
  class CompilationCacheProducedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kDataSet = 1 << 2,
      kAllRequiredFieldsSet = (kUrlSet | kDataSet | 0)
    };

    CompilationCacheProducedParamsBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    CompilationCacheProducedParamsBuilder<STATE | kDataSet>& SetData(const protocol::Binary& value) {
      static_assert(!(STATE & kDataSet), "property data should not have already been set");
      result_->SetData(value);
      return CastState<kDataSet>();
    }

    std::unique_ptr<CompilationCacheProducedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class CompilationCacheProducedParams;
    CompilationCacheProducedParamsBuilder() : result_(new CompilationCacheProducedParams()) { }

    template<int STEP> CompilationCacheProducedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<CompilationCacheProducedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<CompilationCacheProducedParams> result_;
  };

  static CompilationCacheProducedParamsBuilder<0> Builder() {
    return CompilationCacheProducedParamsBuilder<0>();
  }

 private:
  CompilationCacheProducedParams() { }

  std::string url_;
  protocol::Binary data_;

  DISALLOW_COPY_AND_ASSIGN(CompilationCacheProducedParams);
};


}  // namespace page

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_PAGE_H_
