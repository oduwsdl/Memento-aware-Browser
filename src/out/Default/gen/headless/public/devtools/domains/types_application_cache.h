// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_APPLICATION_CACHE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_APPLICATION_CACHE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_application_cache.h"
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

namespace application_cache {

// Detailed application cache resource information.
class HEADLESS_EXPORT ApplicationCacheResource {
 public:
  static std::unique_ptr<ApplicationCacheResource> Parse(const base::Value& value, ErrorReporter* errors);
  ~ApplicationCacheResource() { }

  // Resource url.
  std::string GetUrl() const { return url_; }
  void SetUrl(const std::string& value) { url_ = value; }

  // Resource size.
  int GetSize() const { return size_; }
  void SetSize(int value) { size_ = value; }

  // Resource type.
  std::string GetType() const { return type_; }
  void SetType(const std::string& value) { type_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ApplicationCacheResource> Clone() const;

  template<int STATE>
  class ApplicationCacheResourceBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kUrlSet = 1 << 1,
    kSizeSet = 1 << 2,
    kTypeSet = 1 << 3,
      kAllRequiredFieldsSet = (kUrlSet | kSizeSet | kTypeSet | 0)
    };

    ApplicationCacheResourceBuilder<STATE | kUrlSet>& SetUrl(const std::string& value) {
      static_assert(!(STATE & kUrlSet), "property url should not have already been set");
      result_->SetUrl(value);
      return CastState<kUrlSet>();
    }

    ApplicationCacheResourceBuilder<STATE | kSizeSet>& SetSize(int value) {
      static_assert(!(STATE & kSizeSet), "property size should not have already been set");
      result_->SetSize(value);
      return CastState<kSizeSet>();
    }

    ApplicationCacheResourceBuilder<STATE | kTypeSet>& SetType(const std::string& value) {
      static_assert(!(STATE & kTypeSet), "property type should not have already been set");
      result_->SetType(value);
      return CastState<kTypeSet>();
    }

    std::unique_ptr<ApplicationCacheResource> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ApplicationCacheResource;
    ApplicationCacheResourceBuilder() : result_(new ApplicationCacheResource()) { }

    template<int STEP> ApplicationCacheResourceBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ApplicationCacheResourceBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ApplicationCacheResource> result_;
  };

  static ApplicationCacheResourceBuilder<0> Builder() {
    return ApplicationCacheResourceBuilder<0>();
  }

 private:
  ApplicationCacheResource() { }

  std::string url_;
  int size_;
  std::string type_;

  DISALLOW_COPY_AND_ASSIGN(ApplicationCacheResource);
};


// Detailed application cache information.
class HEADLESS_EXPORT ApplicationCache {
 public:
  static std::unique_ptr<ApplicationCache> Parse(const base::Value& value, ErrorReporter* errors);
  ~ApplicationCache() { }

  // Manifest URL.
  std::string GetManifestURL() const { return manifesturl_; }
  void SetManifestURL(const std::string& value) { manifesturl_ = value; }

  // Application cache size.
  double GetSize() const { return size_; }
  void SetSize(double value) { size_ = value; }

  // Application cache creation time.
  double GetCreationTime() const { return creation_time_; }
  void SetCreationTime(double value) { creation_time_ = value; }

  // Application cache update time.
  double GetUpdateTime() const { return update_time_; }
  void SetUpdateTime(double value) { update_time_ = value; }

  // Application cache resources.
  const std::vector<std::unique_ptr<::headless::application_cache::ApplicationCacheResource>>* GetResources() const { return &resources_; }
  void SetResources(std::vector<std::unique_ptr<::headless::application_cache::ApplicationCacheResource>> value) { resources_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ApplicationCache> Clone() const;

  template<int STATE>
  class ApplicationCacheBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kManifestURLSet = 1 << 1,
    kSizeSet = 1 << 2,
    kCreationTimeSet = 1 << 3,
    kUpdateTimeSet = 1 << 4,
    kResourcesSet = 1 << 5,
      kAllRequiredFieldsSet = (kManifestURLSet | kSizeSet | kCreationTimeSet | kUpdateTimeSet | kResourcesSet | 0)
    };

