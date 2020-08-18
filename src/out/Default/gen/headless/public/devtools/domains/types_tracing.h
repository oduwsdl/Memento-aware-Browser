// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TRACING_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TRACING_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_tracing.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace tracing {

class HEADLESS_EXPORT TraceConfig {
 public:
  static std::unique_ptr<TraceConfig> Parse(const base::Value& value, ErrorReporter* errors);
  ~TraceConfig() { }

  // Controls how the trace buffer stores data.
  bool HasRecordMode() const { return !!record_mode_; }
  ::headless::tracing::TraceConfigRecordMode GetRecordMode() const { DCHECK(HasRecordMode()); return record_mode_.value(); }
  void SetRecordMode(::headless::tracing::TraceConfigRecordMode value) { record_mode_ = value; }

  // Turns on JavaScript stack sampling.
  bool HasEnableSampling() const { return !!enable_sampling_; }
  bool GetEnableSampling() const { DCHECK(HasEnableSampling()); return enable_sampling_.value(); }
  void SetEnableSampling(bool value) { enable_sampling_ = value; }

  // Turns on system tracing.
  bool HasEnableSystrace() const { return !!enable_systrace_; }
  bool GetEnableSystrace() const { DCHECK(HasEnableSystrace()); return enable_systrace_.value(); }
  void SetEnableSystrace(bool value) { enable_systrace_ = value; }

  // Turns on argument filter.
  bool HasEnableArgumentFilter() const { return !!enable_argument_filter_; }
  bool GetEnableArgumentFilter() const { DCHECK(HasEnableArgumentFilter()); return enable_argument_filter_.value(); }
  void SetEnableArgumentFilter(bool value) { enable_argument_filter_ = value; }

  // Included category filters.
  bool HasIncludedCategories() const { return !!included_categories_; }
  const std::vector<std::string>* GetIncludedCategories() const { DCHECK(HasIncludedCategories()); return &included_categories_.value(); }
  void SetIncludedCategories(std::vector<std::string> value) { included_categories_ = std::move(value); }

  // Excluded category filters.
  bool HasExcludedCategories() const { return !!excluded_categories_; }
  const std::vector<std::string>* GetExcludedCategories() const { DCHECK(HasExcludedCategories()); return &excluded_categories_.value(); }
  void SetExcludedCategories(std::vector<std::string> value) { excluded_categories_ = std::move(value); }

  // Configuration to synthesize the delays in tracing.
  bool HasSyntheticDelays() const { return !!synthetic_delays_; }
  const std::vector<std::string>* GetSyntheticDelays() const { DCHECK(HasSyntheticDelays()); return &synthetic_delays_.value(); }
  void SetSyntheticDelays(std::vector<std::string> value) { synthetic_delays_ = std::move(value); }

  // Configuration for memory dump triggers. Used only when "memory-infra" category is enabled.
  bool HasMemoryDumpConfig() const { return !!memory_dump_config_; }
  const base::DictionaryValue* GetMemoryDumpConfig() const { DCHECK(HasMemoryDumpConfig()); return memory_dump_config_.value().get(); }
  void SetMemoryDumpConfig(std::unique_ptr<base::DictionaryValue> value) { memory_dump_config_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TraceConfig> Clone() const;

  template<int STATE>
  class TraceConfigBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    TraceConfigBuilder<STATE>& SetRecordMode(::headless::tracing::TraceConfigRecordMode value) {
      result_->SetRecordMode(value);
      return *this;
    }

    TraceConfigBuilder<STATE>& SetEnableSampling(bool value) {
      result_->SetEnableSampling(value);
      return *this;
    }

    TraceConfigBuilder<STATE>& SetEnableSystrace(bool value) {
      result_->SetEnableSystrace(value);
      return *this;
    }

    TraceConfigBuilder<STATE>& SetEnableArgumentFilter(bool value) {
      result_->SetEnableArgumentFilter(value);
      return *this;
    }

    TraceConfigBuilder<STATE>& SetIncludedCategories(std::vector<std::string> value) {
      result_->SetIncludedCategories(std::move(value));
      return *this;
    }

    TraceConfigBuilder<STATE>& SetExcludedCategories(std::vector<std::string> value) {
      result_->SetExcludedCategories(std::move(value));
      return *this;
    }

    TraceConfigBuilder<STATE>& SetSyntheticDelays(std::vector<std::string> value) {
      result_->SetSyntheticDelays(std::move(value));
      return *this;
    }

    TraceConfigBuilder<STATE>& SetMemoryDumpConfig(std::unique_ptr<base::DictionaryValue> value) {
      result_->SetMemoryDumpConfig(std::move(value));
      return *this;
    }

    std::unique_ptr<TraceConfig> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TraceConfig;
    TraceConfigBuilder() : result_(new TraceConfig()) { }

    template<int STEP> TraceConfigBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TraceConfigBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TraceConfig> result_;
  };

