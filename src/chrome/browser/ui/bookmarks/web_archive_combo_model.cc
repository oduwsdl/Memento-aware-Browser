// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/bookmarks/web_archive_combo_model.h"

#include <stddef.h>

#include "base/metrics/user_metrics.h"
#include "chrome/grit/generated_resources.h"
#include "components/bookmarks/browser/bookmark_model.h"
#include "components/bookmarks/browser/bookmark_utils.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/models/combobox_model_observer.h"

using bookmarks::BookmarkModel;
using bookmarks::BookmarkNode;

namespace {

// Max number of most recently used folders.
const size_t kMaxMRUFolders = 5;

}  // namespace

struct WebArchiveComboModel::Item {
  enum Type {
    TYPE_NODE,
    TYPE_SEPARATOR,
    TYPE_CHOOSE_ANOTHER_FOLDER
  };

  Item(const BookmarkNode* node, Type type);
  ~Item();

  bool operator==(const Item& item) const;

  const BookmarkNode* node;
  Type type;
};

WebArchiveComboModel::Item::Item(const BookmarkNode* node,
                                          Type type)
    : node(node),
      type(type) {
}

WebArchiveComboModel::Item::~Item() {}

bool WebArchiveComboModel::Item::operator==(const Item& item) const {
  return item.node == node && item.type == type;
}

WebArchiveComboModel::WebArchiveComboModel(
    BookmarkModel* model,
    const BookmarkNode* node)
    : bookmark_model_(model),
      node_parent_index_(0) {
  bookmark_model_->AddObserver(this);

  DVLOG(0) << "-------------------------------------";
  DVLOG(0) << "WebArchiveComboModel";
  DVLOG(0) << "Getting most recently modified folders.";
  DVLOG(0) << "-------------------------------------";

  // Use + 2 to account for bookmark bar and other node.
  std::vector<const BookmarkNode*> nodes =
      bookmarks::GetMostRecentlyModifiedUserFolders(model, kMaxMRUFolders + 2);

  //for (size_t i = 0; i < nodes.size(); ++i)
    //items_.push_back(Item(nodes[i], Item::TYPE_NODE));

  // We special case the placement of these, so remove them from the list, then
  // fix up the order.
  /*RemoveNode(model->bookmark_bar_node());
  RemoveNode(model->archive_today_node());
  RemoveNode(model->mobile_node());
  RemoveNode(model->other_node());
  RemoveNode(node->parent());*/

  // Make the parent the first item, unless it's a permanent node, which is
  // added below.
  //if (!model->is_permanent_node(node->parent()))
    //items_.insert(items_.begin(), Item(node->parent(), Item::TYPE_NODE));

  // Make sure we only have kMaxMRUFolders in the first chunk.
  //if (items_.size() > kMaxMRUFolders)
    //items_.erase(items_.begin() + kMaxMRUFolders, items_.end());

  // And put the bookmark bar and other nodes at the end of the list.
  //items_.push_back(Item(model->bookmark_bar_node(), Item::TYPE_NODE));
  items_.push_back(Item(model->no_archive_node(), Item::TYPE_NODE));
  items_.push_back(Item(model->archive_today_node(), Item::TYPE_NODE));

  auto it = std::find(items_.begin(), items_.end(),
                      Item(node->parent(), Item::TYPE_NODE));
  node_parent_index_ = static_cast<int>(it - items_.begin());
}

WebArchiveComboModel::~WebArchiveComboModel() {
  bookmark_model_->RemoveObserver(this);
}

int WebArchiveComboModel::GetItemCount() const {
  return static_cast<int>(items_.size());
}

base::string16 WebArchiveComboModel::GetItemAt(int index) const {
  switch (items_[index].type) {
    case Item::TYPE_NODE:
      return items_[index].node->GetTitle();
    case Item::TYPE_SEPARATOR:
      // This function should not be called for separators.
      NOTREACHED();
      return base::string16();
    case Item::TYPE_CHOOSE_ANOTHER_FOLDER:
      return l10n_util::GetStringUTF16(
          IDS_BOOKMARK_BUBBLE_CHOOSER_ANOTHER_FOLDER);
  }
  NOTREACHED();
  return base::string16();
}

bool WebArchiveComboModel::IsItemSeparatorAt(int index) const {
  return items_[index].type == Item::TYPE_SEPARATOR;
}

