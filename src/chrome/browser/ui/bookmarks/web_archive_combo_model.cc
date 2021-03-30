// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/bookmarks/web_archive_combo_model.h"

#include <stddef.h>

#include <ctime>
#include <map>
#include <string>

#include "base/strings/utf_string_conversions.h"
#include "base/metrics/user_metrics.h"
#include "chrome/grit/generated_resources.h"
#include "components/bookmarks/browser/bookmark_model.h"
#include "components/bookmarks/browser/bookmark_utils.h"
#include "ui/base/l10n/l10n_util.h"
#include "ui/base/models/combobox_model_observer.h"

#if defined(OS_WIN)
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

using bookmarks::BookmarkModel;
using bookmarks::BookmarkNode;


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

  // And put the bookmark bar and other nodes at the end of the list.
  //items_.push_back(Item(model->bookmark_bar_node(), Item::TYPE_NODE));
  items_.push_back(Item(model->no_archive_node(), Item::TYPE_NODE));
  items_.push_back(Item(model->archive_today_node(), Item::TYPE_NODE));
  items_.push_back(Item(model->internet_archive_node(), Item::TYPE_NODE));
  items_.push_back(Item(model->megalodon_node(), Item::TYPE_NODE));

  DVLOG(0) << "WebArchive node_parent_index_ ---- " << node_parent_index_;
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

std::string get_current_dir() {
   char buff[FILENAME_MAX]; //create string buffer to hold path
   (void)GetCurrentDir( buff, FILENAME_MAX );
   std::string current_working_dir(buff);
   return current_working_dir;
}

// The function we want to execute on the new thread.
void WebArchiveComboModel::UpdateArchiveNode(const BookmarkNode* archived_node, 
                       const BookmarkNode* node)
{

}


void WebArchiveComboModel::MaybeChangeParent(
    const BookmarkNode* node,
    int selected_index) {
  if (items_[selected_index].type != Item::TYPE_NODE)
    return;

  /*std::time_t ct = std::time(0);
  char* cc = std::put_time(std::gmtime(&ct), "%c %Z");*/

  time_t curr_time;
  curr_time = time(NULL);

  tm *tm_gmt = gmtime(&curr_time);

  std::string year = std::to_string(tm_gmt->tm_year + 1900);
  std::string month = std::to_string(tm_gmt->tm_mon + 1);
  std::string day = std::to_string(tm_gmt->tm_mday);

  std::string hour = std::to_string(tm_gmt->tm_hour);
  std::string minutes = std::to_string(tm_gmt->tm_min);
  std::string seconds = std::to_string(tm_gmt->tm_sec);

  if (month.length() == 1) { month = "0" + month; }
  if (day.length() == 1) { day = "0" + day; }
  if (hour.length() == 1) { hour = "0" + hour; }
  if (minutes.length() == 1) { minutes = "0" + minutes; }
  if (seconds.length() == 1) { seconds = "0" + seconds; }

  DVLOG(0) << year;
  DVLOG(0) << month;
  DVLOG(0) << day;
  DVLOG(0) << hour;
  DVLOG(0) << minutes;
  DVLOG(0) << seconds;

  std::string datestring = year + month + day + hour + minutes + seconds;

  if (items_[selected_index].node->GetTitle() != base::UTF8ToUTF16(std::string("None"))) {
    //const BookmarkNode* new_parent = GetNodeAt(selected_index);
    std::string archive;
    std::string domain;
    std::string archive_node_url;
    if (items_[selected_index].node->GetTitle() == base::UTF8ToUTF16(std::string("Internet Archive"))) {
      archive = "IA";
      domain = "https://web.archive.org/web/";
      archive_node_url = domain + datestring + std::string("\\" + node->url().spec());
    }
    else if (items_[selected_index].node->GetTitle() == base::UTF8ToUTF16(std::string("Archive.today"))) {
      archive = "Archive.Today";
      domain = "https://archive.is/";
      archive_node_url = domain + datestring + std::string("\\" + node->url().spec());
    }
    else if (items_[selected_index].node->GetTitle() == base::UTF8ToUTF16(std::string("Megalodon"))) {
      archive = "Megalodon";
      archive_node_url = node->url().spec();
    }

    #if defined(OS_WIN)
    std::string location = get_current_dir();
    std::string command = ("Start-Process -NoNewWindow python3 " + location + "\\archive.py " + archive + " " + node->url().spec());
    #else
    std::string location = get_current_dir();
    std::string command = ("python3 " + location + "/archive.py " + archive + " \'" + node->url().spec() + "\' " + "&");
    #endif

    if (node->parent()->GetTitle() != base::UTF8ToUTF16(node->url().spec())) {
      const BookmarkNode* new_parent = bookmark_model_->AddFolder(node->parent(), 
                                                                node->parent()->children().size(), 
                                                                base::UTF8ToUTF16(node->url().spec()));
      bookmark_model_->Move(node, new_parent, new_parent->children().size());
    }

    DVLOG(0) << command;
    (void)system(command.c_str());
    
    const BookmarkNode* new_parent = node->parent();

    GURL url_to_archive = GURL(base::UTF8ToUTF16(archive_node_url));

    bookmark_model_->AddURL(new_parent, new_parent->children().size(), base::UTF8ToUTF16(std::string("Archiving " + node->url().spec())), url_to_archive);
  }
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
