// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_BACKGROUND_SERVICE_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_BACKGROUND_SERVICE_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_background_service.h"
#include "headless/public/devtools/internal/types_forward_declarations_browser.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/devtools/internal/types_forward_declarations_service_worker.h"
#include "headless/public/devtools/internal/types_forward_declarations_target.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace background_service {

// A key-value pair for additional event information to pass along.
class HEADLESS_EXPORT EventMetadata {
 public:
  static std::unique_ptr<EventMetadata> Parse(const base::Value& value, ErrorReporter* errors);
  ~EventMetadata() { }

  std::string GetKey() const { return key_; }
  void SetKey(const std::string& value) { key_ = value; }

  std::string GetValue() const { return value_; }
  void SetValue(const std::string& value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EventMetadata> Clone() const;

  template<int STATE>
  class EventMetadataBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kKeySet = 1 << 1,
    kValueSet = 1 << 2,
      kAllRequiredFieldsSet = (kKeySet | kValueSet | 0)
    };

    EventMetadataBuilder<STATE | kKeySet>& SetKey(const std::string& value) {
      static_assert(!(STATE & kKeySet), "property key should not have already been set");
      result_->SetKey(value);
      return CastState<kKeySet>();
    }

    EventMetadataBuilder<STATE | kValueSet>& SetValue(const std::string& value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(value);
      return CastState<kValueSet>();
    }

    std::unique_ptr<EventMetadata> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EventMetadata;
    EventMetadataBuilder() : result_(new EventMetadata()) { }

    template<int STEP> EventMetadataBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EventMetadataBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EventMetadata> result_;
  };

  static EventMetadataBuilder<0> Builder() {
    return EventMetadataBuilder<0>();
  }

 private:
  EventMetadata() { }

  std::string key_;
  std::string value_;

  DISALLOW_COPY_AND_ASSIGN(EventMetadata);
};


class HEADLESS_EXPORT BackgroundServiceEvent {
 public:
  static std::unique_ptr<BackgroundServiceEvent> Parse(const base::Value& value, ErrorReporter* errors);
  ~BackgroundServiceEvent() { }

  // Timestamp of the event (in seconds).
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // The origin this event belongs to.
  std::string GetOrigin() const { return origin_; }
  void SetOrigin(const std::string& value) { origin_ = value; }

  // The Service Worker ID that initiated the event.
  std::string GetServiceWorkerRegistrationId() const { return service_worker_registration_id_; }
  void SetServiceWorkerRegistrationId(const std::string& value) { service_worker_registration_id_ = value; }

  // The Background Service this event belongs to.
  ::headless::background_service::ServiceName GetService() const { return service_; }
  void SetService(::headless::background_service::ServiceName value) { service_ = value; }

  // A description of the event.
  std::string GetEventName() const { return event_name_; }
  void SetEventName(const std::string& value) { event_name_ = value; }

  // An identifier that groups related events together.
  std::string GetInstanceId() const { return instance_id_; }
  void SetInstanceId(const std::string& value) { instance_id_ = value; }

  // A list of event-specific information.
  const std::vector<std::unique_ptr<::headless::background_service::EventMetadata>>* GetEventMetadata() const { return &event_metadata_; }
  void SetEventMetadata(std::vector<std::unique_ptr<::headless::background_service::EventMetadata>> value) { event_metadata_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BackgroundServiceEvent> Clone() const;

  template<int STATE>
  class BackgroundServiceEventBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kTimestampSet = 1 << 1,
    kOriginSet = 1 << 2,
    kServiceWorkerRegistrationIdSet = 1 << 3,
    kServiceSet = 1 << 4,
    kEventNameSet = 1 << 5,
    kInstanceIdSet = 1 << 6,
    kEventMetadataSet = 1 << 7,
      kAllRequiredFieldsSet = (kTimestampSet | kOriginSet | kServiceWorkerRegistrationIdSet | kServiceSet | kEventNameSet | kInstanceIdSet | kEventMetadataSet | 0)
    };

    BackgroundServiceEventBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    BackgroundServiceEventBuilder<STATE | kOriginSet>& SetOrigin(const std::string& value) {
      static_assert(!(STATE & kOriginSet), "property origin should not have already been set");
      result_->SetOrigin(value);
      return CastState<kOriginSet>();
    }

    BackgroundServiceEventBuilder<STATE | kServiceWorkerRegistrationIdSet>& SetServiceWorkerRegistrationId(const std::string& value) {
      static_assert(!(STATE & kServiceWorkerRegistrationIdSet), "property serviceWorkerRegistrationId should not have already been set");
      result_->SetServiceWorkerRegistrationId(value);
      return CastState<kServiceWorkerRegistrationIdSet>();
    }

