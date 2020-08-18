// This file is generated

// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_HEAP_PROFILER_H_
#define HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_HEAP_PROFILER_H_

#include "base/notreached.h"
#include "headless/public/devtools/domains/types_heap_profiler.h"
#include "headless/public/internal/value_conversions.h"

namespace headless {
namespace internal {



template <>
struct FromValue<heap_profiler::SamplingHeapProfileNode> {
  static std::unique_ptr<heap_profiler::SamplingHeapProfileNode> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::SamplingHeapProfileNode::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::SamplingHeapProfileNode& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::SamplingHeapProfileSample> {
  static std::unique_ptr<heap_profiler::SamplingHeapProfileSample> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::SamplingHeapProfileSample::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::SamplingHeapProfileSample& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::SamplingHeapProfile> {
  static std::unique_ptr<heap_profiler::SamplingHeapProfile> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::SamplingHeapProfile::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::SamplingHeapProfile& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::AddInspectedHeapObjectParams> {
  static std::unique_ptr<heap_profiler::AddInspectedHeapObjectParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::AddInspectedHeapObjectParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::AddInspectedHeapObjectParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::AddInspectedHeapObjectResult> {
  static std::unique_ptr<heap_profiler::AddInspectedHeapObjectResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::AddInspectedHeapObjectResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::AddInspectedHeapObjectResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::CollectGarbageParams> {
  static std::unique_ptr<heap_profiler::CollectGarbageParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::CollectGarbageParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::CollectGarbageParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::CollectGarbageResult> {
  static std::unique_ptr<heap_profiler::CollectGarbageResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::CollectGarbageResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::CollectGarbageResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::DisableParams> {
  static std::unique_ptr<heap_profiler::DisableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::DisableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::DisableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::DisableResult> {
  static std::unique_ptr<heap_profiler::DisableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::DisableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::DisableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::EnableParams> {
  static std::unique_ptr<heap_profiler::EnableParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::EnableParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::EnableParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::EnableResult> {
  static std::unique_ptr<heap_profiler::EnableResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::EnableResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::EnableResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::GetHeapObjectIdParams> {
  static std::unique_ptr<heap_profiler::GetHeapObjectIdParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::GetHeapObjectIdParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::GetHeapObjectIdParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::GetHeapObjectIdResult> {
  static std::unique_ptr<heap_profiler::GetHeapObjectIdResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::GetHeapObjectIdResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::GetHeapObjectIdResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::GetObjectByHeapObjectIdParams> {
  static std::unique_ptr<heap_profiler::GetObjectByHeapObjectIdParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::GetObjectByHeapObjectIdParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::GetObjectByHeapObjectIdParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::GetObjectByHeapObjectIdResult> {
  static std::unique_ptr<heap_profiler::GetObjectByHeapObjectIdResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::GetObjectByHeapObjectIdResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::GetObjectByHeapObjectIdResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::GetSamplingProfileParams> {
  static std::unique_ptr<heap_profiler::GetSamplingProfileParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::GetSamplingProfileParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::GetSamplingProfileParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::GetSamplingProfileResult> {
  static std::unique_ptr<heap_profiler::GetSamplingProfileResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::GetSamplingProfileResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::GetSamplingProfileResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StartSamplingParams> {
  static std::unique_ptr<heap_profiler::StartSamplingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StartSamplingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StartSamplingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StartSamplingResult> {
  static std::unique_ptr<heap_profiler::StartSamplingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StartSamplingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StartSamplingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StartTrackingHeapObjectsParams> {
  static std::unique_ptr<heap_profiler::StartTrackingHeapObjectsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StartTrackingHeapObjectsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StartTrackingHeapObjectsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StartTrackingHeapObjectsResult> {
  static std::unique_ptr<heap_profiler::StartTrackingHeapObjectsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StartTrackingHeapObjectsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StartTrackingHeapObjectsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StopSamplingParams> {
  static std::unique_ptr<heap_profiler::StopSamplingParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StopSamplingParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StopSamplingParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StopSamplingResult> {
  static std::unique_ptr<heap_profiler::StopSamplingResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StopSamplingResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StopSamplingResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StopTrackingHeapObjectsParams> {
  static std::unique_ptr<heap_profiler::StopTrackingHeapObjectsParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StopTrackingHeapObjectsParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StopTrackingHeapObjectsParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::StopTrackingHeapObjectsResult> {
  static std::unique_ptr<heap_profiler::StopTrackingHeapObjectsResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::StopTrackingHeapObjectsResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::StopTrackingHeapObjectsResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::TakeHeapSnapshotParams> {
  static std::unique_ptr<heap_profiler::TakeHeapSnapshotParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::TakeHeapSnapshotParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::TakeHeapSnapshotParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::TakeHeapSnapshotResult> {
  static std::unique_ptr<heap_profiler::TakeHeapSnapshotResult> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::TakeHeapSnapshotResult::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::TakeHeapSnapshotResult& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::AddHeapSnapshotChunkParams> {
  static std::unique_ptr<heap_profiler::AddHeapSnapshotChunkParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::AddHeapSnapshotChunkParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::AddHeapSnapshotChunkParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::HeapStatsUpdateParams> {
  static std::unique_ptr<heap_profiler::HeapStatsUpdateParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::HeapStatsUpdateParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::HeapStatsUpdateParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::LastSeenObjectIdParams> {
  static std::unique_ptr<heap_profiler::LastSeenObjectIdParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::LastSeenObjectIdParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::LastSeenObjectIdParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::ReportHeapSnapshotProgressParams> {
  static std::unique_ptr<heap_profiler::ReportHeapSnapshotProgressParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::ReportHeapSnapshotProgressParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::ReportHeapSnapshotProgressParams& value) {
  return value.Serialize();
}


template <>
struct FromValue<heap_profiler::ResetProfilesParams> {
  static std::unique_ptr<heap_profiler::ResetProfilesParams> Parse(const base::Value& value, ErrorReporter* errors) {
    return heap_profiler::ResetProfilesParams::Parse(value, errors);
  }
};

template <>
inline std::unique_ptr<base::Value> ToValue(const heap_profiler::ResetProfilesParams& value) {
  return value.Serialize();
}


}  // namespace internal
}  // namespace headless

#endif  // HEADLESS_PUBLIC_DEVTOOLS_INTERNAL_TYPE_CONVERSIONS_HEAP_PROFILER_H_