  static TraceConfigBuilder<0> Builder() {
    return TraceConfigBuilder<0>();
  }

 private:
  TraceConfig() { }

  base::Optional<::headless::tracing::TraceConfigRecordMode> record_mode_;
  base::Optional<bool> enable_sampling_;
  base::Optional<bool> enable_systrace_;
  base::Optional<bool> enable_argument_filter_;
  base::Optional<std::vector<std::string>> included_categories_;
  base::Optional<std::vector<std::string>> excluded_categories_;
  base::Optional<std::vector<std::string>> synthetic_delays_;
  base::Optional<std::unique_ptr<base::DictionaryValue>> memory_dump_config_;

  DISALLOW_COPY_AND_ASSIGN(TraceConfig);
};


// Parameters for the End command.
class HEADLESS_EXPORT EndParams {
 public:
  static std::unique_ptr<EndParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EndParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EndParams> Clone() const;

  template<int STATE>
  class EndParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EndParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EndParams;
    EndParamsBuilder() : result_(new EndParams()) { }

    template<int STEP> EndParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EndParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EndParams> result_;
  };

  static EndParamsBuilder<0> Builder() {
    return EndParamsBuilder<0>();
  }

 private:
  EndParams() { }


  DISALLOW_COPY_AND_ASSIGN(EndParams);
};


// Result for the End command.
class HEADLESS_EXPORT EndResult {
 public:
  static std::unique_ptr<EndResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~EndResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EndResult> Clone() const;

  template<int STATE>
  class EndResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<EndResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EndResult;
    EndResultBuilder() : result_(new EndResult()) { }

    template<int STEP> EndResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EndResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EndResult> result_;
  };

  static EndResultBuilder<0> Builder() {
    return EndResultBuilder<0>();
  }

 private:
  EndResult() { }


  DISALLOW_COPY_AND_ASSIGN(EndResult);
};


// Parameters for the GetCategories command.
class HEADLESS_EXPORT GetCategoriesParams {
 public:
  static std::unique_ptr<GetCategoriesParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCategoriesParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCategoriesParams> Clone() const;

  template<int STATE>
  class GetCategoriesParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<GetCategoriesParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCategoriesParams;
    GetCategoriesParamsBuilder() : result_(new GetCategoriesParams()) { }

    template<int STEP> GetCategoriesParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCategoriesParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCategoriesParams> result_;
  };

  static GetCategoriesParamsBuilder<0> Builder() {
    return GetCategoriesParamsBuilder<0>();
  }

 private:
  GetCategoriesParams() { }


  DISALLOW_COPY_AND_ASSIGN(GetCategoriesParams);
};


// Result for the GetCategories command.
class HEADLESS_EXPORT GetCategoriesResult {
 public:
  static std::unique_ptr<GetCategoriesResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~GetCategoriesResult() { }

  // A list of supported tracing categories.
  const std::vector<std::string>* GetCategories() const { return &categories_; }
  void SetCategories(std::vector<std::string> value) { categories_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<GetCategoriesResult> Clone() const;

  template<int STATE>
  class GetCategoriesResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kCategoriesSet = 1 << 1,
      kAllRequiredFieldsSet = (kCategoriesSet | 0)
    };

    GetCategoriesResultBuilder<STATE | kCategoriesSet>& SetCategories(std::vector<std::string> value) {
      static_assert(!(STATE & kCategoriesSet), "property categories should not have already been set");
      result_->SetCategories(std::move(value));
      return CastState<kCategoriesSet>();
    }

    std::unique_ptr<GetCategoriesResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class GetCategoriesResult;
    GetCategoriesResultBuilder() : result_(new GetCategoriesResult()) { }

    template<int STEP> GetCategoriesResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<GetCategoriesResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<GetCategoriesResult> result_;
  };

  static GetCategoriesResultBuilder<0> Builder() {
    return GetCategoriesResultBuilder<0>();
  }

 private:
  GetCategoriesResult() { }

  std::vector<std::string> categories_;

  DISALLOW_COPY_AND_ASSIGN(GetCategoriesResult);
};


