// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_PROFILER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_PROFILER_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_profiler.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {


template <>
struct FromValue<profiler::ProfileNode> {
  static std::unique_ptr<profiler::ProfileNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::ProfileNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::ProfileNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::Profile> {
  static std::unique_ptr<profiler::Profile> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::Profile::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::Profile& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::PositionTickInfo> {
  static std::unique_ptr<profiler::PositionTickInfo> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::PositionTickInfo::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::PositionTickInfo& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::CoverageRange> {
  static std::unique_ptr<profiler::CoverageRange> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::CoverageRange::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::CoverageRange& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::FunctionCoverage> {
  static std::unique_ptr<profiler::FunctionCoverage> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::FunctionCoverage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::FunctionCoverage& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::ScriptCoverage> {
  static std::unique_ptr<profiler::ScriptCoverage> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::ScriptCoverage::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::ScriptCoverage& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::TypeObject> {
  static std::unique_ptr<profiler::TypeObject> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::TypeObject::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::TypeObject& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::TypeProfileEntry> {
  static std::unique_ptr<profiler::TypeProfileEntry> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::TypeProfileEntry::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::TypeProfileEntry& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::ScriptTypeProfile> {
  static std::unique_ptr<profiler::ScriptTypeProfile> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::ScriptTypeProfile::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::ScriptTypeProfile& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::CounterInfo> {
  static std::unique_ptr<profiler::CounterInfo> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::CounterInfo::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::CounterInfo& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::DisableParams> {
  static std::unique_ptr<profiler::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::DisableResult> {
  static std::unique_ptr<profiler::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::EnableParams> {
  static std::unique_ptr<profiler::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::EnableResult> {
  static std::unique_ptr<profiler::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::GetBestEffortCoverageParams> {
  static std::unique_ptr<profiler::GetBestEffortCoverageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::GetBestEffortCoverageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::GetBestEffortCoverageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::GetBestEffortCoverageResult> {
  static std::unique_ptr<profiler::GetBestEffortCoverageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::GetBestEffortCoverageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::GetBestEffortCoverageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::SetSamplingIntervalParams> {
  static std::unique_ptr<profiler::SetSamplingIntervalParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::SetSamplingIntervalParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::SetSamplingIntervalParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::SetSamplingIntervalResult> {
  static std::unique_ptr<profiler::SetSamplingIntervalResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::SetSamplingIntervalResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::SetSamplingIntervalResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StartParams> {
  static std::unique_ptr<profiler::StartParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StartParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StartParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StartResult> {
  static std::unique_ptr<profiler::StartResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StartResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StartResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StartPreciseCoverageParams> {
  static std::unique_ptr<profiler::StartPreciseCoverageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StartPreciseCoverageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StartPreciseCoverageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StartPreciseCoverageResult> {
  static std::unique_ptr<profiler::StartPreciseCoverageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StartPreciseCoverageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StartPreciseCoverageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StartTypeProfileParams> {
  static std::unique_ptr<profiler::StartTypeProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StartTypeProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StartTypeProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StartTypeProfileResult> {
  static std::unique_ptr<profiler::StartTypeProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StartTypeProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StartTypeProfileResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StopParams> {
  static std::unique_ptr<profiler::StopParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StopParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StopParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StopResult> {
  static std::unique_ptr<profiler::StopResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StopResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StopResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StopPreciseCoverageParams> {
  static std::unique_ptr<profiler::StopPreciseCoverageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StopPreciseCoverageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StopPreciseCoverageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StopPreciseCoverageResult> {
  static std::unique_ptr<profiler::StopPreciseCoverageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StopPreciseCoverageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StopPreciseCoverageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StopTypeProfileParams> {
  static std::unique_ptr<profiler::StopTypeProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StopTypeProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StopTypeProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::StopTypeProfileResult> {
  static std::unique_ptr<profiler::StopTypeProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::StopTypeProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::StopTypeProfileResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::TakePreciseCoverageParams> {
  static std::unique_ptr<profiler::TakePreciseCoverageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::TakePreciseCoverageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::TakePreciseCoverageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::TakePreciseCoverageResult> {
  static std::unique_ptr<profiler::TakePreciseCoverageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::TakePreciseCoverageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::TakePreciseCoverageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::TakeTypeProfileParams> {
  static std::unique_ptr<profiler::TakeTypeProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::TakeTypeProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::TakeTypeProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::TakeTypeProfileResult> {
  static std::unique_ptr<profiler::TakeTypeProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::TakeTypeProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::TakeTypeProfileResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::EnableRuntimeCallStatsParams> {
  static std::unique_ptr<profiler::EnableRuntimeCallStatsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::EnableRuntimeCallStatsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::EnableRuntimeCallStatsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::EnableRuntimeCallStatsResult> {
  static std::unique_ptr<profiler::EnableRuntimeCallStatsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::EnableRuntimeCallStatsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::EnableRuntimeCallStatsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::DisableRuntimeCallStatsParams> {
  static std::unique_ptr<profiler::DisableRuntimeCallStatsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::DisableRuntimeCallStatsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::DisableRuntimeCallStatsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::DisableRuntimeCallStatsResult> {
  static std::unique_ptr<profiler::DisableRuntimeCallStatsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::DisableRuntimeCallStatsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::DisableRuntimeCallStatsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::GetRuntimeCallStatsParams> {
  static std::unique_ptr<profiler::GetRuntimeCallStatsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::GetRuntimeCallStatsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::GetRuntimeCallStatsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::GetRuntimeCallStatsResult> {
  static std::unique_ptr<profiler::GetRuntimeCallStatsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::GetRuntimeCallStatsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::GetRuntimeCallStatsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::ConsoleProfileFinishedParams> {
  static std::unique_ptr<profiler::ConsoleProfileFinishedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::ConsoleProfileFinishedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::ConsoleProfileFinishedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::ConsoleProfileStartedParams> {
  static std::unique_ptr<profiler::ConsoleProfileStartedParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::ConsoleProfileStartedParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::ConsoleProfileStartedParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<profiler::PreciseCoverageDeltaUpdateParams> {
  static std::unique_ptr<profiler::PreciseCoverageDeltaUpdateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return profiler::PreciseCoverageDeltaUpdateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const profiler::PreciseCoverageDeltaUpdateParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_PROFILER_H_
