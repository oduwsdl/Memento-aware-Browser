// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/chromeos/local_search_service/linear_map_search.h"

#include <utility>

#include "base/optional.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include "chrome/common/string_matching/fuzzy_tokenized_string_match.h"
#include "chrome/common/string_matching/tokenized_string.h"

namespace local_search_service {

namespace {

using Positions = std::vector<local_search_service::Position>;
using TokenizedStringWithId =
    std::pair<std::string, std::unique_ptr<TokenizedString>>;

void TokenizeSearchTags(const std::vector<Content>& contents,
                        std::vector<TokenizedStringWithId>* tokenized) {
  DCHECK(tokenized);

  for (const auto& content : contents) {
    tokenized->push_back(std::make_pair(
        content.id, std::make_unique<TokenizedString>(content.content)));
  }
}

// Returns whether a given item with |search_tags| is relevant to |query| using
// fuzzy string matching.
bool IsItemRelevant(const TokenizedString& query,
                    const std::vector<TokenizedStringWithId>& search_tags,
                    double relevance_threshold,
                    bool use_prefix_only,
                    bool use_edit_distance,
                    double partial_match_penalty_rate,
                    double* relevance_score,
                    Positions* positions) {
  DCHECK(relevance_score);
  DCHECK(positions);

  if (search_tags.empty())
    return false;

  for (const auto& tag : search_tags) {
    FuzzyTokenizedStringMatch match;
    if (match.IsRelevant(query, *(tag.second), relevance_threshold,
                         use_prefix_only, true /* use_weighted_ratio */,
                         use_edit_distance, partial_match_penalty_rate, 0.1)) {
      *relevance_score = match.relevance();
      Position position;
      position.content_id = tag.first;
      positions->push_back(position);
      return true;
    }
  }
  return false;
}

// Compares Results by |score|.
bool CompareResults(const local_search_service::Result& r1,
                    const local_search_service::Result& r2) {
  return r1.score > r2.score;
}

}  // namespace

LinearMapSearch::LinearMapSearch() = default;

LinearMapSearch::~LinearMapSearch() = default;

uint64_t LinearMapSearch::GetSize() {
  return data_.size();
}

void LinearMapSearch::AddOrUpdate(
    const std::vector<local_search_service::Data>& data) {
  for (const auto& item : data) {
    const auto& id = item.id;
    DCHECK(!id.empty());

    // If a key already exists, it will overwrite earlier data.
    data_[id] = std::vector<TokenizedStringWithId>();
    TokenizeSearchTags(item.contents, &data_[id]);
  }
}

uint32_t LinearMapSearch::Delete(const std::vector<std::string>& ids) {
  uint32_t num_deleted = 0u;
  for (const auto& id : ids) {
    DCHECK(!id.empty());

    const auto& it = data_.find(id);
    if (it != data_.end()) {
      // If id doesn't exist, just ignore it.
      data_.erase(id);
      ++num_deleted;
    }
  }
  return num_deleted;
}

ResponseStatus LinearMapSearch::Find(const base::string16& query,
                                     uint32_t max_results,
                                     std::vector<Result>* results) {
  DCHECK(results);
  results->clear();
  if (query.empty()) {
    return ResponseStatus::kEmptyQuery;
  }
  if (data_.empty()) {
    return ResponseStatus::kEmptyIndex;
  }

  *results = GetSearchResults(query, max_results);
  return ResponseStatus::kSuccess;
}

void LinearMapSearch::SetSearchParams(const SearchParams& search_params) {
  search_params_ = search_params;
}

SearchParams LinearMapSearch::GetSearchParams() {
  return search_params_;
}

std::vector<Result> LinearMapSearch::GetSearchResults(
    const base::string16& query,
    uint32_t max_results) const {
  std::vector<Result> results;
  const TokenizedString tokenized_query(query);

  for (const auto& item : data_) {
    double relevance_score = 0.0;
    Positions positions;
    if (IsItemRelevant(
            tokenized_query, item.second, search_params_.relevance_threshold,
            search_params_.use_prefix_only, search_params_.use_edit_distance,
            search_params_.partial_match_penalty_rate, &relevance_score,
            &positions)) {
      Result result;
      result.id = item.first;
      result.score = relevance_score;
      result.positions = positions;
      results.push_back(result);
    }
  }

  std::sort(results.begin(), results.end(), CompareResults);
  if (results.size() > max_results && max_results > 0u) {
    results.resize(max_results);
  }
  return results;
}

}  // namespace local_search_service
