// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/dns/httpssvc_metrics.h"

#include <string>
#include <tuple>

#include "base/feature_list.h"
#include "base/strings/strcat.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"
#include "base/test/metrics/histogram_tester.h"
#include "base/test/scoped_feature_list.h"
#include "net/base/features.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace net {

// int: number of domains
// bool: extra leading comma
// bool: extra trailing comma
using DomainListQuirksTuple = std::tuple<int, bool, bool>;

// bool: DnsHttpssvc feature is enabled
// bool: DnsHttpssvcUseIntegrity feature param
// bool: DnsHttpssvcUseHttpssvc feature param
// bool: DnsHttpssvcControlDomainWildcard feature param
using HttpssvcFeatureTuple = std::tuple<bool, bool, bool, bool>;

// DomainListQuirksTuple: quirks for the experimental domain list.
// DomainListQuirksTuple: quirks for the control domain list.
// HttpssvcFeatureTuple: config for the whole DnsHttpssvc feature.
using ParsingTestParamTuple = std::
    tuple<DomainListQuirksTuple, DomainListQuirksTuple, HttpssvcFeatureTuple>;

// bool: whether we are querying for an experimental domain or a control domain
// HttpssvcFeatureTuple: config for the whole DnsHttpssvc feature.
using MetricsTestParamTuple = std::tuple<bool, HttpssvcFeatureTuple>;

// Create a comma-separated list of |domains| with the given |quirks|.
std::string FlattenDomainList(const std::vector<std::string>& domains,
                              DomainListQuirksTuple quirks) {
  int num_domains;
  bool leading_comma, trailing_comma;
  std::tie(num_domains, leading_comma, trailing_comma) = quirks;

  CHECK_EQ(static_cast<size_t>(num_domains), domains.size());
  std::string flattened = base::JoinString(domains, ",");
  if (leading_comma)
    flattened.insert(flattened.begin(), ',');
  if (trailing_comma)
    flattened.push_back(',');
  return flattened;
}

// Intermediate representation constructed from test parameters.
struct HttpssvcFeatureConfig {
  HttpssvcFeatureConfig() = default;

  explicit HttpssvcFeatureConfig(const HttpssvcFeatureTuple& feature_tuple,
                                 base::StringPiece experiment_domains,
                                 base::StringPiece control_domains)
      : experiment_domains(experiment_domains.as_string()),
        control_domains(control_domains.as_string()) {
    std::tie(enabled, use_integrity, use_httpssvc, control_domain_wildcard) =
        feature_tuple;
  }

  void Apply(base::test::ScopedFeatureList* scoped_feature_list) const {
    if (!enabled) {
      scoped_feature_list->InitAndDisableFeature(features::kDnsHttpssvc);
      return;
    }
    auto stringify = [](bool b) -> std::string { return b ? "true" : "false"; };
    scoped_feature_list->InitAndEnableFeatureWithParameters(
        features::kDnsHttpssvc,
        {
            {"DnsHttpssvcUseHttpssvc", stringify(use_httpssvc)},
            {"DnsHttpssvcUseIntegrity", stringify(use_integrity)},
            {"DnsHttpssvcEnableQueryOverInsecure", "false"},
            {"DnsHttpssvcExperimentDomains", experiment_domains},
            {"DnsHttpssvcControlDomains", control_domains},
            {"DnsHttpssvcControlDomainWildcard",
             stringify(control_domain_wildcard)},
        });
  }

  bool enabled = false;
  bool use_integrity = false;
  bool use_httpssvc = false;
  bool control_domain_wildcard = false;
  std::string experiment_domains;
  std::string control_domains;
};

std::vector<std::string> GenerateDomainList(base::StringPiece label, int n) {
  std::vector<std::string> domains;
  for (int i = 0; i < n; i++) {
    domains.push_back(base::StrCat(
        {"domain", base::NumberToString(i), ".", label, ".example"}));
  }
  return domains;
}

