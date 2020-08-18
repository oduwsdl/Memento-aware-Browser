// Copyright (c) 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// GENERATED FROM THE API DEFINITION IN
//   extensions/common/api/metrics_private.json
// DO NOT EDIT.

#ifndef EXTENSIONS_COMMON_API_METRICS_PRIVATE_H__
#define EXTENSIONS_COMMON_API_METRICS_PRIVATE_H__

#include <stdint.h>

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "base/logging.h"
#include "base/values.h"

namespace extensions {
namespace api {
namespace metrics_private {

//
// Types
//

// The type of metric, such as 'histogram-log' or 'histogram-linear'.
enum MetricTypeType {
  METRIC_TYPE_TYPE_NONE,
  METRIC_TYPE_TYPE_HISTOGRAM_LOG,
  METRIC_TYPE_TYPE_HISTOGRAM_LINEAR,
  METRIC_TYPE_TYPE_LAST = METRIC_TYPE_TYPE_HISTOGRAM_LINEAR,
};


const char* ToString(MetricTypeType as_enum);
MetricTypeType ParseMetricTypeType(const std::string& as_string);

// Describes the type of metric that is to be collected.
struct MetricType {
  MetricType();
  ~MetricType();
  MetricType(MetricType&& rhs);
  MetricType& operator=(MetricType&& rhs);

  // Populates a MetricType object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, MetricType* out);

  // Creates a MetricType object from a base::Value, or NULL on failure.
  static std::unique_ptr<MetricType> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this MetricType object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // A unique name within the extension for the metric.
  std::string metric_name;

  MetricTypeType type;

  // The minimum sample value to be recoded.  Must be greater than zero.
  int min;

  // The maximum sample value to be recoded.
  int max;

  // The number of buckets to use when separating the recorded values.
  int buckets;


 private:
  DISALLOW_COPY_AND_ASSIGN(MetricType);
};

struct HistogramBucket {
  HistogramBucket();
  ~HistogramBucket();
  HistogramBucket(HistogramBucket&& rhs);
  HistogramBucket& operator=(HistogramBucket&& rhs);

  // Populates a HistogramBucket object from a base::Value. Returns whether
  // |out| was successfully populated.
  static bool Populate(const base::Value& value, HistogramBucket* out);

  // Creates a HistogramBucket object from a base::Value, or NULL on failure.
  static std::unique_ptr<HistogramBucket> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this HistogramBucket object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Minimum sample value that can be stored in this bucket (i.e. inclusive).
  int min;

  // Exclusive maximum value for samples stored this bucket.
  int max;

  // Number of samples stored in this bucket.
  int count;


 private:
  DISALLOW_COPY_AND_ASSIGN(HistogramBucket);
};

struct Histogram {
  Histogram();
  ~Histogram();
  Histogram(Histogram&& rhs);
  Histogram& operator=(Histogram&& rhs);

  // Populates a Histogram object from a base::Value. Returns whether |out| was
  // successfully populated.
  static bool Populate(const base::Value& value, Histogram* out);

  // Creates a Histogram object from a base::Value, or NULL on failure.
  static std::unique_ptr<Histogram> FromValue(const base::Value& value);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Histogram object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  // Sum of the all entries.
  double sum;

  // Buckets containing samples.
  std::vector<HistogramBucket> buckets;


 private:
  DISALLOW_COPY_AND_ASSIGN(Histogram);
};


//
// Functions
//

namespace GetHistogram {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  // Histogram name, e.g. 'Accessibility.CrosAutoclick'.
  std::string name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const Histogram& histogram);
}  // namespace Results

}  // namespace GetHistogram

namespace GetIsCrashReportingEnabled {

namespace Results {

std::unique_ptr<base::ListValue> Create(bool is_enabled);
}  // namespace Results

}  // namespace GetIsCrashReportingEnabled

namespace GetFieldTrial {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

std::unique_ptr<base::ListValue> Create(const std::string& group);
}  // namespace Results

}  // namespace GetFieldTrial

namespace GetVariationParams {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

namespace Results {

struct Params {
  Params();
  ~Params();
  Params(Params&& rhs);
  Params& operator=(Params&& rhs);

  // Returns a new base::DictionaryValue representing the serialized form of
  // this Params object.
  std::unique_ptr<base::DictionaryValue> ToValue() const;

  std::map<std::string, std::string> additional_properties;

 private:
  DISALLOW_COPY_AND_ASSIGN(Params);
};


std::unique_ptr<base::ListValue> Create(const Params& params);
}  // namespace Results

}  // namespace GetVariationParams

namespace RecordUserAction {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string name;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordUserAction

namespace RecordPercentage {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordPercentage

namespace RecordCount {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordCount

namespace RecordSmallCount {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordSmallCount

namespace RecordMediumCount {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordMediumCount

namespace RecordTime {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordTime

namespace RecordMediumTime {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordMediumTime

namespace RecordLongTime {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordLongTime

namespace RecordSparseHashable {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  std::string value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordSparseHashable

namespace RecordSparseValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordSparseValue

namespace RecordValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  MetricType metric;

  int value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordValue

namespace RecordBoolean {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  bool value;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordBoolean

namespace RecordEnumerationValue {

struct Params {
  static std::unique_ptr<Params> Create(const base::ListValue& args);
  ~Params();

  std::string metric_name;

  int value;

  int enum_size;


 private:
  Params();

  DISALLOW_COPY_AND_ASSIGN(Params);
};

}  // namespace RecordEnumerationValue

}  // namespace metrics_private
}  // namespace api
}  // namespace extensions
#endif  // EXTENSIONS_COMMON_API_METRICS_PRIVATE_H__