// Parameters for the RecordClockSyncMarker command.
class HEADLESS_EXPORT RecordClockSyncMarkerParams {
 public:
  static std::unique_ptr<RecordClockSyncMarkerParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RecordClockSyncMarkerParams() { }

  // The ID of this clock sync marker
  std::string GetSyncId() const { return sync_id_; }
  void SetSyncId(const std::string& value) { sync_id_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RecordClockSyncMarkerParams> Clone() const;

  template<int STATE>
  class RecordClockSyncMarkerParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSyncIdSet = 1 << 1,
      kAllRequiredFieldsSet = (kSyncIdSet | 0)
    };

    RecordClockSyncMarkerParamsBuilder<STATE | kSyncIdSet>& SetSyncId(const std::string& value) {
      static_assert(!(STATE & kSyncIdSet), "property syncId should not have already been set");
      result_->SetSyncId(value);
      return CastState<kSyncIdSet>();
    }

    std::unique_ptr<RecordClockSyncMarkerParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RecordClockSyncMarkerParams;
    RecordClockSyncMarkerParamsBuilder() : result_(new RecordClockSyncMarkerParams()) { }

    template<int STEP> RecordClockSyncMarkerParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RecordClockSyncMarkerParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RecordClockSyncMarkerParams> result_;
  };

  static RecordClockSyncMarkerParamsBuilder<0> Builder() {
    return RecordClockSyncMarkerParamsBuilder<0>();
  }

 private:
  RecordClockSyncMarkerParams() { }

  std::string sync_id_;

  DISALLOW_COPY_AND_ASSIGN(RecordClockSyncMarkerParams);
};


// Result for the RecordClockSyncMarker command.
class HEADLESS_EXPORT RecordClockSyncMarkerResult {
 public:
  static std::unique_ptr<RecordClockSyncMarkerResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RecordClockSyncMarkerResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RecordClockSyncMarkerResult> Clone() const;

  template<int STATE>
  class RecordClockSyncMarkerResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<RecordClockSyncMarkerResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RecordClockSyncMarkerResult;
    RecordClockSyncMarkerResultBuilder() : result_(new RecordClockSyncMarkerResult()) { }

    template<int STEP> RecordClockSyncMarkerResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RecordClockSyncMarkerResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RecordClockSyncMarkerResult> result_;
  };

  static RecordClockSyncMarkerResultBuilder<0> Builder() {
    return RecordClockSyncMarkerResultBuilder<0>();
  }

 private:
  RecordClockSyncMarkerResult() { }


  DISALLOW_COPY_AND_ASSIGN(RecordClockSyncMarkerResult);
};


// Parameters for the RequestMemoryDump command.
class HEADLESS_EXPORT RequestMemoryDumpParams {
 public:
  static std::unique_ptr<RequestMemoryDumpParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestMemoryDumpParams() { }

  // Enables more deterministic results by forcing garbage collection
  bool HasDeterministic() const { return !!deterministic_; }
  bool GetDeterministic() const { DCHECK(HasDeterministic()); return deterministic_.value(); }
  void SetDeterministic(bool value) { deterministic_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestMemoryDumpParams> Clone() const;

  template<int STATE>
  class RequestMemoryDumpParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    RequestMemoryDumpParamsBuilder<STATE>& SetDeterministic(bool value) {
      result_->SetDeterministic(value);
      return *this;
    }

    std::unique_ptr<RequestMemoryDumpParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestMemoryDumpParams;
    RequestMemoryDumpParamsBuilder() : result_(new RequestMemoryDumpParams()) { }

    template<int STEP> RequestMemoryDumpParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestMemoryDumpParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestMemoryDumpParams> result_;
  };

  static RequestMemoryDumpParamsBuilder<0> Builder() {
    return RequestMemoryDumpParamsBuilder<0>();
  }

 private:
  RequestMemoryDumpParams() { }

  base::Optional<bool> deterministic_;

  DISALLOW_COPY_AND_ASSIGN(RequestMemoryDumpParams);
};


// Result for the RequestMemoryDump command.
class HEADLESS_EXPORT RequestMemoryDumpResult {
 public:
  static std::unique_ptr<RequestMemoryDumpResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~RequestMemoryDumpResult() { }

  // GUID of the resulting global memory dump.
  std::string GetDumpGuid() const { return dump_guid_; }
  void SetDumpGuid(const std::string& value) { dump_guid_ = value; }