// Base for testing domain list parsing functions in
// net::features::dns_httpssvc_experiment.
class HttpssvcDomainParsingTest
    : public ::testing::TestWithParam<ParsingTestParamTuple> {
 public:
  void SetUp() override {
    DomainListQuirksTuple domain_quirks_experimental;
    DomainListQuirksTuple domain_quirks_control;
    HttpssvcFeatureTuple httpssvc_feature;
    std::tie(domain_quirks_experimental, domain_quirks_control,
             httpssvc_feature) = GetParam();

    expected_experiment_domains_ = GenerateDomainList(
        "experiment", std::get<0>(domain_quirks_experimental));
    expected_control_domains_ =
        GenerateDomainList("control", std::get<0>(domain_quirks_control));

    config_ = HttpssvcFeatureConfig(
        httpssvc_feature,
        FlattenDomainList(expected_experiment_domains_,
                          domain_quirks_experimental),
        FlattenDomainList(expected_control_domains_, domain_quirks_control));
    config_.Apply(&scoped_feature_list_);
  }

  const HttpssvcFeatureConfig& config() { return config_; }

 protected:
  // The expected results of parsing the comma-separated domain lists in
  // |experiment_domains| and |control_domains|, respectively.
  std::vector<std::string> expected_experiment_domains_;
  std::vector<std::string> expected_control_domains_;

 private:
  HttpssvcFeatureConfig config_;
  base::test::ScopedFeatureList scoped_feature_list_;
};

// This instantiation tests the domain list parser against various quirks,
// e.g. leading comma.
INSTANTIATE_TEST_SUITE_P(
    HttpssvcMetricsTestDomainParsing,
    HttpssvcDomainParsingTest,
    testing::Combine(
        // DomainListQuirksTuple for experimental domains. To fight back
        // combinatorial explosion of tests, this tuple is pared down more than
        // the one for control domains. This should not significantly hurt test
        // coverage because |IsExperimentDomain| and |IsControlDomain| rely on a
        // shared helper function.
        testing::Combine(testing::Values(0, 1),
                         testing::Values(false),
                         testing::Values(false)),
        // DomainListQuirksTuple for control domains.
        testing::Combine(testing::Range(0, 3),
                         testing::Bool(),
                         testing::Bool()),
        // HttpssvcFeatureTuple
        testing::Combine(
            testing::Bool() /* DnsHttpssvc feature enabled? */,
            testing::Bool() /* DnsHttpssvcUseIntegrity */,
            testing::Values(false) /* DnsHttpssvcUseHttpssvc */,
            testing::Values(false) /* DnsHttpssvcControlDomainWildcard */)));