int WebArchiveComboModel::GetDefaultIndex() const {
  return 0;
}

void WebArchiveComboModel::AddObserver(
    ui::ComboboxModelObserver* observer) {
  observers_.AddObserver(observer);
}

void WebArchiveComboModel::RemoveObserver(
    ui::ComboboxModelObserver* observer) {
  observers_.RemoveObserver(observer);
}

void WebArchiveComboModel::BookmarkModelLoaded(BookmarkModel* model,
                                                        bool ids_reassigned) {}

void WebArchiveComboModel::BookmarkModelBeingDeleted(
    BookmarkModel* model) {
}

void WebArchiveComboModel::BookmarkNodeMoved(
    BookmarkModel* model,
    const BookmarkNode* old_parent,
    size_t old_index,
    const BookmarkNode* new_parent,
    size_t new_index) {}

void WebArchiveComboModel::BookmarkNodeAdded(
    BookmarkModel* model,
    const BookmarkNode* parent,
    size_t index) {}

void WebArchiveComboModel::OnWillRemoveBookmarks(
    BookmarkModel* model,
    const BookmarkNode* parent,
    size_t old_index,
    const BookmarkNode* node) {
  // Changing is rare enough that we don't attempt to readjust the contents.
  // Update |items_| so we aren't left pointing to a deleted node.
  bool changed = false;
  for (auto i = items_.begin(); i != items_.end();) {
    if (i->type == Item::TYPE_NODE && i->node->HasAncestor(node)) {
      i = items_.erase(i);
      changed = true;
    } else {
      ++i;
    }
  }
  if (changed) {
    for (ui::ComboboxModelObserver& observer : observers_)
      observer.OnComboboxModelChanged(this);
  }
}

void WebArchiveComboModel::BookmarkNodeRemoved(
    BookmarkModel* model,
    const BookmarkNode* parent,
    size_t old_index,
    const BookmarkNode* node,
    const std::set<GURL>& removed_urls) {}

void WebArchiveComboModel::BookmarkNodeChanged(
    BookmarkModel* model,
    const BookmarkNode* node) {
}

void WebArchiveComboModel::BookmarkNodeFaviconChanged(
    BookmarkModel* model,
    const BookmarkNode* node) {
}

void WebArchiveComboModel::BookmarkNodeChildrenReordered(
      BookmarkModel* model,
      const BookmarkNode* node) {
}

void WebArchiveComboModel::BookmarkAllUserNodesRemoved(
    BookmarkModel* model,
    const std::set<GURL>& removed_urls) {
  // Changing is rare enough that we don't attempt to readjust the contents.
  // Update |items_| so we aren't left pointing to a deleted node.
  bool changed = false;
  for (auto i = items_.begin(); i != items_.end();) {
    if (i->type == Item::TYPE_NODE &&
        !bookmark_model_->is_permanent_node(i->node)) {
      i = items_.erase(i);
      changed = true;
    } else {
      ++i;
    }
  }
  if (changed) {
    for (ui::ComboboxModelObserver& observer : observers_)
      observer.OnComboboxModelChanged(this);
  }
}

void WebArchiveComboModel::MaybeChangeParent(
    const BookmarkNode* node,
    int selected_index) {
  if (items_[selected_index].type != Item::TYPE_NODE)
    return;

  DVLOG(0) << "-------------------------------";
  DVLOG(0) << "Title of selected archive: " << items_[selected_index].node->GetTitle();
  DVLOG(0) << "-------------------------------";
  system("python3 ~/MemAwareBrowser/src/chrome/browser/ui/bookmarks/test.py");


  /*const BookmarkNode* new_parent = GetNodeAt(selected_index);
  if (new_parent != node->parent()) {
    base::RecordAction(base::UserMetricsAction("BookmarkBubble_ChangeParent"));
    bookmark_model_->Move(node, new_parent, new_parent->children().size());
  }*/
}

const BookmarkNode* WebArchiveComboModel::GetNodeAt(int index) {
  if (index < 0 || index >= static_cast<int>(items_.size()))
    return NULL;
  return items_[index].node;
}

void WebArchiveComboModel::RemoveNode(const BookmarkNode* node) {
  auto it =
      std::find(items_.begin(), items_.end(), Item(node, Item::TYPE_NODE));
  if (it != items_.end())
    items_.erase(it);
}