    BackgroundServiceEventBuilder<STATE | kServiceSet>& SetService(::headless::background_service::ServiceName value) {
      static_assert(!(STATE & kServiceSet), "property service should not have already been set");
      result_->SetService(value);
      return CastState<kServiceSet>();
    }

    BackgroundServiceEventBuilder<STATE | kEventNameSet>& SetEventName(const std::string& value) {
      static_assert(!(STATE & kEventNameSet), "property eventName should not have already been set");
      result_->SetEventName(value);
      return CastState<kEventNameSet>();
    }

    BackgroundServiceEventBuilder<STATE | kInstanceIdSet>& SetInstanceId(const std::string& value) {
      static_assert(!(STATE & kInstanceIdSet), "property instanceId should not have already been set");
      result_->SetInstanceId(value);
      return CastState<kInstanceIdSet>();
    }

    BackgroundServiceEventBuilder<STATE | kEventMetadataSet>& SetEventMetadata(std::vector<std::unique_ptr<::headless::background_service::EventMetadata>> value) {
      static_assert(!(STATE & kEventMetadataSet), "property eventMetadata should not have already been set");
      result_->SetEventMetadata(std::move(value));
      return CastState<kEventMetadataSet>();
    }

    std::unique_ptr<BackgroundServiceEvent> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BackgroundServiceEvent;
    BackgroundServiceEventBuilder() : result_(new BackgroundServiceEvent()) { }

    template<int STEP> BackgroundServiceEventBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BackgroundServiceEventBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BackgroundServiceEvent> result_;
  };

  static BackgroundServiceEventBuilder<0> Builder() {
    return BackgroundServiceEventBuilder<0>();
  }

 private:
  BackgroundServiceEvent() { }

  double timestamp_;
  std::string origin_;
  std::string service_worker_registration_id_;
  ::headless::background_service::ServiceName service_;
  std::string event_name_;
  std::string instance_id_;
  std::vector<std::unique_ptr<::headless::background_service::EventMetadata>> event_metadata_;

  DISALLOW_COPY_AND_ASSIGN(BackgroundServiceEvent);
};


// Parameters for the StartObserving command.
class HEADLESS_EXPORT StartObservingParams {
 public:
  static std::unique_ptr<StartObservingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartObservingParams() { }

  ::headless::background_service::ServiceName GetService() const { return service_; }
  void SetService(::headless::background_service::ServiceName value) { service_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartObservingParams> Clone() const;

  template<int STATE>
  class StartObservingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kServiceSet = 1 << 1,
      kAllRequiredFieldsSet = (kServiceSet | 0)
    };

    StartObservingParamsBuilder<STATE | kServiceSet>& SetService(::headless::background_service::ServiceName value) {
      static_assert(!(STATE & kServiceSet), "property service should not have already been set");
      result_->SetService(value);
      return CastState<kServiceSet>();
    }

    std::unique_ptr<StartObservingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartObservingParams;
    StartObservingParamsBuilder() : result_(new StartObservingParams()) { }

    template<int STEP> StartObservingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartObservingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartObservingParams> result_;
  };

  static StartObservingParamsBuilder<0> Builder() {
    return StartObservingParamsBuilder<0>();
  }

 private:
  StartObservingParams() { }

  ::headless::background_service::ServiceName service_;

  DISALLOW_COPY_AND_ASSIGN(StartObservingParams);
};


// Result for the StartObserving command.
class HEADLESS_EXPORT StartObservingResult {
 public:
  static std::unique_ptr<StartObservingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartObservingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartObservingResult> Clone() const;

  template<int STATE>
  class StartObservingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartObservingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartObservingResult;
    StartObservingResultBuilder() : result_(new StartObservingResult()) { }

    template<int STEP> StartObservingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartObservingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartObservingResult> result_;
  };

  static StartObservingResultBuilder<0> Builder() {
    return StartObservingResultBuilder<0>();
  }

 private:
  StartObservingResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartObservingResult);
};


// Parameters for the StopObserving command.
class HEADLESS_EXPORT StopObservingParams {
 public:
  static std::unique_ptr<StopObservingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopObservingParams() { }

  ::headless::background_service::ServiceName GetService() const { return service_; }
  void SetService(::headless::background_service::ServiceName value) { service_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopObservingParams> Clone() const;

  template<int STATE>
  class StopObservingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kServiceSet = 1 << 1,
      kAllRequiredFieldsSet = (kServiceSet | 0)
    };

    StopObservingParamsBuilder<STATE | kServiceSet>& SetService(::headless::background_service::ServiceName value) {
      static_assert(!(STATE & kServiceSet), "property service should not have already been set");
      result_->SetService(value);
      return CastState<kServiceSet>();
    }

    std::unique_ptr<StopObservingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopObservingParams;
    StopObservingParamsBuilder() : result_(new StopObservingParams()) { }