    ApplicationCacheBuilder<STATE | kManifestURLSet>& SetManifestURL(const std::string& value) {
      static_assert(!(STATE & kManifestURLSet), "property manifestURL should not have already been set");
      result_->SetManifestURL(value);
      return CastState<kManifestURLSet>();
    }

    ApplicationCacheBuilder<STATE | kSizeSet>& SetSize(double value) {
      static_assert(!(STATE & kSizeSet), "property size should not have already been set");
      result_->SetSize(value);
      return CastState<kSizeSet>();
    }

    ApplicationCacheBuilder<STATE | kCreationTimeSet>& SetCreationTime(double value) {
      static_assert(!(STATE & kCreationTimeSet), "property creationTime should not have already been set");
      result_->SetCreationTime(value);
      return CastState<kCreationTimeSet>();
    }

    ApplicationCacheBuilder<STATE | kUpdateTimeSet>& SetUpdateTime(double value) {
      static_assert(!(STATE & kUpdateTimeSet), "property updateTime should not have already been set");
      result_->SetUpdateTime(value);
      return CastState<kUpdateTimeSet>();
    }

    ApplicationCacheBuilder<STATE | kResourcesSet>& SetResources(std::vector<std::unique_ptr<::headless::application_cache::ApplicationCacheResource>> value) {
      static_assert(!(STATE & kResourcesSet), "property resources should not have already been set");
      result_->SetResources(std::move(value));
      return CastState<kResourcesSet>();
    }

    std::unique_ptr<ApplicationCache> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ApplicationCache;
    ApplicationCacheBuilder() : result_(new ApplicationCache()) { }

    template<int STEP> ApplicationCacheBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ApplicationCacheBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ApplicationCache> result_;
  };

  static ApplicationCacheBuilder<0> Builder() {
    return ApplicationCacheBuilder<0>();
  }

 private:
  ApplicationCache() { }

  std::string manifesturl_;
  double size_;
  double creation_time_;
  double update_time_;
  std::vector<std::unique_ptr<::headless::application_cache::ApplicationCacheResource>> resources_;

  DISALLOW_COPY_AND_ASSIGN(ApplicationCache);
};


// Frame identifier - manifest URL pair.
class HEADLESS_EXPORT FrameWithManifest {
 public:
  static std::unique_ptr<FrameWithManifest> Parse(const base::Value& value, ErrorReporter* errors);
  ~FrameWithManifest() { }

  // Frame identifier.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Manifest URL.
  std::string GetManifestURL() const { return manifesturl_; }
  void SetManifestURL(const std::string& value) { manifesturl_ = value; }

  // Application cache status.
  int GetStatus() const { return status_; }
  void SetStatus(int value) { status_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<FrameWithManifest> Clone() const;

  template<int STATE>
  class FrameWithManifestBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kManifestURLSet = 1 << 2,
    kStatusSet = 1 << 3,
      kAllRequiredFieldsSet = (kFrameIdSet | kManifestURLSet | kStatusSet | 0)
    };

    FrameWithManifestBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    FrameWithManifestBuilder<STATE | kManifestURLSet>& SetManifestURL(const std::string& value) {
      static_assert(!(STATE & kManifestURLSet), "property manifestURL should not have already been set");
      result_->SetManifestURL(value);
      return CastState<kManifestURLSet>();
    }

    FrameWithManifestBuilder<STATE | kStatusSet>& SetStatus(int value) {
      static_assert(!(STATE & kStatusSet), "property status should not have already been set");
      result_->SetStatus(value);
      return CastState<kStatusSet>();
    }

    std::unique_ptr<FrameWithManifest> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class FrameWithManifest;
    FrameWithManifestBuilder() : result_(new FrameWithManifest()) { }

    template<int STEP> FrameWithManifestBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<FrameWithManifestBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<FrameWithManifest> result_;
  };

  static FrameWithManifestBuilder<0> Builder() {
    return FrameWithManifestBuilder<0>();
  }

 private:
  FrameWithManifest() { }

  std::string frame_id_;
  std::string manifesturl_;
  int status_;

  DISALLOW_COPY_AND_ASSIGN(FrameWithManifest);
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