  // True iff the global memory dump succeeded.
  bool GetSuccess() const { return success_; }
  void SetSuccess(bool value) { success_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<RequestMemoryDumpResult> Clone() const;

  template<int STATE>
  class RequestMemoryDumpResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDumpGuidSet = 1 << 1,
    kSuccessSet = 1 << 2,
      kAllRequiredFieldsSet = (kDumpGuidSet | kSuccessSet | 0)
    };

    RequestMemoryDumpResultBuilder<STATE | kDumpGuidSet>& SetDumpGuid(const std::string& value) {
      static_assert(!(STATE & kDumpGuidSet), "property dumpGuid should not have already been set");
      result_->SetDumpGuid(value);
      return CastState<kDumpGuidSet>();
    }

    RequestMemoryDumpResultBuilder<STATE | kSuccessSet>& SetSuccess(bool value) {
      static_assert(!(STATE & kSuccessSet), "property success should not have already been set");
      result_->SetSuccess(value);
      return CastState<kSuccessSet>();
    }

    std::unique_ptr<RequestMemoryDumpResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class RequestMemoryDumpResult;
    RequestMemoryDumpResultBuilder() : result_(new RequestMemoryDumpResult()) { }

    template<int STEP> RequestMemoryDumpResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<RequestMemoryDumpResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<RequestMemoryDumpResult> result_;
  };

  static RequestMemoryDumpResultBuilder<0> Builder() {
    return RequestMemoryDumpResultBuilder<0>();
  }

 private:
  RequestMemoryDumpResult() { }

  std::string dump_guid_;
  bool success_;

  DISALLOW_COPY_AND_ASSIGN(RequestMemoryDumpResult);
};


// Parameters for the Start command.
class HEADLESS_EXPORT StartParams {
 public:
  static std::unique_ptr<StartParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartParams() { }

  // Category/tag filter
  bool HasCategories() const { return !!categories_; }
  std::string GetCategories() const { DCHECK(HasCategories()); return categories_.value(); }
  void SetCategories(const std::string& value) { categories_ = value; }

  // Tracing options
  bool HasOptions() const { return !!options_; }
  std::string GetOptions() const { DCHECK(HasOptions()); return options_.value(); }
  void SetOptions(const std::string& value) { options_ = value; }

  // If set, the agent will issue bufferUsage events at this interval, specified in milliseconds
  bool HasBufferUsageReportingInterval() const { return !!buffer_usage_reporting_interval_; }
  double GetBufferUsageReportingInterval() const { DCHECK(HasBufferUsageReportingInterval()); return buffer_usage_reporting_interval_.value(); }
  void SetBufferUsageReportingInterval(double value) { buffer_usage_reporting_interval_ = value; }

  // Whether to report trace events as series of dataCollected events or to save trace to a
  // stream (defaults to `ReportEvents`).
  bool HasTransferMode() const { return !!transfer_mode_; }
  ::headless::tracing::StartTransferMode GetTransferMode() const { DCHECK(HasTransferMode()); return transfer_mode_.value(); }
  void SetTransferMode(::headless::tracing::StartTransferMode value) { transfer_mode_ = value; }

  // Trace data format to use. This only applies when using `ReturnAsStream`
  // transfer mode (defaults to `json`).
  bool HasStreamFormat() const { return !!stream_format_; }
  ::headless::tracing::StreamFormat GetStreamFormat() const { DCHECK(HasStreamFormat()); return stream_format_.value(); }
  void SetStreamFormat(::headless::tracing::StreamFormat value) { stream_format_ = value; }

  // Compression format to use. This only applies when using `ReturnAsStream`
  // transfer mode (defaults to `none`)
  bool HasStreamCompression() const { return !!stream_compression_; }
  ::headless::tracing::StreamCompression GetStreamCompression() const { DCHECK(HasStreamCompression()); return stream_compression_.value(); }
  void SetStreamCompression(::headless::tracing::StreamCompression value) { stream_compression_ = value; }

