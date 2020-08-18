// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_LOG_H_
#define HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_LOG_H_

#include "base/optional.h"
#include "base/values.h"
#include "headless/lib/browser/protocol/base_string_adapter.h"
#include "headless/public/devtools/internal/types_forward_declarations_dom.h"
#include "headless/public/devtools/internal/types_forward_declarations_debugger.h"
#include "headless/public/devtools/internal/types_forward_declarations_emulation.h"
#include "headless/public/devtools/internal/types_forward_declarations_io.h"
#include "headless/public/devtools/internal/types_forward_declarations_log.h"
#include "headless/public/devtools/internal/types_forward_declarations_network.h"
#include "headless/public/devtools/internal/types_forward_declarations_page.h"
#include "headless/public/devtools/internal/types_forward_declarations_runtime.h"
#include "headless/public/devtools/internal/types_forward_declarations_security.h"
#include "headless/public/headless_export.h"

namespace headless {

class ErrorReporter;

namespace log {

// Log entry.
class HEADLESS_EXPORT LogEntry {
 public:
  static std::unique_ptr<LogEntry> Parse(const base::Value& value, ErrorReporter* errors);
  ~LogEntry() { }

  // Log entry source.
  ::headless::log::LogEntrySource GetSource() const { return source_; }
  void SetSource(::headless::log::LogEntrySource value) { source_ = value; }

  // Log entry severity.
  ::headless::log::LogEntryLevel GetLevel() const { return level_; }
  void SetLevel(::headless::log::LogEntryLevel value) { level_ = value; }

  // Logged text.
  std::string GetText() const { return text_; }
  void SetText(const std::string& value) { text_ = value; }

  // Timestamp when this entry was added.
  double GetTimestamp() const { return timestamp_; }
  void SetTimestamp(double value) { timestamp_ = value; }

  // URL of the resource if known.
  bool HasUrl() const { return !!url_; }
  std::string GetUrl() const { DCHECK(HasUrl()); return url_.value(); }
  void SetUrl(const std::string& value) { url_ = value; }

  // Line number in the resource.
  bool HasLineNumber() const { return !!line_number_; }
  int GetLineNumber() const { DCHECK(HasLineNumber()); return line_number_.value(); }
  void SetLineNumber(int value) { line_number_ = value; }

  // JavaScript stack trace.
  bool HasStackTrace() const { return !!stack_trace_; }
  const ::headless::runtime::StackTrace* GetStackTrace() const { DCHECK(HasStackTrace()); return stack_trace_.value().get(); }
  void SetStackTrace(std::unique_ptr<::headless::runtime::StackTrace> value) { stack_trace_ = std::move(value); }

  // Identifier of the network request associated with this entry.
  bool HasNetworkRequestId() const { return !!network_request_id_; }
  std::string GetNetworkRequestId() const { DCHECK(HasNetworkRequestId()); return network_request_id_.value(); }
  void SetNetworkRequestId(const std::string& value) { network_request_id_ = value; }

  // Identifier of the worker associated with this entry.
  bool HasWorkerId() const { return !!worker_id_; }
  std::string GetWorkerId() const { DCHECK(HasWorkerId()); return worker_id_.value(); }
  void SetWorkerId(const std::string& value) { worker_id_ = value; }

  // Call arguments.
  bool HasArgs() const { return !!args_; }
  const std::vector<std::unique_ptr<::headless::runtime::RemoteObject>>* GetArgs() const { DCHECK(HasArgs()); return &args_.value(); }
  void SetArgs(std::vector<std::unique_ptr<::headless::runtime::RemoteObject>> value) { args_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<LogEntry> Clone() const;

  template<int STATE>
  class LogEntryBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kSourceSet = 1 << 1,
    kLevelSet = 1 << 2,
    kTextSet = 1 << 3,
    kTimestampSet = 1 << 4,
      kAllRequiredFieldsSet = (kSourceSet | kLevelSet | kTextSet | kTimestampSet | 0)
    };

    LogEntryBuilder<STATE | kSourceSet>& SetSource(::headless::log::LogEntrySource value) {
      static_assert(!(STATE & kSourceSet), "property source should not have already been set");
      result_->SetSource(value);
      return CastState<kSourceSet>();
    }