// Parameters for the GetApplicationCacheForFrame command.
class HEADLESS_EXPORT GetApplicationCacheForFrameParams {
 public:
  static std::unique_ptr<GetApplicationCacheForFrameParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetApplicationCacheForFrameParams() { }

  // Identifier of the frame containing document whose application cache is retrieved.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetApplicationCacheForFrameParams> Clone() const;

  template<int STATE>
  class GetApplicationCacheForFrameParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    GetApplicationCacheForFrameParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<GetApplicationCacheForFrameParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetApplicationCacheForFrameParams;
    GetApplicationCacheForFrameParamsBuilder() : result_(new GetApplicationCacheForFrameParams()) { }

    template<int STEP> GetApplicationCacheForFrameParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetApplicationCacheForFrameParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetApplicationCacheForFrameParams> result_;
  };

  static GetApplicationCacheForFrameParamsBuilder<0> Builder() {
    return GetApplicationCacheForFrameParamsBuilder<0>();
  }

 private:
  GetApplicationCacheForFrameParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(GetApplicationCacheForFrameParams);
};


// Result for the GetApplicationCacheForFrame command.
class HEADLESS_EXPORT GetApplicationCacheForFrameResult {
 public:
  static std::unique_ptr<GetApplicationCacheForFrameResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetApplicationCacheForFrameResult() { }

  // Relevant application cache data for the document in given frame.
  const ::headless::application_cache::ApplicationCache* GetApplicationCache() const { return application_cache_.get(); }
  void SetApplicationCache(std::unique_ptr<::headless::application_cache::ApplicationCache> value) { application_cache_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetApplicationCacheForFrameResult> Clone() const;

  template<int STATE>
  class GetApplicationCacheForFrameResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kApplicationCacheSet = 1 << 1,
      kAllRequiredFieldsSet = (kApplicationCacheSet | 0)
    };

    GetApplicationCacheForFrameResultBuilder<STATE | kApplicationCacheSet>& SetApplicationCache(std::unique_ptr<::headless::application_cache::ApplicationCache> value) {
      static_assert(!(STATE & kApplicationCacheSet), "property applicationCache should not have already been set");
      result_->SetApplicationCache(std::move(value));
      return CastState<kApplicationCacheSet>();
    }

    std::unique_ptr<GetApplicationCacheForFrameResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetApplicationCacheForFrameResult;
    GetApplicationCacheForFrameResultBuilder() : result_(new GetApplicationCacheForFrameResult()) { }

    template<int STEP> GetApplicationCacheForFrameResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetApplicationCacheForFrameResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetApplicationCacheForFrameResult> result_;
  };

  static GetApplicationCacheForFrameResultBuilder<0> Builder() {
    return GetApplicationCacheForFrameResultBuilder<0>();
  }

 private:
  GetApplicationCacheForFrameResult() { }

  std::unique_ptr<::headless::application_cache::ApplicationCache> application_cache_;

  DISALLOW_COPY_AND_ASSIGN(GetApplicationCacheForFrameResult);
};


// Parameters for the GetFramesWithManifests command.
class HEADLESS_EXPORT GetFramesWithManifestsParams {
 public:
  static std::unique_ptr<GetFramesWithManifestsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFramesWithManifestsParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFramesWithManifestsParams> Clone() const;

  template<int STATE>
  class GetFramesWithManifestsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetFramesWithManifestsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFramesWithManifestsParams;
    GetFramesWithManifestsParamsBuilder() : result_(new GetFramesWithManifestsParams()) { }

    template<int STEP> GetFramesWithManifestsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFramesWithManifestsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFramesWithManifestsParams> result_;
  };

  static GetFramesWithManifestsParamsBuilder<0> Builder() {
    return GetFramesWithManifestsParamsBuilder<0>();
  }

 private:
  GetFramesWithManifestsParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetFramesWithManifestsParams);
};


// Result for the GetFramesWithManifests command.
class HEADLESS_EXPORT GetFramesWithManifestsResult {
 public:
  static std::unique_ptr<GetFramesWithManifestsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetFramesWithManifestsResult() { }