  bool HasTraceConfig() const { return !!trace_config_; }
  const ::headless::tracing::TraceConfig* GetTraceConfig() const { DCHECK(HasTraceConfig()); return trace_config_.value().get(); }
  void SetTraceConfig(std::unique_ptr<::headless::tracing::TraceConfig> value) { trace_config_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartParams> Clone() const;

  template<int STATE>
  class StartParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    StartParamsBuilder<STATE>& SetCategories(const std::string& value) {
      result_->SetCategories(value);
      return *this;
    }

    StartParamsBuilder<STATE>& SetOptions(const std::string& value) {
      result_->SetOptions(value);
      return *this;
    }

    StartParamsBuilder<STATE>& SetBufferUsageReportingInterval(double value) {
      result_->SetBufferUsageReportingInterval(value);
      return *this;
    }

    StartParamsBuilder<STATE>& SetTransferMode(::headless::tracing::StartTransferMode value) {
      result_->SetTransferMode(value);
      return *this;
    }

    StartParamsBuilder<STATE>& SetStreamFormat(::headless::tracing::StreamFormat value) {
      result_->SetStreamFormat(value);
      return *this;
    }

    StartParamsBuilder<STATE>& SetStreamCompression(::headless::tracing::StreamCompression value) {
      result_->SetStreamCompression(value);
      return *this;
    }

    StartParamsBuilder<STATE>& SetTraceConfig(std::unique_ptr<::headless::tracing::TraceConfig> value) {
      result_->SetTraceConfig(std::move(value));
      return *this;
    }

    std::unique_ptr<StartParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartParams;
    StartParamsBuilder() : result_(new StartParams()) { }

    template<int STEP> StartParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartParams> result_;
  };

  static StartParamsBuilder<0> Builder() {
    return StartParamsBuilder<0>();
  }

 private:
  StartParams() { }

  base::Optional<std::string> categories_;
  base::Optional<std::string> options_;
  base::Optional<double> buffer_usage_reporting_interval_;
  base::Optional<::headless::tracing::StartTransferMode> transfer_mode_;
  base::Optional<::headless::tracing::StreamFormat> stream_format_;
  base::Optional<::headless::tracing::StreamCompression> stream_compression_;
  base::Optional<std::unique_ptr<::headless::tracing::TraceConfig>> trace_config_;

  DISALLOW_COPY_AND_ASSIGN(StartParams);
};


// Result for the Start command.
class HEADLESS_EXPORT StartResult {
 public:
  static std::unique_ptr<StartResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartResult> Clone() const;

  template<int STATE>
  class StartResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartResult;
    StartResultBuilder() : result_(new StartResult()) { }

    template<int STEP> StartResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartResult> result_;
  };

  static StartResultBuilder<0> Builder() {
    return StartResultBuilder<0>();
  }

 private:
  StartResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartResult);
};


// Parameters for the BufferUsage event.
class HEADLESS_EXPORT BufferUsageParams {
 public:
  static std::unique_ptr<BufferUsageParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~BufferUsageParams() { }

  // A number in range [0..1] that indicates the used size of event buffer as a fraction of its
  // total size.
  bool HasPercentFull() const { return !!percent_full_; }
  double GetPercentFull() const { DCHECK(HasPercentFull()); return percent_full_.value(); }
  void SetPercentFull(double value) { percent_full_ = value; }

  // An approximate number of events in the trace log.
  bool HasEventCount() const { return !!event_count_; }
  double GetEventCount() const { DCHECK(HasEventCount()); return event_count_.value(); }
  void SetEventCount(double value) { event_count_ = value; }

  // A number in range [0..1] that indicates the used size of event buffer as a fraction of its
  // total size.
  bool HasValue() const { return !!value_; }
  double GetValue() const { DCHECK(HasValue()); return value_.value(); }
  void SetValue(double value) { value_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<BufferUsageParams> Clone() const;

  template<int STATE>
  class BufferUsageParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    BufferUsageParamsBuilder<STATE>& SetPercentFull(double value) {
      result_->SetPercentFull(value);
      return *this;
    }

    BufferUsageParamsBuilder<STATE>& SetEventCount(double value) {
      result_->SetEventCount(value);
      return *this;
    }

    BufferUsageParamsBuilder<STATE>& SetValue(double value) {
      result_->SetValue(value);
      return *this;
    }

    std::unique_ptr<BufferUsageParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class BufferUsageParams;
    BufferUsageParamsBuilder() : result_(new BufferUsageParams()) { }

    template<int STEP> BufferUsageParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<BufferUsageParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<BufferUsageParams> result_;
  };

  static BufferUsageParamsBuilder<0> Builder() {
    return BufferUsageParamsBuilder<0>();
  }

 private:
  BufferUsageParams() { }

  base::Optional<double> percent_full_;
  base::Optional<double> event_count_;
  base::Optional<double> value_;

  DISALLOW_COPY_AND_ASSIGN(BufferUsageParams);
};


// Parameters for the DataCollected event.
class HEADLESS_EXPORT DataCollectedParams {
 public:
  static std::unique_ptr<DataCollectedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~DataCollectedParams() { }