    LogEntryBuilder<STATE | kLevelSet>& SetLevel(::headless::log::LogEntryLevel value) {
      static_assert(!(STATE & kLevelSet), "property level should not have already been set");
      result_->SetLevel(value);
      return CastState<kLevelSet>();
    }

    LogEntryBuilder<STATE | kTextSet>& SetText(const std::string& value) {
      static_assert(!(STATE & kTextSet), "property text should not have already been set");
      result_->SetText(value);
      return CastState<kTextSet>();
    }

    LogEntryBuilder<STATE | kTimestampSet>& SetTimestamp(double value) {
      static_assert(!(STATE & kTimestampSet), "property timestamp should not have already been set");
      result_->SetTimestamp(value);
      return CastState<kTimestampSet>();
    }

    LogEntryBuilder<STATE>& SetUrl(const std::string& value) {
      result_->SetUrl(value);
      return *this;
    }

    LogEntryBuilder<STATE>& SetLineNumber(int value) {
      result_->SetLineNumber(value);
      return *this;
    }

    LogEntryBuilder<STATE>& SetStackTrace(std::unique_ptr<::headless::runtime::StackTrace> value) {
      result_->SetStackTrace(std::move(value));
      return *this;
    }

    LogEntryBuilder<STATE>& SetNetworkRequestId(const std::string& value) {
      result_->SetNetworkRequestId(value);
      return *this;
    }

    LogEntryBuilder<STATE>& SetWorkerId(const std::string& value) {
      result_->SetWorkerId(value);
      return *this;
    }

    LogEntryBuilder<STATE>& SetArgs(std::vector<std::unique_ptr<::headless::runtime::RemoteObject>> value) {
      result_->SetArgs(std::move(value));
      return *this;
    }

    std::unique_ptr<LogEntry> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class LogEntry;
    LogEntryBuilder() : result_(new LogEntry()) { }

    template<int STEP> LogEntryBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<LogEntryBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<LogEntry> result_;
  };

  static LogEntryBuilder<0> Builder() {
    return LogEntryBuilder<0>();
  }

 private:
  LogEntry() { }

  ::headless::log::LogEntrySource source_;
  ::headless::log::LogEntryLevel level_;
  std::string text_;
  double timestamp_;
  base::Optional<std::string> url_;
  base::Optional<int> line_number_;
  base::Optional<std::unique_ptr<::headless::runtime::StackTrace>> stack_trace_;
  base::Optional<std::string> network_request_id_;
  base::Optional<std::string> worker_id_;
  base::Optional<std::vector<std::unique_ptr<::headless::runtime::RemoteObject>>> args_;

  DISALLOW_COPY_AND_ASSIGN(LogEntry);
};


// Violation configuration setting.
class HEADLESS_EXPORT ViolationSetting {
 public:
  static std::unique_ptr<ViolationSetting> Parse(const base::Value& value, ErrorReporter* errors);
  ~ViolationSetting() { }

  // Violation type.
  ::headless::log::ViolationSettingName GetName() const { return name_; }
  void SetName(::headless::log::ViolationSettingName value) { name_ = value; }

  // Time threshold to trigger upon.
  double GetThreshold() const { return threshold_; }
  void SetThreshold(double value) { threshold_ = value; }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ViolationSetting> Clone() const;

  template<int STATE>
  class ViolationSettingBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kNameSet = 1 << 1,
    kThresholdSet = 1 << 2,
      kAllRequiredFieldsSet = (kNameSet | kThresholdSet | 0)
    };

    ViolationSettingBuilder<STATE | kNameSet>& SetName(::headless::log::ViolationSettingName value) {
      static_assert(!(STATE & kNameSet), "property name should not have already been set");
      result_->SetName(value);
      return CastState<kNameSet>();
    }

    ViolationSettingBuilder<STATE | kThresholdSet>& SetThreshold(double value) {
      static_assert(!(STATE & kThresholdSet), "property threshold should not have already been set");
      result_->SetThreshold(value);
      return CastState<kThresholdSet>();
    }