    template<int STEP> StopObservingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopObservingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopObservingParams> result_;
  };

  static StopObservingParamsBuilder<0> Builder() {
    return StopObservingParamsBuilder<0>();
  }

 private:
  StopObservingParams() { }

  ::headless::background_service::ServiceName service_;

  DISALLOW_COPY_AND_ASSIGN(StopObservingParams);
};


// Result for the StopObserving command.
class HEADLESS_EXPORT StopObservingResult {
 public:
  static std::unique_ptr<StopObservingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopObservingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopObservingResult> Clone() const;

  template<int STATE>
  class StopObservingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopObservingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopObservingResult;
    StopObservingResultBuilder() : result_(new StopObservingResult()) { }

    template<int STEP> StopObservingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopObservingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopObservingResult> result_;
  };

  static StopObservingResultBuilder<0> Builder() {
    return StopObservingResultBuilder<0>();
  }

 private:
  StopObservingResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopObservingResult);
};


// Parameters for the SetRecording command.
class HEADLESS_EXPORT SetRecordingParams {
 public:
  static std::unique_ptr<SetRecordingParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetRecordingParams() { }

  bool GetShouldRecord() const { return should_record_; }
  void SetShouldRecord(bool value) { should_record_ = value; }

  ::headless::background_service::ServiceName GetService() const { return service_; }
  void SetService(::headless::background_service::ServiceName value) { service_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetRecordingParams> Clone() const;

  template<int STATE>
  class SetRecordingParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kShouldRecordSet = 1 << 1,
    kServiceSet = 1 << 2,
      kAllRequiredFieldsSet = (kShouldRecordSet | kServiceSet | 0)
    };

    SetRecordingParamsBuilder<STATE | kShouldRecordSet>& SetShouldRecord(bool value) {
      static_assert(!(STATE & kShouldRecordSet), "property shouldRecord should not have already been set");
      result_->SetShouldRecord(value);
      return CastState<kShouldRecordSet>();
    }

    SetRecordingParamsBuilder<STATE | kServiceSet>& SetService(::headless::background_service::ServiceName value) {
      static_assert(!(STATE & kServiceSet), "property service should not have already been set");
      result_->SetService(value);
      return CastState<kServiceSet>();
    }

    std::unique_ptr<SetRecordingParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetRecordingParams;
    SetRecordingParamsBuilder() : result_(new SetRecordingParams()) { }

    template<int STEP> SetRecordingParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetRecordingParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetRecordingParams> result_;
  };

  static SetRecordingParamsBuilder<0> Builder() {
    return SetRecordingParamsBuilder<0>();
  }

 private:
  SetRecordingParams() { }

  bool should_record_;
  ::headless::background_service::ServiceName service_;

  DISALLOW_COPY_AND_ASSIGN(SetRecordingParams);
};


// Result for the SetRecording command.
class HEADLESS_EXPORT SetRecordingResult {
 public:
  static std::unique_ptr<SetRecordingResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~SetRecordingResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<SetRecordingResult> Clone() const;

  template<int STATE>
  class SetRecordingResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<SetRecordingResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class SetRecordingResult;
    SetRecordingResultBuilder() : result_(new SetRecordingResult()) { }

    template<int STEP> SetRecordingResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<SetRecordingResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<SetRecordingResult> result_;
  };

  static SetRecordingResultBuilder<0> Builder() {
    return SetRecordingResultBuilder<0>();
  }

 private:
  SetRecordingResult() { }


  DISALLOW_COPY_AND_ASSIGN(SetRecordingResult);
};


// Parameters for the ClearEvents command.
class HEADLESS_EXPORT ClearEventsParams {
 public:
  static std::unique_ptr<ClearEventsParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearEventsParams() { }

  ::headless::background_service::ServiceName GetService() const { return service_; }
  void SetService(::headless::background_service::ServiceName value) { service_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearEventsParams> Clone() const;

  template<int STATE>
  class ClearEventsParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kServiceSet = 1 << 1,
      kAllRequiredFieldsSet = (kServiceSet | 0)
    };

    ClearEventsParamsBuilder<STATE | kServiceSet>& SetService(::headless::background_service::ServiceName value) {
      static_assert(!(STATE & kServiceSet), "property service should not have already been set");
      result_->SetService(value);
      return CastState<kServiceSet>();
    }

    std::unique_ptr<ClearEventsParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearEventsParams;
    ClearEventsParamsBuilder() : result_(new ClearEventsParams()) { }

    template<int STEP> ClearEventsParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearEventsParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearEventsParams> result_;
  };

  static ClearEventsParamsBuilder<0> Builder() {
    return ClearEventsParamsBuilder<0>();
  }

 private:
  ClearEventsParams() { }

  ::headless::background_service::ServiceName service_;

  DISALLOW_COPY_AND_ASSIGN(ClearEventsParams);
};


