// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_WEBUI_SETTINGS_CHROMEOS_SEARCH_SEARCH_HANDLER_H_
#define CHROME_BROWSER_UI_WEBUI_SETTINGS_CHROMEOS_SEARCH_SEARCH_HANDLER_H_

#include <vector>

#include "base/gtest_prod_util.h"
#include "base/optional.h"
#include "chrome/browser/chromeos/local_search_service/index.h"
#include "chrome/browser/ui/webui/settings/chromeos/search/search.mojom.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/receiver_set.h"
#include "mojo/public/cpp/bindings/remote.h"

namespace local_search_service {
class LocalSearchService;
}  // namespace local_search_service

namespace chromeos {
namespace settings {

class Hierarchy;
class OsSettingsSections;
struct SearchConcept;
class SearchTagRegistry;

// Handles search queries for Chrome OS settings. Search() is expected to be
// invoked by the settings UI as well as the the Launcher search UI. Search
// results are obtained by matching the provided query against search tags
// indexed in the LocalSearchService and cross-referencing results with
// SearchTagRegistry.
//
// Searches which do not provide any matches result in an empty results array.
class SearchHandler : public mojom::SearchHandler {
 public:
  SearchHandler(SearchTagRegistry* search_tag_registry,
                OsSettingsSections* sections,
                Hierarchy* hierarchy,
                local_search_service::LocalSearchService* local_search_service);
  ~SearchHandler() override;

  SearchHandler(const SearchHandler& other) = delete;
  SearchHandler& operator=(const SearchHandler& other) = delete;

  void BindInterface(
      mojo::PendingReceiver<mojom::SearchHandler> pending_receiver);

  // Synchronous search implementation (for in-process clients).
  std::vector<mojom::SearchResultPtr> Search(
      const base::string16& query,
      uint32_t max_num_results,
      mojom::ParentResultBehavior parent_result_behavior);

  // mojom::SearchHandler:
  void Search(const base::string16& query,
              uint32_t max_num_results,
              mojom::ParentResultBehavior parent_result_behavior,
              SearchCallback callback) override;

 private:
  FRIEND_TEST_ALL_PREFIXES(SearchHandlerTest, CompareSearchResults);

  std::vector<mojom::SearchResultPtr> GenerateSearchResultsArray(
      const std::vector<local_search_service::Result>&
          local_search_service_results,
      uint32_t max_num_results,
      mojom::ParentResultBehavior parent_result_behavior) const;

  void AddParentResults(
      uint32_t max_num_results,
      std::vector<mojom::SearchResultPtr>* search_results) const;

  std::vector<mojom::SearchResultPtr>::iterator AddSectionResultIfPossible(
      const std::vector<mojom::SearchResultPtr>::iterator& position,
      const mojom::SearchResultPtr& child_result,
      mojom::Section section,
      std::vector<mojom::SearchResultPtr>* results) const;

  std::vector<mojom::SearchResultPtr>::iterator AddSubpageResultIfPossible(
      const std::vector<mojom::SearchResultPtr>::iterator& position,
      mojom::Subpage subpage,
      double relevance_score,
      std::vector<mojom::SearchResultPtr>* results) const;

  mojom::SearchResultPtr ResultToSearchResult(
      const local_search_service::Result& result) const;
  std::string GetModifiedUrl(const SearchConcept& concept,
                             mojom::Section section) const;

  // Returns true if |first| should be ranked before |second|.
  static bool CompareSearchResults(const mojom::SearchResultPtr& first,
                                   const mojom::SearchResultPtr& second);

  SearchTagRegistry* search_tag_registry_;
  OsSettingsSections* sections_;
  Hierarchy* hierarchy_;
  local_search_service::Index* index_;

  // Note: Expected to have multiple clients, so a ReceiverSet is used.
  mojo::ReceiverSet<mojom::SearchHandler> receivers_;
};

}  // namespace settings
}  // namespace chromeos

#endif  // CHROME_BROWSER_UI_WEBUI_SETTINGS_CHROMEOS_SEARCH_SEARCH_HANDLER_H_