// Base for testing the metrics collection code in |HttpssvcMetrics|.
class HttpssvcMetricsTest
    : public ::testing::TestWithParam<MetricsTestParamTuple> {
 public:
  void SetUp() override {
    HttpssvcFeatureTuple httpssvc_feature;
    std::tie(querying_experimental_, httpssvc_feature) = GetParam();
    config_ = HttpssvcFeatureConfig(httpssvc_feature, "", "");
    config_.Apply(&scoped_feature_list_);
  }

  std::string BuildMetricNamePrefix() const {
    return base::StrCat(
        {"Net.DNS.HTTPSSVC.RecordIntegrity.", doh_provider_, "."});
  }

  template <typename T>
  void ExpectSample(base::StringPiece name, base::Optional<T> sample) const {
    if (sample)
      histo().ExpectUniqueSample(name, *sample, 1);
    else
      histo().ExpectTotalCount(name, 0);
  }

  void ExpectSample(base::StringPiece name,
                    base::Optional<base::TimeDelta> sample) const {
    base::Optional<int64_t> sample_ms;
    if (sample)
      sample_ms = {sample->InMilliseconds()};
    ExpectSample<int64_t>(name, sample_ms);
  }

  void VerifyMetricsForExpectIntact(
      base::Optional<HttpssvcDnsRcode> rcode,
      base::Optional<bool> integrity,
      base::Optional<bool> record_with_error,
      base::Optional<base::TimeDelta> resolve_time_integrity,
      base::Optional<base::TimeDelta> resolve_time_non_integrity,
      base::Optional<int> resolve_time_ratio) const {
    const std::string kPrefix =
        base::StrCat({BuildMetricNamePrefix(), "ExpectIntact."});
    const std::string kMetricDnsRcode = base::StrCat({kPrefix, "DnsRcode"});
    const std::string kMetricIntegrity = base::StrCat({kPrefix, "Integrity"});
    const std::string kMetricRecordWithError =
        base::StrCat({kPrefix, "RecordWithError"});
    const std::string kMetricResolveTimeIntegrity =
        base::StrCat({kPrefix, "ResolveTimeIntegrityRecord"});
    const std::string kMetricResolveTimeNonIntegrity =
        base::StrCat({kPrefix, "ResolveTimeNonIntegrityRecord"});
    const std::string kMetricResolveTimeRatio =
        base::StrCat({kPrefix, "ResolveTimeRatio"});

    ExpectSample(kMetricDnsRcode, rcode);
    ExpectSample(kMetricIntegrity, integrity);
    ExpectSample(kMetricRecordWithError, record_with_error);
    ExpectSample(kMetricResolveTimeIntegrity, resolve_time_integrity);
    ExpectSample(kMetricResolveTimeNonIntegrity, resolve_time_non_integrity);
    ExpectSample(kMetricResolveTimeRatio, resolve_time_ratio);
  }

  void VerifyMetricsForExpectNoerror(
      base::Optional<HttpssvcDnsRcode> rcode,
      base::Optional<int> record_received,
      base::Optional<base::TimeDelta> resolve_time_integrity,
      base::Optional<base::TimeDelta> resolve_time_non_integrity,
      base::Optional<int> resolve_time_ratio) const {
    const std::string kPrefix =
        base::StrCat({BuildMetricNamePrefix(), "ExpectNoerror."});
    const std::string kMetricDnsRcode = base::StrCat({kPrefix, "DnsRcode"});
    const std::string kMetricRecordReceived =
        base::StrCat({kPrefix, "RecordReceived"});
    const std::string kMetricResolveTimeIntegrity =
        base::StrCat({kPrefix, "ResolveTimeIntegrityRecord"});
    const std::string kMetricResolveTimeNonIntegrity =
        base::StrCat({kPrefix, "ResolveTimeNonIntegrityRecord"});
    const std::string kMetricResolveTimeRatio =
        base::StrCat({kPrefix, "ResolveTimeRatio"});

    ExpectSample(kMetricDnsRcode, rcode);
    ExpectSample(kMetricRecordReceived, record_received);
    ExpectSample(kMetricResolveTimeIntegrity, resolve_time_integrity);
    ExpectSample(kMetricResolveTimeNonIntegrity, resolve_time_non_integrity);
    ExpectSample(kMetricResolveTimeRatio, resolve_time_ratio);
  }

  void VerifyMetricsForExpectIntact() {
    VerifyMetricsForExpectIntact(base::nullopt, base::nullopt, base::nullopt,
                                 base::nullopt, base::nullopt, base::nullopt);
  }

  void VerifyMetricsForExpectNoerror() {
    VerifyMetricsForExpectNoerror(base::nullopt, base::nullopt, base::nullopt,
                                  base::nullopt, base::nullopt);
  }

  const base::HistogramTester& histo() const { return histogram_; }
  const HttpssvcFeatureConfig& config() const { return config_; }

 protected:
  bool querying_experimental_;

 private:
  HttpssvcFeatureConfig config_;
  base::test::ScopedFeatureList scoped_feature_list_;
  base::HistogramTester histogram_;
  std::string doh_provider_ = "Other";
};

// This instantiation focuses on whether the correct metrics are recorded. The
// domain list parser is already tested against encoding quirks in
// |HttpssvcMetricsTestDomainParsing|, so we fix the quirks at false.
INSTANTIATE_TEST_SUITE_P(
    HttpssvcMetricsTestSimple,
    HttpssvcMetricsTest,
    testing::Combine(
        // Whether we are querying an experimental domain.
        testing::Bool(),
        // HttpssvcFeatureTuple
        testing::Combine(
            testing::Values(true) /* DnsHttpssvc feature enabled? */,
            testing::Values(true) /* DnsHttpssvcUseIntegrity */,
            testing::Values(false) /* DnsHttpssvcUseHttpssvc */,
            testing::Values(false) /* DnsHttpssvcControlDomainWildcard */)));