    std::unique_ptr<ViolationSetting> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ViolationSetting;
    ViolationSettingBuilder() : result_(new ViolationSetting()) { }

    template<int STEP> ViolationSettingBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ViolationSettingBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ViolationSetting> result_;
  };

  static ViolationSettingBuilder<0> Builder() {
    return ViolationSettingBuilder<0>();
  }

 private:
  ViolationSetting() { }

  ::headless::log::ViolationSettingName name_;
  double threshold_;

  DISALLOW_COPY_AND_ASSIGN(ViolationSetting);
};


// Parameters for the Clear command.
class HEADLESS_EXPORT ClearParams {
 public:
  static std::unique_ptr<ClearParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearParams> Clone() const;

  template<int STATE>
  class ClearParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearParams;
    ClearParamsBuilder() : result_(new ClearParams()) { }

    template<int STEP> ClearParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearParams> result_;
  };

  static ClearParamsBuilder<0> Builder() {
    return ClearParamsBuilder<0>();
  }

 private:
  ClearParams() { }


  DISALLOW_COPY_AND_ASSIGN(ClearParams);
};


// Result for the Clear command.
class HEADLESS_EXPORT ClearResult {
 public:
  static std::unique_ptr<ClearResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~ClearResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<ClearResult> Clone() const;

  template<int STATE>
  class ClearResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<ClearResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class ClearResult;
    ClearResultBuilder() : result_(new ClearResult()) { }

    template<int STEP> ClearResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<ClearResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<ClearResult> result_;
  };

  static ClearResultBuilder<0> Builder() {
    return ClearResultBuilder<0>();
  }

 private:
  ClearResult() { }


  DISALLOW_COPY_AND_ASSIGN(ClearResult);
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


// Parameters for the StartViolationsReport command.
class HEADLESS_EXPORT StartViolationsReportParams {
 public:
  static std::unique_ptr<StartViolationsReportParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartViolationsReportParams() { }

  // Configuration for violations.
  const std::vector<std::unique_ptr<::headless::log::ViolationSetting>>* GetConfig() const { return &config_; }
  void SetConfig(std::vector<std::unique_ptr<::headless::log::ViolationSetting>> value) { config_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartViolationsReportParams> Clone() const;

  template<int STATE>
  class StartViolationsReportParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kConfigSet = 1 << 1,
      kAllRequiredFieldsSet = (kConfigSet | 0)
    };

    StartViolationsReportParamsBuilder<STATE | kConfigSet>& SetConfig(std::vector<std::unique_ptr<::headless::log::ViolationSetting>> value) {
      static_assert(!(STATE & kConfigSet), "property config should not have already been set");
      result_->SetConfig(std::move(value));
      return CastState<kConfigSet>();
    }

    std::unique_ptr<StartViolationsReportParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartViolationsReportParams;
    StartViolationsReportParamsBuilder() : result_(new StartViolationsReportParams()) { }

    template<int STEP> StartViolationsReportParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartViolationsReportParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartViolationsReportParams> result_;
  };

  static StartViolationsReportParamsBuilder<0> Builder() {
    return StartViolationsReportParamsBuilder<0>();
  }

 private:
  StartViolationsReportParams() { }

  std::vector<std::unique_ptr<::headless::log::ViolationSetting>> config_;

  DISALLOW_COPY_AND_ASSIGN(StartViolationsReportParams);
};


// Result for the StartViolationsReport command.
class HEADLESS_EXPORT StartViolationsReportResult {
 public:
  static std::unique_ptr<StartViolationsReportResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StartViolationsReportResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StartViolationsReportResult> Clone() const;

  template<int STATE>
  class StartViolationsReportResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StartViolationsReportResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StartViolationsReportResult;
    StartViolationsReportResultBuilder() : result_(new StartViolationsReportResult()) { }

    template<int STEP> StartViolationsReportResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StartViolationsReportResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StartViolationsReportResult> result_;
  };

  static StartViolationsReportResultBuilder<0> Builder() {
    return StartViolationsReportResultBuilder<0>();
  }

 private:
  StartViolationsReportResult() { }


  DISALLOW_COPY_AND_ASSIGN(StartViolationsReportResult);
};