// Result for the ClearEvents command.
class HEADLESS_EXPORT ClearEventsResult {
 public:
  static std::unique_ptr<ClearEventsResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearEventsResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearEventsResult> Clone() const;

  template<int STATE>
  class ClearEventsResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearEventsResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearEventsResult;
    ClearEventsResultBuilder() : result_(new ClearEventsResult()) { }

    template<int STEP> ClearEventsResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearEventsResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearEventsResult> result_;
  };

  static ClearEventsResultBuilder<0> Builder() {
    return ClearEventsResultBuilder<0>();
  }

 private:
  ClearEventsResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearEventsResult);
};


// Parameters for the RecordingStateChanged event.
class HEADLESS_EXPORT RecordingStateChangedParams {
 public:
  static std::unique_ptr<RecordingStateChangedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RecordingStateChangedParams() { }

  bool GetIsRecording() const { return is_recording_; }
  void SetIsRecording(bool value) { is_recording_ = value; }

  ::headless::background_service::ServiceName GetService() const { return service_; }
  void SetService(::headless::background_service::ServiceName value) { service_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RecordingStateChangedParams> Clone() const;

  template<int STATE>
  class RecordingStateChangedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kIsRecordingSet = 1 << 1,
    kServiceSet = 1 << 2,
      kAllRequiredFieldsSet = (kIsRecordingSet | kServiceSet | 0)
    };

    RecordingStateChangedParamsBuilder<STATE | kIsRecordingSet>& SetIsRecording(bool value) {
      static_assert(!(STATE & kIsRecordingSet), "property isRecording should not have already been set");
      result_->SetIsRecording(value);
      return CastState<kIsRecordingSet>();
    }

    RecordingStateChangedParamsBuilder<STATE | kServiceSet>& SetService(::headless::background_service::ServiceName value) {
      static_assert(!(STATE & kServiceSet), "property service should not have already been set");
      result_->SetService(value);
      return CastState<kServiceSet>();
    }

    std::unique_ptr<RecordingStateChangedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RecordingStateChangedParams;
    RecordingStateChangedParamsBuilder() : result_(new RecordingStateChangedParams()) { }

    template<int STEP> RecordingStateChangedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RecordingStateChangedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RecordingStateChangedParams> result_;
  };

  static RecordingStateChangedParamsBuilder<0> Builder() {
    return RecordingStateChangedParamsBuilder<0>();
  }

 private:
  RecordingStateChangedParams() { }

  bool is_recording_;
  ::headless::background_service::ServiceName service_;

  DISALLOW_COPY_AND_ASSIGN(RecordingStateChangedParams);
};


// Parameters for the BackgroundServiceEventReceived event.
class HEADLESS_EXPORT BackgroundServiceEventReceivedParams {
 public:
  static std::unique_ptr<BackgroundServiceEventReceivedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~BackgroundServiceEventReceivedParams() { }

  const ::headless::background_service::BackgroundServiceEvent* GetBackgroundServiceEvent() const { return background_service_event_.get(); }
  void SetBackgroundServiceEvent(std::unique_ptr<::headless::background_service::BackgroundServiceEvent> value) { background_service_event_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BackgroundServiceEventReceivedParams> Clone() const;

  template<int STATE>
  class BackgroundServiceEventReceivedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kBackgroundServiceEventSet = 1 << 1,
      kAllRequiredFieldsSet = (kBackgroundServiceEventSet | 0)
    };

    BackgroundServiceEventReceivedParamsBuilder<STATE | kBackgroundServiceEventSet>& SetBackgroundServiceEvent(std::unique_ptr<::headless::background_service::BackgroundServiceEvent> value) {
      static_assert(!(STATE & kBackgroundServiceEventSet), "property backgroundServiceEvent should not have already been set");
      result_->SetBackgroundServiceEvent(std::move(value));
      return CastState<kBackgroundServiceEventSet>();
    }

    std::unique_ptr<BackgroundServiceEventReceivedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BackgroundServiceEventReceivedParams;
    BackgroundServiceEventReceivedParamsBuilder() : result_(new BackgroundServiceEventReceivedParams()) { }

    template<int STEP> BackgroundServiceEventReceivedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BackgroundServiceEventReceivedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BackgroundServiceEventReceivedParams> result_;
  };

  static BackgroundServiceEventReceivedParamsBuilder<0> Builder() {
    return BackgroundServiceEventReceivedParamsBuilder<0>();
  }

 private:
  BackgroundServiceEventReceivedParams() { }

  std::unique_ptr<::headless::background_service::BackgroundServiceEvent> background_service_event_;

  DISALLOW_COPY_AND_ASSIGN(BackgroundServiceEventReceivedParams);
};


}  // namespace background_service

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_BACKGROUND_SERVICE_H_