TEST_P(HttpssvcDomainParsingTest, ParseFeatureParamIntegrityDomains) {
  // We are not testing this feature param yet.
  CHECK(!config().use_httpssvc);

  const std::string kReservedDomain = "neither.example";
  EXPECT_FALSE(
      features::dns_httpssvc_experiment::IsExperimentDomain(kReservedDomain));
  EXPECT_EQ(features::dns_httpssvc_experiment::IsControlDomain(kReservedDomain),
            config().enabled && config().control_domain_wildcard);

  // If |config().use_integrity| is true, then we expect all domains in
  // |expected_experiment_domains_| to be experimental (same goes for
  // control domains). Otherwise, no domain should be considered experimental or
  // control.

  if (!config().enabled) {
    // When the HTTPSSVC feature is disabled, no domain should be considered
    // experimental or control.
    for (const std::string& experiment_domain : expected_experiment_domains_) {
      EXPECT_FALSE(features::dns_httpssvc_experiment::IsExperimentDomain(
          experiment_domain));
      EXPECT_FALSE(features::dns_httpssvc_experiment::IsControlDomain(
          experiment_domain));
    }
    for (const std::string& control_domain : expected_control_domains_) {
      EXPECT_FALSE(features::dns_httpssvc_experiment::IsExperimentDomain(
          control_domain));
      EXPECT_FALSE(
          features::dns_httpssvc_experiment::IsControlDomain(control_domain));
    }
    return;
  }

  if (config().use_integrity) {
    // When the HTTPSSVC feature is disabled, no domain should be considered
    // experimental or control.
    for (const std::string& experiment_domain : expected_experiment_domains_) {
      EXPECT_TRUE(features::dns_httpssvc_experiment::IsExperimentDomain(
          experiment_domain));
      EXPECT_FALSE(features::dns_httpssvc_experiment::IsControlDomain(
          experiment_domain));
    }
    for (const std::string& control_domain : expected_control_domains_) {
      EXPECT_FALSE(features::dns_httpssvc_experiment::IsExperimentDomain(
          control_domain));
      EXPECT_TRUE(
          features::dns_httpssvc_experiment::IsControlDomain(control_domain));
    }
    return;
  }
}

// Only record metrics for a non-integrity query.
TEST_P(HttpssvcMetricsTest, AddressAndIntegrityMissing) {
  if (!config().enabled || !config().use_integrity) {
    VerifyMetricsForExpectIntact();
    VerifyMetricsForExpectNoerror();
    return;
  }
  const base::TimeDelta kResolveTime = base::TimeDelta::FromMilliseconds(10);
  base::Optional<HttpssvcMetrics> metrics(querying_experimental_);
  metrics->SaveForNonIntegrity(base::nullopt, kResolveTime,
                               HttpssvcDnsRcode::kNoError);
  metrics.reset();  // Record the metrics to UMA.

  VerifyMetricsForExpectIntact();
  VerifyMetricsForExpectNoerror();
}

TEST_P(HttpssvcMetricsTest, AddressAndIntegrityIntact) {
  if (!config().enabled || !config().use_integrity) {
    VerifyMetricsForExpectIntact();
    VerifyMetricsForExpectNoerror();
    return;
  }
  const base::TimeDelta kResolveTime = base::TimeDelta::FromMilliseconds(10);
  const base::TimeDelta kResolveTimeIntegrity =
      base::TimeDelta::FromMilliseconds(15);
  base::Optional<HttpssvcMetrics> metrics(querying_experimental_);
  metrics->SaveForIntegrity(base::nullopt, HttpssvcDnsRcode::kNoError, {true},
                            kResolveTimeIntegrity);
  metrics->SaveForNonIntegrity(base::nullopt, kResolveTime,
                               HttpssvcDnsRcode::kNoError);
  metrics.reset();  // Record the metrics to UMA.

  if (querying_experimental_) {
    VerifyMetricsForExpectIntact(
        base::nullopt /* rcode */, {true} /* integrity */,
        base::nullopt /* record_with_error */,
        {kResolveTimeIntegrity} /* resolve_time_integrity */,
        {kResolveTime} /* resolve_time_non_integrity */,
        {15} /* resolve_time_ratio */);

    VerifyMetricsForExpectNoerror();
    return;
  }

  VerifyMetricsForExpectIntact();

  VerifyMetricsForExpectNoerror(
      {HttpssvcDnsRcode::kNoError} /* rcode */, {1} /* record_received */,
      {kResolveTimeIntegrity} /* resolve_time_integrity */,
      {kResolveTime} /* resolve_time_non_integrity */,
      {15} /* resolve_time_ratio */);
}