// Parameters for the StopViolationsReport command.
class HEADLESS_EXPORT StopViolationsReportParams {
 public:
  static std::unique_ptr<StopViolationsReportParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopViolationsReportParams() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopViolationsReportParams> Clone() const;

  template<int STATE>
  class StopViolationsReportParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopViolationsReportParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopViolationsReportParams;
    StopViolationsReportParamsBuilder() : result_(new StopViolationsReportParams()) { }

    template<int STEP> StopViolationsReportParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopViolationsReportParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopViolationsReportParams> result_;
  };

  static StopViolationsReportParamsBuilder<0> Builder() {
    return StopViolationsReportParamsBuilder<0>();
  }

 private:
  StopViolationsReportParams() { }


  DISALLOW_COPY_AND_ASSIGN(StopViolationsReportParams);
};


// Result for the StopViolationsReport command.
class HEADLESS_EXPORT StopViolationsReportResult {
 public:
  static std::unique_ptr<StopViolationsReportResult> Parse(const base::Value& value, ErrorReporter* errors);
  ~StopViolationsReportResult() { }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<StopViolationsReportResult> Clone() const;

  template<int STATE>
  class StopViolationsReportResultBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
      kAllRequiredFieldsSet = (0)
    };

    std::unique_ptr<StopViolationsReportResult> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class StopViolationsReportResult;
    StopViolationsReportResultBuilder() : result_(new StopViolationsReportResult()) { }

    template<int STEP> StopViolationsReportResultBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<StopViolationsReportResultBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<StopViolationsReportResult> result_;
  };

  static StopViolationsReportResultBuilder<0> Builder() {
    return StopViolationsReportResultBuilder<0>();
  }

 private:
  StopViolationsReportResult() { }


  DISALLOW_COPY_AND_ASSIGN(StopViolationsReportResult);
};


// Parameters for the EntryAdded event.
class HEADLESS_EXPORT EntryAddedParams {
 public:
  static std::unique_ptr<EntryAddedParams> Parse(const base::Value& value, ErrorReporter* errors);
  ~EntryAddedParams() { }

  // The entry.
  const ::headless::log::LogEntry* GetEntry() const { return entry_.get(); }
  void SetEntry(std::unique_ptr<::headless::log::LogEntry> value) { entry_ = std::move(value); }

  std::unique_ptr<base::Value> Serialize() const;
  std::unique_ptr<EntryAddedParams> Clone() const;

  template<int STATE>
  class EntryAddedParamsBuilder {
  public:
    enum {
      kNoFieldsSet = 0,
    kEntrySet = 1 << 1,
      kAllRequiredFieldsSet = (kEntrySet | 0)
    };

    EntryAddedParamsBuilder<STATE | kEntrySet>& SetEntry(std::unique_ptr<::headless::log::LogEntry> value) {
      static_assert(!(STATE & kEntrySet), "property entry should not have already been set");
      result_->SetEntry(std::move(value));
      return CastState<kEntrySet>();
    }

    std::unique_ptr<EntryAddedParams> Build() {
      static_assert(STATE == kAllRequiredFieldsSet, "all required fields should have been set");
      return std::move(result_);
    }

   private:
    friend class EntryAddedParams;
    EntryAddedParamsBuilder() : result_(new EntryAddedParams()) { }

    template<int STEP> EntryAddedParamsBuilder<STATE | STEP>& CastState() {
      return *reinterpret_cast<EntryAddedParamsBuilder<STATE | STEP>*>(this);
    }

    std::unique_ptr<EntryAddedParams> result_;
  };

  static EntryAddedParamsBuilder<0> Builder() {
    return EntryAddedParamsBuilder<0>();
  }

 private:
  EntryAddedParams() { }

  std::unique_ptr<::headless::log::LogEntry> entry_;

  DISALLOW_COPY_AND_ASSIGN(EntryAddedParams);
};


}  // namespace log

}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_DOMAINS_TYPES_LOG_H_