  // Array of frame identifiers with manifest urls for each frame containing a document
  // associated with some application cache.
  const std::vector<std::unique_ptr<::headless::application_cache::FrameWithManifest>>* GetFrameIds() const { return &frame_ids_; }
  void SetFrameIds(std::vector<std::unique_ptr<::headless::application_cache::FrameWithManifest>> value) { frame_ids_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetFramesWithManifestsResult> Clone() const;

  template<int STATE>
  class GetFramesWithManifestsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdsSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdsSet | 0)
    };

    GetFramesWithManifestsResultBuilder<STATE | kFrameIdsSet>& SetFrameIds(std::vector<std::unique_ptr<::headless::application_cache::FrameWithManifest>> value) {
      static_assert(!(STATE & kFrameIdsSet), "property frameIds should not have already been set");
      result_->SetFrameIds(std::move(value));
      return CastState<kFrameIdsSet>();
    }

    std::unique_ptr<GetFramesWithManifestsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetFramesWithManifestsResult;
    GetFramesWithManifestsResultBuilder() : result_(new GetFramesWithManifestsResult()) { }

    template<int STEP> GetFramesWithManifestsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetFramesWithManifestsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetFramesWithManifestsResult> result_;
  };

  static GetFramesWithManifestsResultBuilder<0> Builder() {
    return GetFramesWithManifestsResultBuilder<0>();
  }

 private:
  GetFramesWithManifestsResult() { }

  std::vector<std::unique_ptr<::headless::application_cache::FrameWithManifest>> frame_ids_;

  DISALLOW_COPY_AND_ASSIGN(GetFramesWithManifestsResult);
};


// Parameters for the GetManifestForFrame command.
class HEADLESS_EXPORT GetManifestForFrameParams {
 public:
  static std::unique_ptr<GetManifestForFrameParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetManifestForFrameParams() { }

  // Identifier of the frame containing document whose manifest is retrieved.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetManifestForFrameParams> Clone() const;

  template<int STATE>
  class GetManifestForFrameParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kFrameIdSet | 0)
    };

    GetManifestForFrameParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    std::unique_ptr<GetManifestForFrameParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetManifestForFrameParams;
    GetManifestForFrameParamsBuilder() : result_(new GetManifestForFrameParams()) { }

    template<int STEP> GetManifestForFrameParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetManifestForFrameParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetManifestForFrameParams> result_;
  };

  static GetManifestForFrameParamsBuilder<0> Builder() {
    return GetManifestForFrameParamsBuilder<0>();
  }

 private:
  GetManifestForFrameParams() { }

  std::string frame_id_;

  DISALLOW_COPY_AND_ASSIGN(GetManifestForFrameParams);
};


// Result for the GetManifestForFrame command.
class HEADLESS_EXPORT GetManifestForFrameResult {
 public:
  static std::unique_ptr<GetManifestForFrameResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetManifestForFrameResult() { }

  // Manifest URL for document in the given frame.
  std::string GetManifestURL() const { return manifesturl_; }
  void SetManifestURL(const std::string& value) { manifesturl_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetManifestForFrameResult> Clone() const;

  template<int STATE>
  class GetManifestForFrameResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kManifestURLSet = 1 << 1,
      kAllRequiredFieldsSet = (kManifestURLSet | 0)
    };

    GetManifestForFrameResultBuilder<STATE | kManifestURLSet>& SetManifestURL(const std::string& value) {
      static_assert(!(STATE & kManifestURLSet), "property manifestURL should not have already been set");
      result_->SetManifestURL(value);
      return CastState<kManifestURLSet>();
    }

    std::unique_ptr<GetManifestForFrameResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetManifestForFrameResult;
    GetManifestForFrameResultBuilder() : result_(new GetManifestForFrameResult()) { }

    template<int STEP> GetManifestForFrameResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetManifestForFrameResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetManifestForFrameResult> result_;
  };

  static GetManifestForFrameResultBuilder<0> Builder() {
    return GetManifestForFrameResultBuilder<0>();
  }

 private:
  GetManifestForFrameResult() { }

  std::string manifesturl_;

  DISALLOW_COPY_AND_ASSIGN(GetManifestForFrameResult);
};


// Parameters for the ApplicationCacheStatusUpdated event.
class HEADLESS_EXPORT ApplicationCacheStatusUpdatedParams {
 public:
  static std::unique_ptr<ApplicationCacheStatusUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ApplicationCacheStatusUpdatedParams() { }