// This test simulates an INTEGRITY response that includes no INTEGRITY records,
// but does have an error value for the RCODE.
TEST_P(HttpssvcMetricsTest, AddressAndIntegrityMissingWithRcode) {
  if (!config().enabled || !config().use_integrity) {
    VerifyMetricsForExpectIntact();
    VerifyMetricsForExpectNoerror();
    return;
  }
  const base::TimeDelta kResolveTime = base::TimeDelta::FromMilliseconds(10);
  const base::TimeDelta kResolveTimeIntegrity =
      base::TimeDelta::FromMilliseconds(15);

  base::Optional<HttpssvcMetrics> metrics(querying_experimental_);
  metrics->SaveForIntegrity(base::nullopt, HttpssvcDnsRcode::kNxDomain, {},
                            kResolveTimeIntegrity);
  metrics->SaveForNonIntegrity(base::nullopt, kResolveTime,
                               HttpssvcDnsRcode::kNoError);
  metrics.reset();  // Record the metrics to UMA.

  if (querying_experimental_) {
    VerifyMetricsForExpectIntact(
        {HttpssvcDnsRcode::kNxDomain} /* rcode */,
        base::nullopt /* integrity */, base::nullopt /* record_with_error */,
        {kResolveTimeIntegrity} /* resolve_time_integrity */,
        {kResolveTime} /* resolve_time_non_integrity */,
        {15} /* resolve_time_ratio */);

    VerifyMetricsForExpectNoerror();
    return;
  }

  VerifyMetricsForExpectIntact();

  VerifyMetricsForExpectNoerror(
      {HttpssvcDnsRcode::kNxDomain} /* rcode */,
      base::nullopt /* record_received */,
      {kResolveTimeIntegrity} /* resolve_time_integrity */,
      {kResolveTime} /* resolve_time_non_integrity */,
      {15} /* resolve_time_ratio */);
}

// This test simulates an INTEGRITY response that includes an intact INTEGRITY
// record, but also has an error RCODE.
TEST_P(HttpssvcMetricsTest, AddressAndIntegrityIntactWithRcode) {
  if (!config().enabled || !config().use_integrity) {
    VerifyMetricsForExpectIntact();
    VerifyMetricsForExpectNoerror();
    return;
  }

  const base::TimeDelta kResolveTime = base::TimeDelta::FromMilliseconds(10);
  const base::TimeDelta kResolveTimeIntegrity =
      base::TimeDelta::FromMilliseconds(15);

  base::Optional<HttpssvcMetrics> metrics(querying_experimental_);
  metrics->SaveForIntegrity(base::nullopt, HttpssvcDnsRcode::kNxDomain, {true},
                            kResolveTimeIntegrity);
  metrics->SaveForNonIntegrity(base::nullopt, kResolveTime,
                               HttpssvcDnsRcode::kNoError);
  metrics.reset();  // Record the metrics to UMA.

  if (querying_experimental_) {
    VerifyMetricsForExpectIntact(
        // "DnsRcode" metric is omitted because we received an INTEGRITY record.
        base::nullopt /* rcode */,
        // "Integrity" metric is omitted because the RCODE is not NOERROR.
        base::nullopt /* integrity */, {true} /* record_with_error */,
        {kResolveTimeIntegrity} /* resolve_time_integrity */,
        {kResolveTime} /* resolve_time_non_integrity */,
        {15} /* resolve_time_ratio */);

    VerifyMetricsForExpectNoerror();
    return;
  }

  VerifyMetricsForExpectIntact();

  VerifyMetricsForExpectNoerror(
      {HttpssvcDnsRcode::kNxDomain} /* rcode */, {true} /* record_received */,
      {kResolveTimeIntegrity} /* resolve_time_integrity */,
      {kResolveTime} /* resolve_time_non_integrity */,
      {15} /* resolve_time_ratio */);
}