  const std::vector<std::unique_ptr<base::Value>>* GetValue() const { return &value_; }
  void SetValue(std::vector<std::unique_ptr<base::Value>> value) { value_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<DataCollectedParams> Clone() const;

  template<int STATE>
  class DataCollectedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kValueSet = 1 << 1,
      kAllRequiredFieldsSet = (kValueSet | 0)
    };

    DataCollectedParamsBuilder<STATE | kValueSet>& SetValue(std::vector<std::unique_ptr<base::Value>> value) {
      static_assert(!(STATE & kValueSet), "property value should not have already been set");
      result_->SetValue(std::move(value));
      return CastState<kValueSet>();
    }

    std::unique_ptr<DataCollectedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class DataCollectedParams;
    DataCollectedParamsBuilder() : result_(new DataCollectedParams()) { }

    template<int STEP> DataCollectedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<DataCollectedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<DataCollectedParams> result_;
  };

  static DataCollectedParamsBuilder<0> Builder() {
    return DataCollectedParamsBuilder<0>();
  }

 private:
  DataCollectedParams() { }

  std::vector<std::unique_ptr<base::Value>> value_;

  DISALLOW_COPY_AND_ASSIGN(DataCollectedParams);
};


// Parameters for the TracingComplete event.
class HEADLESS_EXPORT TracingCompleteParams {
 public:
  static std::unique_ptr<TracingCompleteParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~TracingCompleteParams() { }

  // Indicates whether some trace data is known to have been lost, e.g. because the trace ring
  // buffer wrapped around.
  bool GetDataLossOccurred() const { return data_loss_occurred_; }
  void SetDataLossOccurred(bool value) { data_loss_occurred_ = value; }

  // A handle of the stream that holds resulting trace data.
  bool HasStream() const { return !!stream_; }
  std::string GetStream() const { DCHECK(HasStream()); return stream_.value(); }
  void SetStream(const std::string& value) { stream_ = value; }

  // Trace data format of returned stream.
  bool HasTraceFormat() const { return !!trace_format_; }
  ::headless::tracing::StreamFormat GetTraceFormat() const { DCHECK(HasTraceFormat()); return trace_format_.value(); }
  void SetTraceFormat(::headless::tracing::StreamFormat value) { trace_format_ = value; }

  // Compression format of returned stream.
  bool HasStreamCompression() const { return !!stream_compression_; }
  ::headless::tracing::StreamCompression GetStreamCompression() const { DCHECK(HasStreamCompression()); return stream_compression_.value(); }
  void SetStreamCompression(::headless::tracing::StreamCompression value) { stream_compression_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<TracingCompleteParams> Clone() const;

  template<int STATE>
  class TracingCompleteParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kDataLossOccurredSet = 1 << 1,
      kAllRequiredFieldsSet = (kDataLossOccurredSet | 0)
    };

    TracingCompleteParamsBuilder<STATE | kDataLossOccurredSet>& SetDataLossOccurred(bool value) {
      static_assert(!(STATE & kDataLossOccurredSet), "property dataLossOccurred should not have already been set");
      result_->SetDataLossOccurred(value);
      return CastState<kDataLossOccurredSet>();
    }

    TracingCompleteParamsBuilder<STATE>& SetStream(const std::string& value) {
      result_->SetStream(value);
      return *this;
    }

    TracingCompleteParamsBuilder<STATE>& SetTraceFormat(::headless::tracing::StreamFormat value) {
      result_->SetTraceFormat(value);
      return *this;
    }

    TracingCompleteParamsBuilder<STATE>& SetStreamCompression(::headless::tracing::StreamCompression value) {
      result_->SetStreamCompression(value);
      return *this;
    }

    std::unique_ptr<TracingCompleteParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class TracingCompleteParams;
    TracingCompleteParamsBuilder() : result_(new TracingCompleteParams()) { }

    template<int STEP> TracingCompleteParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<TracingCompleteParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<TracingCompleteParams> result_;
  };

  static TracingCompleteParamsBuilder<0> Builder() {
    return TracingCompleteParamsBuilder<0>();
  }

 private:
  TracingCompleteParams() { }

  bool data_loss_occurred_;
  base::Optional<std::string> stream_;
  base::Optional<::headless::tracing::StreamFormat> trace_format_;
  base::Optional<::headless::tracing::StreamCompression> stream_compression_;

  DISALLOW_COPY_AND_ASSIGN(TracingCompleteParams);
};


}  // namespace tracing

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_TRACING_H_