  // Identifier of the frame containing document whose application cache updated status.
  std::string GetFrameId() const { return frame_id_; }
  void SetFrameId(const std::string& value) { frame_id_ = value; }

  // Manifest URL.
  std::string GetManifestURL() const { return manifesturl_; }
  void SetManifestURL(const std::string& value) { manifesturl_ = value; }

  // Updated application cache status.
  int GetStatus() const { return status_; }
  void SetStatus(int value) { status_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ApplicationCacheStatusUpdatedParams> Clone() const;

  template<int STATE>
  class ApplicationCacheStatusUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kFrameIdSet = 1 << 1,
    kManifestURLSet = 1 << 2,
    kStatusSet = 1 << 3,
      kAllRequiredFieldsSet = (kFrameIdSet | kManifestURLSet | kStatusSet | 0)
    };

    ApplicationCacheStatusUpdatedParamsBuilder<STATE | kFrameIdSet>& SetFrameId(const std::string& value) {
      static_assert(!(STATE & kFrameIdSet), "property frameId should not have already been set");
      result_->SetFrameId(value);
      return CastState<kFrameIdSet>();
    }

    ApplicationCacheStatusUpdatedParamsBuilder<STATE | kManifestURLSet>& SetManifestURL(const std::string& value) {
      static_assert(!(STATE & kManifestURLSet), "property manifestURL should not have already been set");
      result_->SetManifestURL(value);
      return CastState<kManifestURLSet>();
    }

    ApplicationCacheStatusUpdatedParamsBuilder<STATE | kStatusSet>& SetStatus(int value) {
      static_assert(!(STATE & kStatusSet), "property status should not have already been set");
      result_->SetStatus(value);
      return CastState<kStatusSet>();
    }

    std::unique_ptr<ApplicationCacheStatusUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ApplicationCacheStatusUpdatedParams;
    ApplicationCacheStatusUpdatedParamsBuilder() : result_(new ApplicationCacheStatusUpdatedParams()) { }

    template<int STEP> ApplicationCacheStatusUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ApplicationCacheStatusUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ApplicationCacheStatusUpdatedParams> result_;
  };

  static ApplicationCacheStatusUpdatedParamsBuilder<0> Builder() {
    return ApplicationCacheStatusUpdatedParamsBuilder<0>();
  }

 private:
  ApplicationCacheStatusUpdatedParams() { }

  std::string frame_id_;
  std::string manifesturl_;
  int status_;

  DISALLOW_COPY_AND_ASSIGN(ApplicationCacheStatusUpdatedParams);
};


// Parameters for the NetworkStateUpdated event.
class HEADLESS_EXPORT NetworkStateUpdatedParams {
 public:
  static std::unique_ptr<NetworkStateUpdatedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~NetworkStateUpdatedParams() { }

  bool GetIsNowOnline() const { return is_now_online_; }
  void SetIsNowOnline(bool value) { is_now_online_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<NetworkStateUpdatedParams> Clone() const;

  template<int STATE>
  class NetworkStateUpdatedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIsNowOnlineSet = 1 << 1,
      kAllRequiredFieldsSet = (kIsNowOnlineSet | 0)
    };

    NetworkStateUpdatedParamsBuilder<STATE | kIsNowOnlineSet>& SetIsNowOnline(bool value) {
      static_assert(!(STATE & kIsNowOnlineSet), "property isNowOnline should not have already been set");
      result_->SetIsNowOnline(value);
      return CastState<kIsNowOnlineSet>();
    }

    std::unique_ptr<NetworkStateUpdatedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class NetworkStateUpdatedParams;
    NetworkStateUpdatedParamsBuilder() : result_(new NetworkStateUpdatedParams()) { }

    template<int STEP> NetworkStateUpdatedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<NetworkStateUpdatedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<NetworkStateUpdatedParams> result_;
  };

  static NetworkStateUpdatedParamsBuilder<0> Builder() {
    return NetworkStateUpdatedParamsBuilder<0>();
  }

 private:
  NetworkStateUpdatedParams() { }

  bool is_now_online_;

  DISALLOW_COPY_AND_ASSIGN(NetworkStateUpdatedParams);
};


}  // namespace application_cache

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_APPLICATION_CACHE_H_