// This test simulates an INTEGRITY response that includes a mangled INTEGRITY
// record *and* has an error RCODE.
TEST_P(HttpssvcMetricsTest, AddressAndIntegrityMangledWithRcode) {
  if (!config().enabled || !config().use_integrity) {
    VerifyMetricsForExpectIntact();
    VerifyMetricsForExpectNoerror();
    return;
  }
  const base::TimeDelta kResolveTime = base::TimeDelta::FromMilliseconds(10);
  const base::TimeDelta kResolveTimeIntegrity =
      base::TimeDelta::FromMilliseconds(15);
  base::Optional<HttpssvcMetrics> metrics(querying_experimental_);
  metrics->SaveForIntegrity(base::nullopt, HttpssvcDnsRcode::kNxDomain, {false},
                            kResolveTimeIntegrity);
  metrics->SaveForNonIntegrity(base::nullopt, kResolveTime,
                               HttpssvcDnsRcode::kNoError);
  metrics.reset();  // Record the metrics to UMA.

  if (querying_experimental_) {
    VerifyMetricsForExpectIntact(
        // "DnsRcode" metric is omitted because we received an INTEGRITY record.
        base::nullopt /* rcode */,
        // "Integrity" metric is omitted because the RCODE is not NOERROR.
        base::nullopt /* integrity */, {true} /* record_with_error */,
        {kResolveTimeIntegrity} /* resolve_time_integrity */,
        {kResolveTime} /* resolve_time_non_integrity */,
        {15} /* resolve_time_ratio */);

    VerifyMetricsForExpectNoerror();
    return;
  }

  VerifyMetricsForExpectIntact();

  VerifyMetricsForExpectNoerror(
      {HttpssvcDnsRcode::kNxDomain} /* rcode */, {true} /* record_received */,
      {kResolveTimeIntegrity} /* resolve_time_integrity */,
      {kResolveTime} /* resolve_time_non_integrity */,
      {15} /* resolve_time_ratio */);
}

// This test simulates successful address queries and an INTEGRITY query that
// timed out.
TEST_P(HttpssvcMetricsTest, AddressAndIntegrityTimedOut) {
  if (!config().enabled || !config().use_integrity) {
    VerifyMetricsForExpectIntact();
    VerifyMetricsForExpectNoerror();
    return;
  }
  const base::TimeDelta kResolveTime = base::TimeDelta::FromMilliseconds(10);
  const base::TimeDelta kResolveTimeIntegrity =
      base::TimeDelta::FromMilliseconds(15);
  base::Optional<HttpssvcMetrics> metrics(querying_experimental_);
  metrics->SaveForIntegrity(base::nullopt, HttpssvcDnsRcode::kTimedOut, {},
                            kResolveTimeIntegrity);
  metrics->SaveForNonIntegrity(base::nullopt, kResolveTime,
                               HttpssvcDnsRcode::kNoError);
  metrics.reset();  // Record the metrics to UMA.

  if (querying_experimental_) {
    VerifyMetricsForExpectIntact(
        {HttpssvcDnsRcode::kTimedOut} /* rcode */,
        // "Integrity" metric is omitted because the RCODE is not NOERROR.
        base::nullopt /* integrity */, base::nullopt /* record_with_error */,
        {kResolveTimeIntegrity} /* resolve_time_integrity */,
        {kResolveTime} /* resolve_time_non_integrity */,
        {15} /* resolve_time_ratio */);

    VerifyMetricsForExpectNoerror();
    return;
  }

  VerifyMetricsForExpectIntact();

  VerifyMetricsForExpectNoerror(
      {HttpssvcDnsRcode::kTimedOut} /* rcode */,
      base::nullopt /* record_received */,
      {kResolveTimeIntegrity} /* resolve_time_integrity */,
      {kResolveTime} /* resolve_time_non_integrity */,
      {15} /* resolve_time_ratio */);
}

}  // namespace net
